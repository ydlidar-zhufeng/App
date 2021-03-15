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
    //Ŀǰֻ����֧��һ������
    this->setPortName(portName);
     qDebug() << "portname:" << portName << ",baudrate:" << baudrate;



    if(!this->QSerialPort::open(QIODevice::ReadWrite))//��ReadWrite ��ģʽ���Դ򿪴���
    {
        qCritical() << "open port failed!";
       // delete this;
        return false;
    }

    this->setBaudRate(baudrate,QSerialPort::AllDirections);//���ò����ʺͶ�д����,����ֻ�������ó�QSerialPort::Input,
    this->setDataBits(QSerialPort::Data8);		//����λΪ8λ
    this->setFlowControl(QSerialPort::NoFlowControl);//��������
    this->setParity(QSerialPort::NoParity);	//��У��λ
    this->setStopBits(QSerialPort::OneStop); //һλֹͣλ
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
//        QMessageBox::warning(NULL,"����",QString("����b:(%1)�������").arg(QString::fromUtf8(cmd)));
//        port->clearError();
//        cmd_status = false;
//        return;
//    }
    return true;
}

}


