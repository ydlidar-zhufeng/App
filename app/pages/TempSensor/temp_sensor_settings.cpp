﻿#include "temp_sensor_settings.h"
#include "ui_temp_sensor_settings.h"
#include "newcombobox.h"
#include <QDebug>
#include <QThread>

Temp_Sensor_Settings::Temp_Sensor_Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Temp_Sensor_Settings)/*,status(false)*/
{
    ui->setupUi(this);
    init();
    connect(ui->combPortName,SIGNAL(clicked(bool)),this,SLOT(slot_getports(bool)));
}

Temp_Sensor_Settings::~Temp_Sensor_Settings()
{
    delete ui;
}

void Temp_Sensor_Settings::init(){
    connect(ui->btnSave,SIGNAL(clicked()),this,SLOT(slot_save_clicked()));
    connect(ui->btnStop,SIGNAL(clicked()),this,SLOT(slot_stop_clicked()));
    connect(ui->btnControl,SIGNAL(clicked()),this,SLOT(slot_open_clicked()),Qt::DirectConnection);
    connect(ui->btnSend,SIGNAL(clicked()),this,SLOT(slot_send_clicked()));
}

void Temp_Sensor_Settings::slot_getports(bool){
    qDebug() << "slot_getports";
    QStringList qlist;
    emit sig_getports(qlist);
    setCombPortName(qlist);
}

void Temp_Sensor_Settings::setCombPortName(QStringList & qlist){
    ui->combPortName->clear();
    ui->combPortName->addItems(qlist);
}

void Temp_Sensor_Settings::slot_open_clicked(bool flag){
    qDebug() << "进入open槽";
    qDebug() << "setting_thread:" <<QThread::currentThreadId();
    emit sig_open_clicked();
}

void Temp_Sensor_Settings::slot_save_clicked(bool flag){
    emit sig_save_clicked();
}

void Temp_Sensor_Settings::slot_send_clicked(bool flag){
    qDebug() << "send 槽";
    emit sig_send_clicked();
}

void Temp_Sensor_Settings::slot_stop_clicked(bool flag){
    emit sig_stop_clicked();
}


void  Temp_Sensor_Settings::getCombPortName(QString &portname){
    portname = ui->combPortName->currentText();
}

void  Temp_Sensor_Settings::getCombBaudrate(int &baudrate){
    baudrate = ui->combBaudrate->currentText().toInt();
}
void  Temp_Sensor_Settings::getStandardValue(int& stdVal){
    stdVal = ui->lineStandardDistance->text().toInt();
}
void  Temp_Sensor_Settings::getScanIntervalTime(int& intvl){
    intvl = ui->lineIntervalTime->text().toInt();
}

void Temp_Sensor_Settings::setContrlBtnText(bool flag){

    if(!flag){
        ui->btnControl->setText("close");
    }else{
        ui->btnControl->setText("open");
    }

}
