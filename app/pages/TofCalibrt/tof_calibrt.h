#ifndef TOF_CALIBRT_H
#define TOF_CALIBRT_H

#include <QWidget>
#include <QThread>
#include "config.h"
#include <QSerialPort>
#include "DistanceCalibrt/machinecontrl.h"
#include "DistanceCalibrt/distancecalibrt.h"
#include <QStandardItemModel>
#include <global.h>
#include <QLineEdit>
#include <QTimer>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
using namespace  std;
namespace Ui {
class tof_calibrt;
}

class  DistanceCalibrt;
class tof_calibrt : public QWidget
{
    Q_OBJECT

public:
    explicit tof_calibrt(QWidget *parent = nullptr);
    ~tof_calibrt();
    void emitClose();

private slots:
    void on_btncontrl_clicked();
    void on_btndata_clicked();
    void on_btnexcel_clicked();

    void getPortnameList(bool flag=false);
    void on_btndtrcontrol_clicked();

    void on_btnClearTable_clicked();
    void on_btnbackOnce_clicked();

    void  slot_add_log(QString & txt);

    void on_btnImportExcel_clicked();

    void on_btnWritePararmts_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_btnDtrTableAdd_clicked();

    void on_btnDtrTableDelRow_clicked();

    void on_btnOnceRun_clicked();

    void on_btnLimitSig_clicked();

    void on_btnAllRun_clicked();

    void on_btnClearModu_clicked();

    void on_btnTest_clicked();

    void on_btnReadLimitSig_clicked();

    void on_btnPositionSetZero_clicked();

    void on_btnFrontRun_clicked();

    void on_btnBackRun_clicked();

    void on_btnDtrStop_clicked();

    void on_btnReturnZeroPos_clicked();

    void on_btnGetCurrentPos_clicked();

    void on_btntableDtrClear_clicked();

public slots:
    void slot_exit_thread();
    void slot_btn_once_run();
    void slot_check_setZeroStatus();
    void slot_dtr_readyRead();

signals:
    void  sig_tof_open(bool &flag,int baudrate,QString portName,
                                int dirctions = QSerialPort::AllDirections,
                                int  dataBit =QSerialPort::Data8,
                                int StopBit =QSerialPort::OneStop,
                                int controlBit =QSerialPort::NoFlowControl,int checkBit = QSerialPort::NoParity);
    void  sig_dtr_open(bool &flag,int baudrate,QString portName,
                                int dirctions = QSerialPort::AllDirections,
                                int  dataBit =QSerialPort::Data8,
                                int StopBit =QSerialPort::OneStop,
                                int controlBit =QSerialPort::NoFlowControl,int checkBit = QSerialPort::NoParity);

    void sig_tof_close();
    void sig_dtr_close();

    void sig_tof_sendInfo(bool &flag,char* cmd,const int len);
    void sig_dtr_sendInfo(bool &flag,char* cmd,const int len);

    void sig_tof_flushReadCache();
    void sig_tof_getData(QByteArray &data);
    void sig_dtr_flushReadCache();

    void sig_tof_testConnect(bool &flag);
    void sig_dtr_testConnect(bool &flag);
    void sig_tof_startOnceScan(_Tof_point& point,float& stddevit);

    void sig_dtr_readData(bool &flag,int count ,int timeout,QByteArray& arr);
    void sig_exit_thread();

    void sig_btn_once_run();
private:
    void init();
    void initConnect();
    bool modulusPoints();
    void controlBtn();
    void dtr_once_cal(int dis,int speech,int direction);
    bool read_current_pos(QLineEdit *edit);

    bool read_one_register_func(read_register& addr,uint16_t& data);
    bool read_two_register_func(read_register& addr,uint16_t& data_first,uint16_t& data_second);
    bool read_four_register_func(read_register& addr,uint16_t* data_arr);
    bool write_single_register(write_single_address& addr);
    bool write_four_register(write_four_address& addr);
    bool write_two_register(write_two_address& addr);
    void getOncePointData();
    void loadConfig();
    void saveConfig();
    void GetDtrParm();
    void  setDTRBtnStatus(bool status);
private:
    Ui::tof_calibrt *ui;
    bool tof_status;
    bool dtr_status;
    QThread*  p_dtrThd;
    QThread*  p_tofThd;
private:
    QVector<_Tof_point> vec_point;
    DistanceCalibrt *p_calibrt;
    machineContrl    *p_machiCtl;
    int              array_index;
    bool          tableMax;
    int       sheetNum;
    int       lastTableRow;
    QFont      *logFont;
    Tof_Para_Type tof_para[6];
    QStandardItemModel *m_pDtrmodel;
    QTimer  *m_read_timer;

    int  timeoutCount = 0;
    bool setZeroStatus = false;
};

#endif // TOF_CALIBRT_H
