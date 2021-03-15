#include "tempcalibrt.h"
#include <QDebug>
#include "../config.h"
#include <math.h>

using namespace  std;

TempCalibrt::TempCalibrt(QObject *parent):QObject(parent)
{
}

TempCalibrt::~TempCalibrt(){

}

void TempCalibrt::init(){

}

void  TempCalibrt::getTempValue(float& temp,bool &flag,int timeout){
    if(!port->isOpen()){
        qCritical() << "port is not open!";
        flag = false;
        return;
    }
    int m =GetTempTimes;
    int maxSize = GetTempTimes;
    int tempAll = 0;
    qint64 startTime = QDateTime::currentMSecsSinceEpoch();
    char  buf[TemperatureValueSize];
    memset(buf,0,TemperatureValueSize);

    QByteArray arr;
    arr.resize(2);
    port->flushReadCache();
    while(m>0){
        arr[0] = 0xA5;
        arr[1] = 0xAD;
       bool isOk = port->sendInfo(arr.data(),2);
       if(!isOk){
           flag = false;
           return;
        }

        int remainsize = TemperatureValueSize ;

        if(HDTimer::getCurrentTimeMisc() - startTime >timeout){
             flag = false;
            return ;
        }

        while(remainsize >0 || HDTimer::getCurrentTimeMisc() - startTime <timeout){
            int size = port->bytesAvailable();
            if (size ==0){
                qint64 startTi = QDateTime::currentMSecsSinceEpoch();
               if(!port->bytesAvailable()){
                   bool isOk =   port->waitForReadyRead(timeout -startTi + startTime);
                   qDebug() << ":" << QDateTime::currentMSecsSinceEpoch() - startTi;
               }
            }

            QByteArray  a_tmp = port->readAll();
            int len = a_tmp.length();
            memcpy(buf+TemperatureValueSize- remainsize,a_tmp.data(),len);
            if(a_tmp.contains(0x0D)){
                buf[TemperatureValueSize- remainsize+len] = '\0';
                goto end;
            }
            remainsize -= len;
        }
        end:

        string str(buf);
        int32_t index = str.find("TEMP");
        if(index == -1){
            continue;
        }
        m--;
       int  temValue = atoi(str.substr(index+6).c_str());
        tempAll += temValue;
    }
    temp = (1.0* tempAll) / (maxSize* 100);
     flag = true;
    return ;

}


void  TempCalibrt::parseDataHeader(bool &flag,int timeout){
    int pos = 0;
    qint64 startTime = HDTimer::getCurrentTimeMisc();
    qDebug() << "";
    QByteArray ar;
    ar.resize(10);
    bool isOk = false;
    while(HDTimer::getCurrentTimeMisc() - startTime < timeout || timeout == -1){ //getHDTimer() - startTime >DefaultTimeout
        qDebug() << "";
        int remain = PackageDataHeaderLen -pos;
        if(timeout == -1){
            isOk = port->waitForData(remain,timeout);
        }else{
            isOk = port->waitForData(remain,timeout - HDTimer::getCurrentTimeMisc()+startTime);
        }

        if(!isOk){
            flag = false;
            return;
        }
        QByteArray tmp = port->read(qint64(remain));

        for(int i = 0;i <tmp.length();i++){
            switch (pos) {
            case 0:
                if(uint8_t(tmp[i]) != 0xaa){
                    continue;
                }
                pos++;
                break;
            case 1:
                if(uint8_t(tmp[i]) != 0x55){
                    pos = 0;
                    continue;
                }
                pos++;
                CheckSumCal = 0X55AA;
                break;
            case 2:
                SampleNumlAndCTCal = uint8_t(tmp[i]);
                pos++;
                break;
            case 3:
                if(uint8_t(tmp[i]) != 0x28){
                    pos = 0;
                    continue;
                }
                pos++;
                SampleNumlAndCTCal += uint8_t(tmp[i]) * 0x100;
                break;
            case 4:
                firstAngle = uint8_t(tmp[i]);
                pos++;
                break;
            case 5:
                firstAngle += (uint8_t(tmp[i])) * 0x100;
                CheckSumCal ^= firstAngle;
                pos++;
                break;
            case 6:
                lastAngle = uint8_t(tmp[i]);
                pos++;
                break;
            case 7:
                lastAngle += (uint8_t(tmp[i])) * 0x100;
                CheckSumCal ^= lastAngle;
                pos++;
                break;
            case 8:
                CheckSum = uint8_t(tmp[i]);
                pos++;
                break;
            case 9:
                CheckSum += uint8_t(tmp[i]) * 0x100;
                pos++;
                break;
            default:
                continue;
            }
            ar[pos-1] = tmp[i];

        }
        if (pos == 10){
            flag = true;
           return;
        }
    }
    flag = false;
    return;
}

void TempCalibrt::startDistanceScan(float& distance,float& standDevit){
    QByteArray  arr;
    arr.resize(2);
    arr[0] = 0xA5;
    arr[1] = 0x60;
    const int cstWaitSize = EveryPackagePointSize  *4 ;
    int waitSize =  cstWaitSize;
    char scanData[cstWaitSize+1];
    vector<int32_t> vec_distance;
    vec_distance.resize(MaxTempPointSize);

    bool isOk = true;
    sendInfo(isOk,arr.data(),2);
    if(!isOk){
        return;
    }
    start:
    vec_distance.clear();
    int m = MaxTempPointSize / EveryPackagePointSize;
    while(m>0){
        bool ans = false;
        parseDataHeader(ans);
          if (!ans){
              stopScanDistance();
              return;
          }

          ans = port->waitForData(waitSize, -1); //5s,
          if (ans == false){
              stopScanDistance();
              return;
          }

          qint64 Maxlen = port->read(scanData,waitSize);
          if(Maxlen != waitSize){
              continue;
          }
          ans = caculateCheckSum(scanData,waitSize);
          if (!ans){
              continue;
          }
          QByteArray arr;
          int32_t sumA= 0;
          for(int i=0;i<waitSize;i=i+4){
              arr.append(scanData[i+2]);
              arr.append(scanData[i+3]);
              vec_distance.push_back((uint8_t)scanData[i+2] *1 + 16*16*scanData[i+3]);
              sumA += scanData[i+2] *1 + scanData[i+3] * 16*16;
          }
          m--;
    }

    calcuteDistance(vec_distance,distance,standDevit);
    if(standDevit >= MaxStandardDevitation){
        qWarning() << QString("%1,%2").arg(standDevit).arg(MaxStandardDevitation);
        goto start;
    }
    stopScanDistance();
    return;
}

void TempCalibrt::stopScanDistance(){
    QByteArray  arr;
    arr.resize(2);
    arr[0] = 0xa5;
    arr[1] = 0x65;
    port->sendInfo(arr.data(),2);
    port->flushReadCache();
}

bool  TempCalibrt::caculateCheckSum(char *scanData,const int num){
    CheckSumCal ^= SampleNumlAndCTCal;
    uint32_t checknum;
    for(int i=0; i<num;i++){
        if(i%2 ==0){
            checknum = (uint8_t)scanData[i];
        }else{
            checknum += (uint8_t)scanData[i] * (uint32_t)0x100;
            CheckSumCal ^= checknum;
            checknum = 0;
        }
    }
    if(CheckSumCal == CheckSum){
        return true;
    }
    return false;
}


void  TempCalibrt::calcuteDistance(vector<int32_t> &vec_distance,float &distance,float &deviation){
    int32_t sum = 0;
    int32_t  avg =0;
    int64_t div = 0;

    for(size_t i=0;i<vec_distance.size();i++){
        sum += vec_distance[i];
    }
    avg = sum / vec_distance.size();
    for(size_t i=0;i<vec_distance.size();i++){
        div += (vec_distance[i] - avg) * (vec_distance[i] - avg);
    }

    deviation = (sqrt(div*1.0 / vec_distance.size()));
    distance = (sum *1.0)/ (1.0*vec_distance.size()); //15.56
}


void  TempCalibrt::open(bool &flag, int baudrate,QString portName, \
                            int dirctions, \
                            int  dataBit, \
                            int StopBit, \
                        int controlBit ,int checkBit ){
  flag =  port->open(baudrate,portName,dirctions,dataBit,StopBit,controlBit,checkBit);
    return ;
}
void TempCalibrt::close(){
    port->close();
}

void TempCalibrt::sendInfo(bool &flag,char* cmd,const int len){
   flag = port->sendInfo(cmd,len);
   return;
}

void TempCalibrt::flushReadCache(){
    port->flushReadCache();
}

void  TempCalibrt::waitForData(bool &flag,int &count,const int timeout){

   flag = port->waitForData(count,timeout);

   return;
}

void TempCalibrt::getPortnameList(QStringList& qlist){
   port->getPortnameList(qlist);
}


void  TempCalibrt::getOpenStatus(bool &flag){
    bool isOk = port->isOpen();
    flag = isOk;
}
void  TempCalibrt::getValidSize(int &size){
    size = port->bytesAvailable();
}
