#ifndef MYSERIAPORT_H
#define MYSERIAPORT_H

#include <QSerialPort>
#include <QDateTime>
#include <QDebug>
#include <QThread>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
Q_DECLARE_METATYPE(QStringList);
namespace myport{
class MySeriaPort:public QSerialPort
{
    Q_OBJECT
public:    
    ~MySeriaPort();
    MySeriaPort * GetInstance(){
        return port_;
    }
public:
    MySeriaPort();
    void init();
    bool  open(const int baudrate,QString portName,
                                int dirctions = QSerialPort::AllDirections,
                                int  dataBit =QSerialPort::Data8,
                                int StopBit =QSerialPort::OneStop,
                                int controlBit =QSerialPort::NoFlowControl,int checkBit = QSerialPort::NoParity);
    void close();

    bool sendInfo(char* cmd,const int len);
    void flushReadCache();
    bool waitForData(int &count,const int timeout = -1);
    void   getPortnameList(QStringList& qlist);
signals:
    void addLog(QString &txt);

private:
    MySeriaPort *port_;

};
}





#endif // MYSERIAPORT_H
