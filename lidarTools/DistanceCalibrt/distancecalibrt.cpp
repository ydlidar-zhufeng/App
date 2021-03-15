#include "distancecalibrt.h"
#include <QDebug>
#include <math.h>
#include <QByteArray>

using namespace  std;

DistanceCalibrt::DistanceCalibrt(QObject *parent):QObject(parent) //myport::MySeriaPort *port_
{
    qRegisterMetaType<_Tof_point>("_Tof_point");
    qRegisterMetaType<_Tof_point>("_Tof_point&");
    vec_tof.resize(MaxTempPointSize);
    vec_peak.resize(MaxTempPointSize);

    /////connect(this,&DistanceCalibrt::sig_tof_open,this,&DistanceCalibrt::open,Qt::BlockingQueuedConnection);

}

DistanceCalibrt::~DistanceCalibrt(){

}

void DistanceCalibrt::init(){
}


void  DistanceCalibrt::parseDataHeader(bool &flag,int timeout){
    int pos = 0;
    qint64 startTime = HDTimer::getCurrentTimeMisc();
    QByteArray ar;
    ar.resize(10);
    bool isOk = false;
    while(HDTimer::getCurrentTimeMisc() - startTime < timeout || timeout == -1){
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
   //     qDebug() << "等待成功";
        QByteArray tmp = port->read(qint64(remain));
    //    qDebug() <<"buf_hex:" << tmp.toHex();

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
        qDebug() << "header_array:" << ar.toHex();
        if (pos == 10){
            qDebug() << "获取数据成功!";
            flag = true;
           return;
        }
    }
    flag = false;
    return;
}

void DistanceCalibrt::getTestData(){
    bool flag = false;
    int count = 2000;
    waitForData(flag,count,-1);
    if (flag == false){
        qDebug() << "get test data failed";
    }
    port->readAll();
    qDebug() << "get test data success";
}

void DistanceCalibrt::startDistanceScan(_Tof_point &point,float &stddevit){
    QByteArray  arr;
    arr.resize(2);
    arr[0] = 0xA5;
    arr[1] = 0x60;
    ::memset(&point,0,sizeof(point));
    const int cstWaitSize = EveryPackagePointSize  *4 ;
    int waitSize =  cstWaitSize;
    char scanData[cstWaitSize+1];

    vec_tof.clear();
    vec_peak.clear();

    bool isOk = true;
    sendInfo(isOk,arr.data(),2);
    if(!isOk){
        stopScanDistance();
        qDebug() << "发送命令失败";
        return;
    }

    getTestData();
    int m = MaxTempPointSize / EveryPackagePointSize;
    while(m>0){
        bool ans = false;
        parseDataHeader(ans);
          qDebug() << "退出解析头";
          if (!ans){
              stopScanDistance();
              qDebug() << "解析头部失败,退出!";
              return;
          }

         // ans = true;
          ans = port->waitForData(waitSize, -1); //
          if (ans == false){
              stopScanDistance();
              qDebug() << "等待数据失败";
              return;
          }

          qint64 Maxlen = port->read(scanData,waitSize);
          qDebug() << "read_size_data:" << Maxlen;
          if(Maxlen != waitSize){
              qDebug() << "numbers of read bytes is wrong";
              continue;
          }
          ans = caculateCheckSum(scanData,waitSize);
          if (!ans){
              qDebug() << "校验和错误";
              continue;
          }
//          QByteArray a2(scanData);
//          qDebug() << "a2:" << a2.toHex();
//          qDebug() << "m:" << m << ",vec_size:" << vec_tof.size();
          for(int i=0;i<waitSize;i=i+4){
              vec_peak.push_back((uint8_t)scanData[i] *1 + 16*16*scanData[i+1]);
              vec_tof.push_back((uint8_t)scanData[i+2] *1 + 16*16*scanData[i+3]);
          }
          m--;
    }
    calcuteDistance(vec_tof,vec_peak,point,stddevit);
    stopScanDistance();
    return;
}

void DistanceCalibrt::stopScanDistance(){
    QByteArray  arr;
    arr.resize(2);
    arr[0] = 0xa5;
    arr[1] = 0x65;
    port->sendInfo(arr.data(),2);
    port->flushReadCache();
}

bool  DistanceCalibrt::caculateCheckSum(char *scanData,const int num){
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
        qDebug() << "校验和正确";
        return true;
    }
    return false;
}


void  DistanceCalibrt::calcuteDistance(std::vector<int32_t>&vec_tof,std::vector<int32_t>&vec_peak,_Tof_point& point,float &stddevit){
    int32_t sum_dis = 0;
    int32_t  sum_peak =0;
    int64_t div = 0;
    int size = std::min(vec_tof.size(),vec_peak.size());
    std::string peak_value;
    for(int i=0;i<size;i++){
        peak_value.append(to_string(vec_tof[i]));
        peak_value.append(",");
    }
  //  qDebug() << "tof_value:" << peak_value.c_str();
    for(int i=0;i<size;i++){
        sum_dis += vec_tof[i];
        sum_peak += vec_peak[i];
    }
    point.tof_avg = sum_dis *1.0 / size;
    point.peak_avg = sum_peak * 1.0 /size;

    point.peak_max = *max_element(vec_peak.begin(),vec_peak.end());
    point.peak_min = *min_element(vec_peak.begin(),vec_peak.end());
  //  qDebug() << "peak: a>.avg:" << point.peak_avg << "  b>.min:" << point.peak_min << " c>.max:" << point.peak_max;

    point.tof_max = *max_element(vec_tof.begin(),vec_tof.end());
    point.tof_min = *min_element(vec_tof.begin(),vec_tof.end());
    point.tof_deviation = point.tof_avg - stddevit;
}


void  DistanceCalibrt::open(bool &flag, int baudrate,QString portName, \
                            int dirctions, \
                            int  dataBit, \
                            int StopBit, \
                        int controlBit ,int checkBit ){
  qDebug() << "DistanceCalibrt open func:" << QThread::currentThread();
  port  = new myport::MySeriaPort;
  flag =  port->open(baudrate,portName,dirctions,dataBit,StopBit,controlBit,checkBit);
  connect(port,SIGNAL(addLog(QString&)),this,SLOT(slot_add_log(QString&)));
  return ;
}
void DistanceCalibrt::close(){
    qDebug() << "开始关闭";
    port->close();
}

void DistanceCalibrt::getData(QByteArray &data){
    qDebug() << "getData";
    QThread::msleep(500);
    data.clear();
    data.append(port->readAll().toHex());
    QString str = QString::fromLocal8Bit("receive data:\n%1").arg(QString(data));
    emit addLog(str);
}

void DistanceCalibrt::sendInfo(bool &flag,char* cmd,const int len){
    QString txt = QString("发送命令:%1").arg(QString(QByteArray(cmd).toHex()));
    qDebug() << "send data cmd:" << txt;
   // emit addLog(txt);
   flag = port->sendInfo(cmd,len);
   return;
}

void DistanceCalibrt::slot_add_log(QString &txt){
    emit addLog(txt);
}

void DistanceCalibrt::flushReadCache(){
    port->flushReadCache();
}

void  DistanceCalibrt::waitForData(bool &flag,int &count,const int timeout){

   flag = port->waitForData(count,timeout);

   return;
}

void DistanceCalibrt::getPortnameList(QStringList& qlist){
    qDebug() << "获取端口列表";
    qDebug() << "当前线程id——move:" << QThread::currentThread();

   port->getPortnameList(qlist);
   return;//   true;
}


void  DistanceCalibrt::getOpenStatus(bool &flag){
    bool isOk = port->isOpen();
    flag = isOk;
    return;
}
void  DistanceCalibrt::getValidSize(int &size){
    size = port->bytesAvailable();
}


void  DistanceCalibrt::testConnect(bool &flag){
   flag = false;
   QByteArray arr;
   arr.resize(6);
   arr[0] = 0xa5;
   arr[1] = 0xf0;
   arr[2] = 0xa5;
   arr[3] = 0xf0;
   arr[4] = 0xa5;
   arr[5] = 0xf0;
   bool isOk = port->sendInfo(arr.data(),6);
   if(!isOk){
       qWarning() << QString("发送指令%1失败").arg(arr.data());
       return;
   }
   int count = 10;
   flag = port->waitForData(count,DefaultTimeout);
}
