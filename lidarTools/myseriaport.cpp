#include "myseriaport.h"
#include <QSerialPortInfo>
#include <QDebug>
//#include <QtDebug>
#include <QThread>
#include "config.h"

namespace myport {

MySeriaPort::MySeriaPort()
{
    port_ = this;
    qRegisterMetaType<QStringList>("QStringList");
    qRegisterMetaType<QStringList>("QStringList&");
    qRegisterMetaType<QString>("QString&");
    init();
}

MySeriaPort::~MySeriaPort(){
    delete  this;
}

void MySeriaPort::init(){

}

void  MySeriaPort::getPortnameList(QStringList& qlist){
    for(QSerialPortInfo &info:QSerialPortInfo::availablePorts()){
        qlist << info.portName();
    }
    return ;
}

bool  MySeriaPort::open(const int baudrate,QString portName,
                           int dirctions,int  dataBit,int StopBit,
                             int controlBit,int checkBit){
    if (this->isOpen()){
        qDebug() << "close last port";
        this->close();
    }
    //目前只设置支持一个窗口
    this->setPortName(portName);
     qDebug() << "portname:" << portName << ",baudrate:" << baudrate;



    if(!this->QSerialPort::open(QIODevice::ReadWrite))//用ReadWrite 的模式尝试打开串口
    {
        qCritical() << "open port failed!";
       // delete this;
        return false;
    }

    this->setBaudRate(baudrate,QSerialPort::AllDirections);//设置波特率和读写方向,若是只读则设置成QSerialPort::Input,
    this->setDataBits(QSerialPort::Data8);		//数据位为8位
    this->setFlowControl(QSerialPort::NoFlowControl);//无流控制
    this->setParity(QSerialPort::NoParity);	//无校验位
    this->setStopBits(QSerialPort::OneStop); //一位停止位
    qDebug() << "open port success";

    return true;
}

void MySeriaPort::flushReadCache(){
    this->QSerialPort::readAll();
}

void MySeriaPort::close(){
    MySeriaPort * port = GetInstance();
    port->QSerialPort::close();
}

bool MySeriaPort::waitForData(int &count,const int timeout){
    //MySeriaPort * port = GetInstance();

   int asize = this->bytesAvailable();

   if (asize >= count){

       return true;
   }
  long long startTime = HDTimer::getCurrentTimeMisc();

   while(HDTimer::getCurrentTimeMisc()- startTime < (long long)timeout || timeout == -1) {

       this->waitForReadyRead(timeout);
       asize = this->bytesAvailable();
       if (asize >= count){
           return true;
       }
   }
   qDebug() << "wait timeout";
   qWarning() << QString("current byte size is %1,bytes we need is %2").arg(asize).arg(count);
   count = asize;
   return false;
}


bool MySeriaPort::sendInfo(char* cmd,const int len){

    if(!this->isOpen()){
        qDebug() << "port is not open!";
        qCritical() << "port is not open!";
    }

    QByteArray  arr;
    arr.resize(len);
    memcpy(arr.data(),cmd,len);
    QString txt = QString("%1").arg(QString(arr.toHex()));
    qDebug() << "send data cmd:" << arr.toHex()<<cmd;
    this->flush();

    qint64 size = this->write(cmd,len);
    if (size!= len){
        qWarning() << QString("write dtr serial data'size failed,cur size:%1,true size: %2").arg(size).arg(len);
        return false;
    }
//    int err = port->error();
//    if(err){
//        qDebug() << "err:" <<err;
//        QMessageBox::warning(NULL,"错误",QString("命令b:(%1)输入错误").arg(QString::fromUtf8(cmd)));
//        port->clearError();
//        cmd_status = false;
//        return;
//    }
    return true;
}

}


