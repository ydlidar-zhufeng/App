﻿#ifndef TEMPCALIBRT_H
#define TEMPCALIBRT_H

#include <QObject>
#include "../myseriaport.h"
#include <vector>
#include <QThread>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

class TempCalibrt:public QObject
{
    Q_OBJECT
public:
    TempCalibrt(QObject *parent = nullptr); //myport::MySeriaPort *port_
    ~TempCalibrt();


public slots:
    void  startDistanceScan(float&,float&);
    void   getTempValue(float&,bool& flag,int timeout = 1000);
    //void init();
    void  parseDataHeader(bool &flag,int timeout =1000);
    void  stopScanDistance();
    void  calcuteDistance(std::vector<int32_t>&vec_distance,float &distance,float &deviation);


    void   open(bool &flag,int baudrate,QString portName,
                                int dirctions = QSerialPort::AllDirections,
                                int  dataBit =QSerialPort::Data8,
                                int StopBit =QSerialPort::OneStop,
                                int controlBit =QSerialPort::NoFlowControl,int checkBit = QSerialPort::NoParity);
    void close();

    void  sendInfo(bool &flag,char* cmd,const int len);
    void flushReadCache();
    void waitForData(bool &flag,int &count,const int timeout = -1);
    void  getPortnameList(QStringList& qlist);

    void  getOpenStatus(bool &flag);
    void  getValidSize(int &size);
private:
    void init();
    bool  caculateCheckSum(char *scanData,const int num);
public:
    myport::MySeriaPort * port;

private:
   uint16_t  CheckSumCal;
   uint16_t  SampleNumlAndCTCal;
   uint16_t  firstAngle;
   uint16_t  lastAngle;
   uint16_t  CheckSum;
};

#endif // TEMPCALIBRT_H
