#include "machinecontrl.h"
#include "config.h"
#include <QThread>

machineContrl::machineContrl(QObject *parent)
{

}

machineContrl::~machineContrl(){

}

void machineContrl::open(bool &flag,int baudrate,QString portName,
                                int dirctions, int  dataBit,int StopBit,
                                int controlBit,int checkBit)
{
    qDebug() << "电机开始打开";
    qDebug() << "machinecontrol open func:" << QThread::currentThread();
    port = new myport::MySeriaPort;
    flag = port->open(baudrate,portName,dirctions,dataBit,StopBit,controlBit,checkBit);
    connect(port,&myport::MySeriaPort::readyRead,this,&machineContrl::slot_readyRead);
}

void  machineContrl::sendInfo(bool &flag, char *cmd, int len){
    flag = port->sendInfo(cmd,len);
    return;
}

void  machineContrl::slot_readyRead(){
    emit readyData();
}

void  machineContrl::close(){
    port->close();
    disconnect(port,&myport::MySeriaPort::readyRead,this,&machineContrl::slot_readyRead);
}

void machineContrl::testConnect(bool &flag){
    qDebug() << "dtr testConnect:" <<QThread::currentThread();
    flag = false;

    QByteArray arr;
    arr.resize(8);
    arr[0] = 0x01;
    arr[1] = 0x05;
    arr[2] = 0x00;
    arr[3] = 0x07;
    arr[4] = 0xff;
    arr[5] = 0x00;
    uint16_t crc16 = pubFunc::CRC16_MODBUS((uint8_t*)arr.data(),6);
    arr[6] = crc16 & 0xff;
    arr[7] = crc16 >>8;
    bool isOk = port->sendInfo(arr.data(),8);
    if(!isOk){
        qWarning() << QString("发送指令%1失败").arg(arr.data());
        return;
    }
    int count = 8;
    flag = port->waitForData(count,DefaultTimeout);
}


void machineContrl::flushReadCache(){
    port->flushReadCache();
}


void machineContrl::readData(bool& flag,int count,int timeout,QByteArray& arr){
    if(arr.size() < count){
        arr.resize(count);
    }
    flag = port->waitForData(count,timeout);
    if(!flag){
        return;
    }
    count = port->bytesAvailable();
    arr = port->readAll();
    flag = true;

}
