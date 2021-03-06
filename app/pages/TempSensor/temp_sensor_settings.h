﻿#ifndef TEMP_SENSOR_SETTINGS_H
#define TEMP_SENSOR_SETTINGS_H

#include <QWidget>
#include <newcombobox.h>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
namespace Ui {
class Temp_Sensor_Settings;
}

class Temp_Sensor_Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Temp_Sensor_Settings(QWidget *parent = nullptr);
    ~Temp_Sensor_Settings();

    void  setCombPortName(QStringList & qlist);
    void  getCombPortName(QString &);
    void  getCombBaudrate(int &);
    void  getStandardValue(int&);
    void  getScanIntervalTime(int&);
//    void  setStatus(bool&);
//    void  getStatus(bool&);
    void  setContrlBtnText(bool flag =false);

private:
    void init();

signals:
    void  sig_getports(QStringList &qlist);
    void  sig_open_clicked();
    void  sig_send_clicked();
    void  sig_stop_clicked();
    void  sig_save_clicked();


private slots:
    void  slot_getports(bool);
    void  slot_open_clicked(bool flag = false);
    void  slot_send_clicked(bool flag = false);
    void  slot_stop_clicked(bool flag = false);
    void  slot_save_clicked(bool flag = false);


private:
    Ui::Temp_Sensor_Settings *ui;
//    bool status;
};

#endif // TEMP_SENSOR_SETTINGS_H
