#ifndef TEMPCALIBRT_H
#define TEMPCALIBRT_H

#include <QObject>

#include <vector>
#include <QThread>
#include "config.h"
#include "../myseriaport.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//using namespace  std;
Q_DECLARE_METATYPE(_Tof_point);
class DistanceCalibrt:public QObject
{
    Q_OBJECT
public:
    DistanceCalibrt(QObject *parent = nullptr);
    ~DistanceCalibrt();
//    static myport::MySeriaPort * GetInstance(){
//        return myport::MySeriaPort::GetInstance();
//    }

public slots:
    void  startDistanceScan(_Tof_point &point,float &stddevit);
    //void   getTempValue(float&,bool& flag,int timeout = 1000);
    //void init();
    void  parseDataHeader(bool &flag,int timeout =1000);
    void  stopScanDistance();
    void  calcuteDistance(std::vector<int32_t>&vec_tof,std::vector<int32_t>&vec_peak,_Tof_point& point,float &stddevit);


    void   open(bool &flag,int baudrate,QString portName,
                                int dirctions = QSerialPort::AllDirections,
                                int  dataBit =QSerialPort::Data8,
                                int StopBit =QSerialPort::OneStop,
                                int controlBit =QSerialPort::NoFlowControl,int checkBit = QSerialPort::NoParity);
    void close();
    void getData(QByteArray &data);
    void testConnect(bool &flag);

    void  sendInfo(bool &flag,char* cmd,const int len);
    void flushReadCache();
    void waitForData(bool &flag,int &count,const int timeout = -1);
    void  getPortnameList(QStringList& qlist);

    void  getOpenStatus(bool &flag);
    void  getValidSize(int &size);
    void  slot_add_log(QString &txt);
signals:
    void addLog(QString& txt);

private:
    void init();
    bool  caculateCheckSum(char *scanData,const int num);
    void  getTestData();

private:
    myport::MySeriaPort * port;
    std::vector<int32_t> vec_tof;
    std::vector<int32_t> vec_peak;

private:
   uint16_t  CheckSumCal;
   uint16_t  SampleNumlAndCTCal;
   uint16_t  firstAngle;
   uint16_t  lastAngle;
   uint16_t  CheckSum;
};

#endif // TEMPCALIBRT_H
