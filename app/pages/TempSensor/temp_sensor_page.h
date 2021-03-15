#ifndef TEMP_SENSOR_PAGE_H
#define TEMP_SENSOR_PAGE_H

#include <QWidget>
#include "TempCalibrt/tempcalibrt.h"
#include "sliding_stacked_widget.h"
#include "temp_custom_display.h"
#include "temp_sensor_settings.h"
#include <QTimer>
#include <QThread>


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

namespace Ui {
class TempSensorPage;
}

class TempSensorPage : public QWidget
{
    Q_OBJECT


public:
    explicit TempSensorPage(QWidget *parent = nullptr);
    ~TempSensorPage();

private slots:
    void on_btnTempSettings_clicked();

    void on_btnCustomDisplay_clicked();
    void getPortNames(QStringList& qlist);
    void slot_open_clicked();
    void slot_send_clicked();
    void slot_stop_clicked();
    void slot_handle_timeout();
    void slot_save_clicked();
    void slot_modulus_clicked();

signals:
    void sig_stop_clicked();

    void  sig_startDistanceScan(float&,float&);
    void  sig_getTempValue(float&,bool& flag,int timeout = 1000);
    void  sig_stopScanDistance();
    void  sig_open(bool &flag,int baudrate,QString portName,
                                int dirctions = QSerialPort::AllDirections,
                                int  dataBit =QSerialPort::Data8,
                                int StopBit =QSerialPort::OneStop,
                                int controlBit =QSerialPort::NoFlowControl,int checkBit = QSerialPort::NoParity);
    void sig_close();

    void  sig_sendInfo(bool &flag,char* cmd,const int len);
    void sig_flushReadCache();
    void sig_waitForData(bool &flag,int &count,const int timeout = -1);
    void sig_getPortnameList(QStringList& qlist);
    void  sig_getOpenStatus(bool &flag);
    void  sig_getValidSize(int &size);



private:
    void init();
    void initConnect();
    bool testConnect();
    void clear_vector();
    void  readXlsx(QString fileName,QVector<double>& vec_temp,QVector<double>& vec_devit);

private:
    Ui::TempSensorPage *ui;
    SlidingStackedWidget *slidingStackedWidget;

    Temp_Sensor_Settings  *tempSensorSettings;
    TEMP_Custom_Display   *tempCustomDisplay;
    TempCalibrt  *p_tempcalibrt;
    bool status;
    QTimer  *p_timer;
    QVector<double> vec_temp,vec_dist,vec_stddevit,vec_devit;
    int fileNum;
    int refValue;
    int stdValue;
    bool fileStatus;
    QThread *p_thread;
};

#endif // TEMP_SENSOR_PAGE_H
