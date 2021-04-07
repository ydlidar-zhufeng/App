#ifndef MACHINECONTRL_H
#define MACHINECONTRL_H
#include <QObject>
#include "myseriaport.h"
class machineContrl:public QObject
{
    Q_OBJECT
public:

    machineContrl(QObject *parent = nullptr);
    ~machineContrl();
signals:
    void readyData();
public slots:
    void   open(bool &flag,int baudrate,QString portName,
                                int dirctions = QSerialPort::AllDirections,
                                int  dataBit =QSerialPort::Data8,
                                int StopBit =QSerialPort::OneStop,
                                int controlBit =QSerialPort::NoFlowControl,int checkBit = QSerialPort::NoParity);
    void close();

    void  sendInfo(bool &flag,char* cmd,const int len);
    void flushReadCache();
    void testConnect(bool &flag);
   // void waitForData(bool &flag,int count,int timeout);
    void readData(bool& flag,int count,int timeout,QByteArray& arr);
    void slot_readyRead();
private:
    myport::MySeriaPort * port;
};

#endif // MACHINECONTRL_H
