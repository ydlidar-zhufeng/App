#include "ui_tof_calibrt.h"
#include "tof_calibrt.h"
#include <QSerialPortInfo>
#include <QMessageBox>
#include <math.h>
#include "Eigen/Core"
#include "Eigen/Dense"
#include "xlsxdocument.h"
#include "xlsxworkbook.h"
#include <QFileDialog>
#include <QDateTime>
#include <stdlib.h>
#include <QModelIndex>
#include <QTimer>
#include <string.h>
#include <QSettings>
#include "ejson.h"
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonParseError>

using namespace Eigen;
using namespace EasyJson;

const int tof_array[10] ={100,150,200,300,400,600,800,1000,1200,6000};

tof_calibrt::tof_calibrt(QWidget *parent):
    QWidget(parent),
    ui(new Ui::tof_calibrt),tof_status(false),
    dtr_status(false),array_index(0),tableMax(false),
    lastTableRow(0)
{
    ui->setupUi(this);
    vec_point.resize(20);
    vec_point.clear();
    memset(tof_para,0,sizeof(tof_para));
    init();
    initConnect();
    loadConfig();
    setDTRBtnStatus(false);

}

tof_calibrt::~tof_calibrt()
{
    delete ui;
    if (m_read_timer != nullptr) {
      delete m_read_timer;
      m_read_timer = nullptr;
    }
}



void tof_calibrt::init(){

    ui->tbwgttof_calibrt->setColumnCount(7);
    ui->tbwgttof_calibrt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//setSectionResizeMode(QHeaderView::Stretch)
    ///ui->tbwgttof_calibrt->setRowHeight(8,30);
    //然后设置要根据内容使用宽度的列
    ui->tbwgttof_calibrt->setRowCount(20);
    ui->tbwgttof_calibrt->horizontalHeader()->setStretchLastSection(true);//设置是否填充末尾列
    ui->tbwgttof_calibrt->verticalHeader()->setStretchLastSection(true);
    ui->tbwgttof_calibrt->verticalHeader()->setDefaultSectionSize(30);//设置默认行的高度
    ui->tbwgttof_calibrt->horizontalHeader()->setFixedHeight(25);//设置行的默认高度,水平表头就是横标题
    ui->tbwgttof_calibrt->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->tbwgttof_calibrt->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->tbwgttof_calibrt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tbwgttof_calibrt->setHorizontalHeaderLabels(QStringList()<<"tof最小值"<<"tof平均值"<<"tof最大值"<<"peak最小值"<<"peak平均值"<< "peak最大值" << "tof误差");
    ui->tbwgttof_calibrt->setVerticalHeaderLabels(QStringList()<<"100(黑)"<<"100(白)" <<"150(黑)" << "150(白)" <<"200(黑)" << "200(白)" <<"300(黑)"<<"300(白)" << "400(黑)" <<"400(白)"
                                                  <<"600(黑)"<<"600(白)"<<"800(黑)" << "800(白)"<<"1000(黑)"<<"1000(白)"<<"1200(黑)"<<"1200(白)"<<"6000(黑)"<<"6000(白)");

    ui->tbwgt_fit->setColumnCount(6);
    ui->tbwgt_fit->setColumnWidth(0,150);
    ui->tbwgt_fit->setColumnWidth(1,150);
    ui->tbwgt_fit->setColumnWidth(2,150);
    ui->tbwgt_fit->setColumnWidth(3,150);
    ui->tbwgt_fit->setColumnWidth(4,150);
    ui->tbwgt_fit->setColumnWidth(5,150);
    ui->tbwgt_fit->setRowCount(6);
    ui->tbwgt_fit->horizontalHeader()->setStretchLastSection(true);//设置是否填充末尾列
    ui->tbwgt_fit->verticalHeader()->setDefaultSectionSize(30);//设置默认行的高度
    ui->tbwgt_fit->horizontalHeader()->setFixedHeight(25);//设置行的默认高度,水平表头就是横标题
    ui->tbwgt_fit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->tbwgt_fit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->tbwgt_fit->setHorizontalHeaderLabels(QStringList()<<"系数" << "误差"<< "tof最大值" <<"tof最小值" << "peak最大值" << "peak 最小值");
    ui->tbwgt_fit->setVerticalHeaderLabels(QStringList()<<"第一组"<<"第二组" <<"第三组" << "第四组" << "第五组" <<"第六组");
    ui->tbwgt_fit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tbwgt_fit->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);



    //电机参数表

    m_pDtrmodel = new QStandardItemModel(ui->tableViewDtr);

    /*设置列数*/
    m_pDtrmodel->setColumnCount(4);
    m_pDtrmodel->setHorizontalHeaderLabels(QStringList()  << QString("距离") << QString("速度") << QString("方向(正0,反1)") << QString("坐标"));
    ui->tableViewDtr->verticalHeader()->setVisible(false);
    ui->tableViewDtr->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewDtr->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewDtr->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewDtr->setModel(m_pDtrmodel);
    ui->combbaudrate->setCurrentIndex(3);
    ui->combdtrbaudrate->setCurrentIndex(1);
    ui->checkBox->setCheckState(Qt::Checked);

    if (m_read_timer == nullptr) {
      m_read_timer = new QTimer();
      connect(m_read_timer,&QTimer::timeout,this,&tof_calibrt::slot_check_setZeroStatus);
    }
}

void tof_calibrt::slot_check_setZeroStatus(){
    if(setZeroStatus){
        setZeroStatus = false;
        return;
    }
    timeoutCount++;
    if(timeoutCount > 5){
      //  disconnect(m_read_timer,&QTimer::timeout,this,&tof_calibrt::slot_check_setZeroStatus);
        m_read_timer->stop();
        timeoutCount = 0;
    }


}

void tof_calibrt::initConnect(){
    p_tofThd = new QThread(this);
    p_calibrt = new DistanceCalibrt(nullptr);
    p_calibrt->moveToThread(p_tofThd);
    p_tofThd->start();

    p_dtrThd = new QThread(this);
    p_machiCtl = new machineContrl;
    p_machiCtl->moveToThread(p_dtrThd);
    p_dtrThd->start();

    connect(p_dtrThd,SIGNAL(finished()),p_machiCtl,SLOT(deleteLater()));
    connect(p_tofThd,SIGNAL(finished()),p_calibrt,SLOT(deleteLater()));

    connect(ui->combportname,SIGNAL(clicked(bool)),this,SLOT(getPortnameList(bool)));
    connect(ui->combdtrportname,SIGNAL(clicked(bool)),this,SLOT(getPortnameList(bool)));

    connect(this,SIGNAL(sig_exit_thread()),this,SLOT(slot_exit_thread()));

    connect(this,&tof_calibrt::sig_tof_open,p_calibrt,&DistanceCalibrt::open,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_tof_close,p_calibrt,&DistanceCalibrt::close,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_tof_getData,p_calibrt,&DistanceCalibrt::getData,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_tof_sendInfo,p_calibrt,&DistanceCalibrt::sendInfo,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_tof_testConnect,p_calibrt,&DistanceCalibrt::testConnect,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_tof_flushReadCache,p_calibrt,&DistanceCalibrt::flushReadCache,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_tof_startOnceScan,p_calibrt,&DistanceCalibrt::startDistanceScan,Qt::BlockingQueuedConnection);

    connect(this,&tof_calibrt::sig_dtr_open,p_machiCtl,&machineContrl::open,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_dtr_close,p_machiCtl,&machineContrl::close,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_dtr_sendInfo,p_machiCtl,&machineContrl::sendInfo,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_dtr_flushReadCache,p_machiCtl,&machineContrl::flushReadCache,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_dtr_testConnect,p_machiCtl,&machineContrl::testConnect,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_dtr_readData,p_machiCtl,&machineContrl::readData,Qt::BlockingQueuedConnection);
    connect(this,&tof_calibrt::sig_btn_once_run,this,&tof_calibrt::slot_btn_once_run);
    connect(p_machiCtl,&machineContrl::readyData,this,&tof_calibrt::slot_dtr_readyRead);
}

void tof_calibrt::slot_dtr_readyRead(){
    setZeroStatus = true;
    if(timeoutCount){
        timeoutCount = 0;
    }
}

void tof_calibrt::slot_add_log(QString& txt){

}

void tof_calibrt::slot_exit_thread(){
    p_dtrThd->quit();
    p_dtrThd->wait();
    delete p_dtrThd;
    p_tofThd->quit();
    p_tofThd->wait();
    delete p_tofThd;

    saveConfig();

}

void tof_calibrt::emitClose(){
    emit sig_exit_thread();
}

void tof_calibrt::getPortnameList(bool flag){
    ui->combportname->clear();
    ui->combdtrportname->clear();

    QStringList qlist;
    for(QSerialPortInfo &info:QSerialPortInfo::availablePorts()){
        qlist << info.portName();
    }

    ui->combdtrportname->addItems(qlist);
    ui->combportname->addItems(qlist);
}

void tof_calibrt::on_btncontrl_clicked()
{
    if(!tof_status){
        QString portname = ui->combportname->currentText();
        int baudrate = ui->combbaudrate->currentText().toInt();
        if(portname == "" || baudrate == 0){
            qCritical() << "串口或波特率为空";
            QMessageBox::warning(this,"错误","串口或波特率为空");
            return;
        }
        bool flag = false;
        emit sig_tof_open(flag,baudrate,portname);
        if(!flag){
            // emit sig_tof_close();
            QMessageBox::warning(this,"错误","串口打开失败");
            return;
        }
        emit sig_tof_testConnect(flag);
        if(!flag){
            emit sig_tof_close();
            QMessageBox::warning(this,"错误","串口测试未接收到数据");
            return;
        }
        ui->btncontrl->setText("关闭");
        tof_status = true;
        controlBtn();
        repaint();
        return;
    }
    emit sig_tof_close();
    tof_status = false;
    ui->btncontrl->setText("打开");
    controlBtn();

}


void tof_calibrt::slot_btn_once_run(){
    QPushButton *btn = reinterpret_cast<QPushButton*>(sender());
    btn->setEnabled(false);
    QTimer::singleShot(BtnMaxTimeout,this,[=]{
        btn->setEnabled(true);
    });
}

void tof_calibrt::on_btndata_clicked()
{
    modulusPoints();
}

void tof_calibrt::controlBtn(){
    ui->btnbackOnce->setVisible(tof_status);
    ui->btnexcel->setVisible(tof_status);
    ui->btndata->setVisible(tof_status);
    ui->btnexcel->setVisible(tof_status);
}

bool tof_calibrt::modulusPoints(){
    //vec_point
    if(array_index <20){
        QMessageBox::warning(this,tr("拟合错误"),tr("当前行数为%1,小于20行").arg(array_index),QMessageBox::Cancel);
        return false;
    }
    vec_point.clear();
    _Tof_point point;
    for(int i=0;i<20; i++){
        point.tof_min = ui->tbwgttof_calibrt->item(i,0)->text().toInt();
        point.tof_avg = ui->tbwgttof_calibrt->item(i,1)->text().toFloat();
        point.tof_max = ui->tbwgttof_calibrt->item(i,2)->text().toInt();
        point.peak_min = ui->tbwgttof_calibrt->item(i,3)->text().toInt();
        point.peak_avg = ui->tbwgttof_calibrt->item(i,4)->text().toDouble();
        point.peak_max = ui->tbwgttof_calibrt->item(i,5)->text().toInt();
        point.tof_deviation = ui->tbwgttof_calibrt->item(i,6)->text().toDouble();
        vec_point.push_back(point);
    }

    QVector<array_modulus> vec_arr_modulus;
    vec_arr_modulus.resize(6);
    vec_arr_modulus.clear();

    QVector<_Tof_point> vec_threshold; //未分组前每一段的
    QVector<_Tof_point> vec_arr_threshold; //分组后的
    vec_threshold.resize(6);
    vec_arr_threshold.resize(6);

    {
        //第一段:  /* 不同于第一组 */
        vec_threshold[0].tof_max = vec_point[0].tof_max;
        vec_threshold[0].tof_min = vec_point[0].tof_min;
        vec_threshold[0].peak_max = vec_point[0].peak_max;
        vec_threshold[0].peak_min = vec_point[0].peak_min;

        for(int i=1;i<4;i++){
            if(vec_threshold[0].tof_max < vec_point[i].tof_max){
                vec_threshold[0].tof_max = vec_point[i].tof_max;
            }
            if(vec_threshold[0].tof_min > vec_point[i].tof_min){
                vec_threshold[0].tof_min = vec_point[i].tof_min;
            }

            if(vec_threshold[0].peak_max < vec_point[i].peak_max){
                vec_threshold[0].peak_max = vec_point[i].peak_max;
            }
            if(vec_threshold[0].peak_min > vec_point[i].peak_min){
                vec_threshold[0].peak_min = vec_point[i].peak_min;
            }
        }

        //第二段:
        vec_threshold[1].tof_max = vec_point[2].tof_max;
        vec_threshold[1].tof_min = vec_point[2].tof_min;
        vec_threshold[1].peak_max = vec_point[2].peak_max;
        vec_threshold[1].peak_min = vec_point[2].peak_min;

        for(int i=3;i<6;i++){
            if(vec_threshold[1].tof_max < vec_point[i].tof_max){
                vec_threshold[1].tof_max = vec_point[i].tof_max;
            }
            if(vec_threshold[1].tof_min > vec_point[i].tof_min){
                vec_threshold[1].tof_min = vec_point[i].tof_min;
            }

            if(vec_threshold[1].peak_max < vec_point[i].peak_max){
                vec_threshold[1].peak_max = vec_point[i].peak_max;
            }
            if(vec_threshold[1].peak_min > vec_point[i].peak_min){
                vec_threshold[1].peak_min = vec_point[i].peak_min;
            }
        }

        //第三段:
        vec_threshold[2].tof_max = vec_point[4].tof_max;
        vec_threshold[2].tof_min = vec_point[4].tof_min;
        vec_threshold[2].peak_max = vec_point[4].peak_max;
        vec_threshold[2].peak_min = vec_point[4].peak_min;

        for(int i=5;i<10;i++){
            if(vec_threshold[2].tof_max < vec_point[i].tof_max){
                vec_threshold[2].tof_max = vec_point[i].tof_max;
            }
            if(vec_threshold[2].tof_min > vec_point[i].tof_min){
                vec_threshold[2].tof_min = vec_point[i].tof_min;
            }

            if(vec_threshold[2].peak_max < vec_point[i].peak_max){
                vec_threshold[2].peak_max = vec_point[i].peak_max;
            }
            if(vec_threshold[2].peak_min > vec_point[i].peak_min){
                vec_threshold[2].peak_min = vec_point[i].peak_min;
            }
        }

        //第四段:
        vec_threshold[3].tof_max = vec_point[6].tof_max;
        vec_threshold[3].tof_min = vec_point[6].tof_min;
        vec_threshold[3].peak_max = vec_point[6].peak_max;
        vec_threshold[3].peak_min = vec_point[6].peak_min;

        for(int i=7;i<14;i++){
            if(vec_threshold[3].tof_max < vec_point[i].tof_max){
                vec_threshold[3].tof_max = vec_point[i].tof_max;
            }
            if(vec_threshold[3].tof_min > vec_point[i].tof_min){
                vec_threshold[3].tof_min = vec_point[i].tof_min;
            }

            if(vec_threshold[3].peak_max < vec_point[i].peak_max){
                vec_threshold[3].peak_max = vec_point[i].peak_max;
            }
            if(vec_threshold[3].peak_min > vec_point[i].peak_min){
                vec_threshold[3].peak_min = vec_point[i].peak_min;
            }
        }

        //第五段:
        vec_threshold[4].tof_max = vec_point[10].tof_max;
        vec_threshold[4].tof_min = vec_point[10].tof_min;
        vec_threshold[4].peak_max = vec_point[10].peak_max;
        vec_threshold[4].peak_min = vec_point[10].peak_min;

        for(int i=11;i<18;i++){
            if(vec_threshold[4].tof_max < vec_point[i].tof_max){
                vec_threshold[4].tof_max = vec_point[i].tof_max;
            }
            if(vec_threshold[4].tof_min > vec_point[i].tof_min){
                vec_threshold[4].tof_min = vec_point[i].tof_min;
            }

            if(vec_threshold[4].peak_max < vec_point[i].peak_max){
                vec_threshold[4].peak_max = vec_point[i].peak_max;
            }
            if(vec_threshold[4].peak_min > vec_point[i].peak_min){
                vec_threshold[4].peak_min= vec_point[i].peak_min;
            }
        }

        //第六段:
        vec_threshold[5].tof_max = vec_point[14].tof_max;
        vec_threshold[5].tof_min = vec_point[14].tof_min;
        vec_threshold[5].peak_max = vec_point[14].peak_max;
        vec_threshold[5].peak_min = vec_point[14].peak_min;

        for(int i=15;i<20;i++){
            if(vec_threshold[5].tof_max < vec_point[i].tof_max){
                vec_threshold[5].tof_max = vec_point[i].tof_max;
            }
            if(vec_threshold[5].tof_min > vec_point[i].tof_min){
                vec_threshold[5].tof_min = vec_point[i].tof_min;
            }

            if(vec_threshold[5].peak_max < vec_point[i].peak_max){
                vec_threshold[5].peak_max = vec_point[i].peak_max;
            }
            if(vec_threshold[5].peak_min > vec_point[i].peak_min){
                vec_threshold[5].peak_min = vec_point[i].peak_min;
            }
        }

    }

    for(int i =0;i<6-1;i++){
        if(vec_threshold[i].peak_min <= 0|| vec_threshold[i].tof_min <= 0){
            QMessageBox::warning(this,"错误","peak值采集有误");
            return  false;
        }
    }

    {
        vec_arr_threshold[0] = vec_threshold[0];
        vec_arr_threshold[0].tof_min = vec_threshold[1].tof_min;

        vec_arr_threshold[1] = vec_threshold[1];
        vec_arr_threshold[1].tof_min = vec_threshold[2].tof_min;

        vec_arr_threshold[2] = vec_threshold[2];
        vec_arr_threshold[2].tof_min = vec_threshold[3].tof_min;

        vec_arr_threshold[3] = vec_threshold[3];
        vec_arr_threshold[3].tof_min = vec_threshold[4].tof_min;

        vec_arr_threshold[4] = vec_threshold[4];
        vec_arr_threshold[4].tof_min = vec_threshold[5].tof_min;

        vec_arr_threshold[5] = vec_threshold[5];
        vec_arr_threshold[5].tof_min = 65535;
        vec_arr_threshold[5].tof_max = 65535;
    }

    {

        qDebug() << "开始拟合误差";
        //计算第一组的拟合
        MatrixXd X1(4,2);//peak
        MatrixXd Y1(4,1);//bias

        MatrixXd X2(6,2);
        MatrixXd Y2(6,1);

        MatrixXd X3(8,2);
        MatrixXd Y3(8,1);
        Vector2d RES;//结果

        //全部元素置1
        X1 = MatrixXd::Constant(4,2,1);
        X2 = MatrixXd::Constant(6,2,1);
        X3 = MatrixXd::Constant(8,2,1);

        //数组转矩阵
        for(int i = 0; i < 4; i++)
        {
            X1(i,0) = vec_point[i].peak_avg;//信号质量
            Y1(i,0) = vec_point[i].tof_deviation;//偏差
        }
        //拟合公式
        RES = (X1.transpose() * X1).inverse() * (X1.transpose() * Y1);
        vec_arr_modulus.push_back(array_modulus{RES[0],RES[1]});

        //计算第二组的拟合
        //数组转矩阵
        for(quint8 i = 2; i < 6; i++)
        {
            X1(i-2,0) = vec_point[i].peak_avg;//信号质量
            Y1(i-2,0) = vec_point[i].tof_deviation;//偏差
        }
        //拟合公式
        RES = (X1.transpose() * X1).inverse() * (X1.transpose() * Y1);
        vec_arr_modulus.push_back(array_modulus{RES[0],RES[1]});

        //计算第三组的拟合
        //数组转矩阵
        for(quint8 i = 4; i < 10; i++)
        {
            X2(i-4,0) = vec_point[i].peak_avg;//信号质量
            Y2(i-4,0) = vec_point[i].tof_deviation;//偏差
        }
        //拟合公式
        RES = (X2.transpose() * X2).inverse() * (X2.transpose() * Y2);
        vec_arr_modulus.push_back(array_modulus{RES[0],RES[1]});
        //计算第四组的拟合
        //数组转矩阵
        for(quint8 i = 6; i < 14; i++)
        {
            X3(i-6,0) = vec_point[i].peak_avg;//信号质量
            Y3(i-6,0) = vec_point[i].tof_deviation;//偏差
        }
        //拟合公式
        RES = (X3.transpose() * X3).inverse() * (X3.transpose() * Y3);
        vec_arr_modulus.push_back(array_modulus{RES[0],RES[1]});
        //计算第五组的拟合
        //数组转矩阵
        for(quint8 i = 10; i < 18; i++)
        {
            X3(i-10,0) = vec_point[i].peak_avg;//信号质量
            Y3(i-10,0) = vec_point[i].tof_deviation;//偏差
        }
        //拟合公式
        RES = (X3.transpose() * X3).inverse() * (X3.transpose() * Y3);
        vec_arr_modulus.push_back(array_modulus{RES[0],RES[1]});
        //计算第六组的拟合
        //数组转矩阵
        for(quint8 i = 14; i < 20; i++)
        {
            X2(i-14,0) = vec_point[i].peak_avg;//信号质量
            Y2(i-14,0) = vec_point[i].tof_deviation;//偏差
        }
        //拟合公式
        RES = (X2.transpose() * X2).inverse() * (X2.transpose() * Y2);
        vec_arr_modulus.push_back(array_modulus{RES[0],RES[1]});

        //求global_offset
        float maxoffset = 0;
        float minoffset = 1000;

        for(int i =0; i <8;i++){
            int index = 0;
            while (index < 6) // 小于6组
            {
                float Tof_cal = 0;
                if(vec_point[i].tof_avg < vec_arr_threshold[index].tof_min){
                    Tof_cal = vec_point[i].tof_avg - (vec_arr_modulus[index].k * vec_point[i].peak_avg + vec_arr_modulus[index].b);
                    float biosTmp = Tof_cal - tof_array[i/2];
                    maxoffset = maxoffset > biosTmp ? maxoffset:biosTmp;
                    minoffset = minoffset < biosTmp ? minoffset:biosTmp;
                    break;
                }else if (vec_point[i].tof_avg > vec_arr_threshold[index].tof_min && vec_point[i].tof_avg < vec_arr_threshold[index].tof_max){

                    Q_ASSERT(index< 6-1);
                    float w1 = vec_point[i].tof_avg - vec_arr_threshold[index].tof_min;
                    float w2 = vec_arr_threshold[index].tof_max - vec_point[i].tof_avg;
                    float kNew = (w1* vec_arr_modulus[index+1].k + w2 * vec_arr_modulus[index].k) /(w1 + w2);
                    float bNew = (w1 * vec_arr_modulus[index+1].b + w2 * vec_arr_modulus[index].b) /(w1 + w2);
                    int peakThNew = (w1*vec_arr_threshold[index+1].peak_min + w2 * vec_arr_threshold[index].peak_min) / (w1+w2);
                    if(vec_point[i].peak_avg > peakThNew){
                        peakThNew = vec_point[i].peak_avg;
                    }

                    float offset = kNew * peakThNew + bNew;
                    Tof_cal = vec_point[i].tof_avg - offset;
                    float biosTmp = Tof_cal - tof_array[i/2];
                    maxoffset = maxoffset > biosTmp ? maxoffset:biosTmp;
                    minoffset = minoffset < biosTmp ? minoffset:biosTmp;
                    break;

                }
                index++;
            }
        }

        float biosOffset = (maxoffset + minoffset) / 2.0;
        for(int i =0 ;i< vec_arr_modulus.size();i++){
            vec_arr_modulus[i].b += biosOffset;
        }
    }
    {

        memset(tof_para,0,sizeof(tof_para));
        for(int i =0;i<6;i++){
            tof_para[i].tof_max = vec_arr_threshold[i].tof_max;
            tof_para[i].tof_min = vec_arr_threshold[i].tof_min;
            tof_para[i].peak_max = vec_arr_threshold[i].peak_max;
            tof_para[i].peak_min = vec_arr_threshold[i].peak_min;
            tof_para[i].line_k = vec_arr_modulus[i].k * 1000;
            tof_para[i].line_b = vec_arr_modulus[i].b;
        }

        //填充拟合表数据
        for(int i= 0;i<6;i++){
            ui->tbwgt_fit->setItem(i,0,new QTableWidgetItem(QString("%1").arg(vec_arr_modulus[i].k)));
            ui->tbwgt_fit->setItem(i,1,new QTableWidgetItem(QString("%1").arg(vec_arr_modulus[i].b)));
            ui->tbwgt_fit->setItem(i,2,new QTableWidgetItem(QString("%1").arg(tof_para[i].tof_max)));
            ui->tbwgt_fit->setItem(i,3,new QTableWidgetItem(QString("%1").arg(tof_para[i].tof_min)));
            ui->tbwgt_fit->setItem(i,4,new QTableWidgetItem(QString("%1").arg(tof_para[i].peak_max)));
            ui->tbwgt_fit->setItem(i,5,new QTableWidgetItem(QString("%1").arg(tof_para[i].peak_min)));
            ui->tbwgt_fit->item(i,0)->setTextAlignment(Qt::AlignCenter);
            ui->tbwgt_fit->item(i,1)->setTextAlignment(Qt::AlignCenter);
            ui->tbwgt_fit->item(i,2)->setTextAlignment(Qt::AlignCenter);
            ui->tbwgt_fit->item(i,3)->setTextAlignment(Qt::AlignCenter);
            ui->tbwgt_fit->item(i,4)->setTextAlignment(Qt::AlignCenter);
            ui->tbwgt_fit->item(i,5)->setTextAlignment(Qt::AlignCenter);
        }
    }
    return  true;

}

void tof_calibrt::on_btnexcel_clicked()
{
    QString excelPath;

    excelPath = QFileDialog::getSaveFileName(this,"输出文件选择",".",tr("file (*.xlsx  *.xls)"));
    if(excelPath == ""){
        qDebug() << "excel path is empth or qmap is empty!";
        return;
    }

    QXlsx::Document xlsx(excelPath);//打开需要打开的excel文件，filePath为打开的文件名
    xlsx.setColumnWidth(1,15);
    xlsx.setColumnWidth(2,15);
    xlsx.setColumnWidth(3,15);

    QString sheetName = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    if(xlsx.addSheet(sheetName,QXlsx::AbstractSheet::ST_WorkSheet)){
        xlsx.selectSheet(sheetName);
    }
    xlsx.write(1,2,"tof_min");
    xlsx.write(1,3,"tof_avg");
    xlsx.write(1,4,"tof_max");
    xlsx.write(1,5,"peak_min");
    xlsx.write(1,6,"peak_avg");
    xlsx.write(1,7,"peak_max");

    int i=0;
    while(i<20){
        xlsx.write(i+2,1,QString("%1(%2)").arg(tof_array[i/2]).arg((i % 2 == 0)?"黑":"白"));
        if(ui->tbwgttof_calibrt->item(i,0)->text() == "")
            break;
        xlsx.write(i+2,2,ui->tbwgttof_calibrt->item(i,0)->text());
        xlsx.write(i+2,3,ui->tbwgttof_calibrt->item(i,1)->text());
        xlsx.write(i+2,4,ui->tbwgttof_calibrt->item(i,2)->text());
        xlsx.write(i+2,5,ui->tbwgttof_calibrt->item(i,3)->text());
        xlsx.write(i+2,6,ui->tbwgttof_calibrt->item(i,4)->text());
        xlsx.write(i+2,7,ui->tbwgttof_calibrt->item(i,5)->text());
        xlsx.write(i+2,8,ui->tbwgttof_calibrt->item(i,6)->text());
        i++;
    }
    xlsx.write(i+3,2,"系数");
    xlsx.write(i+3,3,"误差");
    for(int j = 0;j < 6;j++,i++){
        if(ui->tbwgt_fit->item(j,0)->text() == "")
            break;
        xlsx.write(i+4,1,QString("第%1组").arg(j+1));
        xlsx.write(i+4,2,ui->tbwgt_fit->item(j,0)->text());
        xlsx.write(i+4,3,ui->tbwgt_fit->item(j,1)->text());
    }

    xlsx.saveAs(excelPath);//写完之后一定要保存

}

void tof_calibrt::on_btndtrcontrol_clicked()
{
    if(!dtr_status){
        QString portname = ui->combdtrportname->currentText();
        int baudrate = ui->combdtrbaudrate->currentText().toInt();
        if(portname == "" || baudrate == 0){
            QMessageBox::warning(this,"错误","串口或波特率为空");
            return;
        }
        bool flag = false;
        emit sig_dtr_open(flag,baudrate,portname);
        if(!flag){

            QMessageBox::warning(this,"错误","串口打开失败");
            return;
        }

        if(!flag){
            QMessageBox::warning(this,"错误","串口测试未接收到数据");
            return;
        }
        ui->btndtrcontrol->setText("关闭");
        dtr_status = true;
        setDTRBtnStatus(true);
        return;
    }
    emit sig_dtr_close();
    dtr_status = false;
    ui->btndtrcontrol->setText("打开");
    setDTRBtnStatus(false);
}


void tof_calibrt::getOncePointData()
{

    int index = ui->tbwgttof_calibrt->currentRow();
    int temp;
    if(index != -1 && lastTableRow != index){
        temp = array_index;
        array_index = index;
    }

    if(array_index == 20){
        qDebug() << "已越界";
        return;
    }

    _Tof_point  point;
    float devit = tof_array[array_index/2];
    emit sig_tof_startOnceScan(point,devit);
    QCoreApplication::processEvents();
    vec_point[array_index] = point;
    ui->tbwgttof_calibrt->setItem(array_index,0,new QTableWidgetItem(QString("%1").arg(point.tof_min)));
    ui->tbwgttof_calibrt->setItem(array_index,1,new QTableWidgetItem(QString("%1").arg(point.tof_avg)));
    ui->tbwgttof_calibrt->setItem(array_index,2,new QTableWidgetItem(QString("%1").arg(point.tof_max)));
    ui->tbwgttof_calibrt->setItem(array_index,3,new QTableWidgetItem(QString("%1").arg(point.peak_min)));
    ui->tbwgttof_calibrt->setItem(array_index,4,new QTableWidgetItem(QString("%1").arg(point.peak_avg)));
    ui->tbwgttof_calibrt->setItem(array_index,5,new QTableWidgetItem(QString("%1").arg(point.peak_max)));
    ui->tbwgttof_calibrt->setItem(array_index,6,new QTableWidgetItem(QString("%1").arg(point.tof_deviation)));

    ui->tbwgttof_calibrt->item(array_index,0)->setTextAlignment(Qt::AlignCenter);
    ui->tbwgttof_calibrt->item(array_index,1)->setTextAlignment(Qt::AlignCenter);
    ui->tbwgttof_calibrt->item(array_index,2)->setTextAlignment(Qt::AlignCenter);
    ui->tbwgttof_calibrt->item(array_index,3)->setTextAlignment(Qt::AlignCenter);
    ui->tbwgttof_calibrt->item(array_index,4)->setTextAlignment(Qt::AlignCenter);
    ui->tbwgttof_calibrt->item(array_index,5)->setTextAlignment(Qt::AlignCenter);
    ui->tbwgttof_calibrt->item(array_index,6)->setTextAlignment(Qt::AlignCenter);
    array_index++;
    lastTableRow = index;

}

void tof_calibrt::on_btnClearTable_clicked()
{
    array_index = 0;
    vec_point.clear();
    ui->tbwgttof_calibrt->clearContents();

}

void tof_calibrt::on_btnbackOnce_clicked()
{
    if(array_index == 0){
        return;
    }

    vec_point.pop_back();
    array_index--;
    ui->tbwgttof_calibrt->setItem(array_index,0,new QTableWidgetItem(""));
    ui->tbwgttof_calibrt->setItem(array_index,1,new QTableWidgetItem(""));
    ui->tbwgttof_calibrt->setItem(array_index,2,new QTableWidgetItem(""));
    ui->tbwgttof_calibrt->setItem(array_index,3,new QTableWidgetItem(""));
    ui->tbwgttof_calibrt->setItem(array_index,4,new QTableWidgetItem(""));
    ui->tbwgttof_calibrt->setItem(array_index,5,new QTableWidgetItem(""));
}


void tof_calibrt::on_btnImportExcel_clicked()
{
    QString excelPath;

    excelPath = QFileDialog::getOpenFileName(this,"输出文件选择",".",tr("file (*.xlsx  *.xls)"));
    if(excelPath == ""){
        qDebug() << "excel path is empth or qmap is empty!";
        return;
    }

    QXlsx::Document xlsx(excelPath);//打开需要打开的excel文件，filePath为打开的文件名
    QXlsx::Workbook *workBook = xlsx.workbook();
    QXlsx::Worksheet *workSheet = static_cast<QXlsx::Worksheet*>(workBook->sheet(0));//第一个标签页
    qDebug() << workBook->sheet(0)->sheetName();
    int rowCount = workSheet->dimension().rowCount();
    if(rowCount >= 1000){
        rowCount = 1000;
    }
    qDebug() << "rowCount" << rowCount;
    for (int i = 1; i <= 21; i++)
    {
        if(i == 1){
            continue;
        }
        QXlsx::Cell *cell = workSheet->cellAt(i, 2);
        ui->tbwgttof_calibrt->setItem(i-2,0,new QTableWidgetItem(QString("%1").arg(cell->value().toInt())));
        cell = workSheet->cellAt(i, 3);
        ui->tbwgttof_calibrt->setItem(i-2,1,new QTableWidgetItem(QString("%1").arg(cell->value().toDouble())));
        cell = workSheet->cellAt(i, 4);
        ui->tbwgttof_calibrt->setItem(i-2,2,new QTableWidgetItem(QString("%1").arg(cell->value().toInt())));
        cell = workSheet->cellAt(i, 5);
        ui->tbwgttof_calibrt->setItem(i-2,3,new QTableWidgetItem(QString("%1").arg(cell->value().toInt())));
        cell = workSheet->cellAt(i, 6);
        ui->tbwgttof_calibrt->setItem(i-2,4,new QTableWidgetItem(QString("%1").arg(cell->value().toDouble())));
        cell = workSheet->cellAt(i, 7);
        ui->tbwgttof_calibrt->setItem(i-2,5,new QTableWidgetItem(QString("%1").arg(cell->value().toInt())));
        cell = workSheet->cellAt(i, 8);
        ui->tbwgttof_calibrt->setItem(i-2,6,new QTableWidgetItem(QString("%1").arg(cell->value().toDouble())));

        ui->tbwgttof_calibrt->item(i-2,0)->setTextAlignment(Qt::AlignCenter);
        ui->tbwgttof_calibrt->item(i-2,1)->setTextAlignment(Qt::AlignCenter);
        ui->tbwgttof_calibrt->item(i-2,2)->setTextAlignment(Qt::AlignCenter);
        ui->tbwgttof_calibrt->item(i-2,3)->setTextAlignment(Qt::AlignCenter);
        ui->tbwgttof_calibrt->item(i-2,4)->setTextAlignment(Qt::AlignCenter);
        ui->tbwgttof_calibrt->item(i-2,5)->setTextAlignment(Qt::AlignCenter);
        ui->tbwgttof_calibrt->item(i-2,6)->setTextAlignment(Qt::AlignCenter);
    }
}

void tof_calibrt::on_btnWritePararmts_clicked()
{
    uint8_t sum =0;
    uint8_t *cs  = (uint8_t*)&tof_para->tof_max;
    for(int i =0;i<144;i++){
        sum ^= *(cs + i);
    }
    QByteArray send_arr;
    send_arr.append(0xa5);
    send_arr.append(0xa0);
    send_arr.append((char*)&tof_para[0],144);
    send_arr.append(sum);
    send_arr.append(0x5a);
    bool flag = false;
    emit  sig_tof_sendInfo(flag,send_arr.data(),148);
    QByteArray arr_getData;
    emit sig_tof_getData(arr_getData);
}

void tof_calibrt::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == 0){
        ui->checkBox->setText("反转");
    }else {
        ui->checkBox->setText("正转");
    }

}

void tof_calibrt::on_btnDtrTableAdd_clicked()
{
    float dis = ui->lineDistance->text().toFloat();
    float speech = ui->lineSpeech->text().toFloat();
    int  direction = (ui->checkBox->checkState()) ? 0:1;//正转为0，反转为1
    int row = m_pDtrmodel->rowCount();
    m_pDtrmodel->insertRow(row);
    m_pDtrmodel->setItem(row,0,new QStandardItem(QString("%1").arg(dis)));
    m_pDtrmodel->setItem(row,1,new QStandardItem(QString("%1").arg(speech)));
    m_pDtrmodel->setItem(row,2,new QStandardItem(QString("%1").arg(direction)));

    m_pDtrmodel->item(row,0)->setTextAlignment(Qt::AlignCenter);
    m_pDtrmodel->item(row,1)->setTextAlignment(Qt::AlignCenter);
    m_pDtrmodel->item(row,2)->setTextAlignment(Qt::AlignCenter);

}

void tof_calibrt::on_btnDtrTableDelRow_clicked()
{
    int row  =  ui->tableViewDtr->currentIndex().row();
    if(-1 == row){
        int aRow = m_pDtrmodel->rowCount();
        m_pDtrmodel->takeRow(aRow-1);
        return;
    }
    m_pDtrmodel->takeRow(row);
}

void tof_calibrt::on_btnOnceRun_clicked()
{
    emit sig_btn_once_run();
    //读起始坐标
    read_current_pos(ui->lineStartingPos);
    int startPos = ui->lineStartingPos->text().toInt();
    int  dis = ui->lineDistance->text().toFloat() * 100;
    int speech = ui->lineSpeech->text().toInt();
    int  direction = (ui->checkBox->checkState()) ? 0:1;//正转为2，反转为0

    dtr_once_cal(dis,speech,direction);
    int CurPos = ui->lineCurrentPos->text().toInt();
    int diff = (CurPos - startPos);
    if(direction){
        diff = - diff;
    }
    if(fabs(diff  - (dis /100)) >=3){
        QMessageBox::warning(this,QString("电机坐标有误"),QString("起始坐标:%1,结束坐标:%2,设定运行距离:%3,相差:%4,大于最大误差3!").arg(startPos).arg(CurPos).arg(dis /100.0).arg(diff),QMessageBox::Cancel);
        return;
    }

    qApp->processEvents();
    //getOncePointData();
    qApp->processEvents();
}


void tof_calibrt::dtr_once_cal(int dis,int speech,int direction){
    //写速度、距离、方向寄存器
    write_four_address multp_addr;
    uint8_t * pHeader = reinterpret_cast<uint8_t *>(&multp_addr.device_number);
    uint8_t device_number = DTR_CMD_DEVICE_NUM;
    uint8_t func_code = WRITE_MULTIPLE_REGISTER_FUNC_CODE;
    uint16_t start_div = ADDR_SPEECH_START_ADDRESS_ONE;
    multp_addr.device_number = device_number;
    multp_addr.func_code =  func_code;
    multp_addr.start_div = start_div;
    multp_addr.data[0] = htou16(speech);
    multp_addr.data[1] = htou16((uint16_t)dis & 0xffff);
    multp_addr.data[2] = htou16(dis >> 16);
    multp_addr.data[3] = htou16(direction);
    multp_addr.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof(multp_addr) - 2);

    bool flag = write_four_register(multp_addr);
    if(!flag){
        QMessageBox::warning(this,QString("发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return;
    }

    //单次运行
    write_single_address  singl_addr;
    pHeader = reinterpret_cast<uint8_t *>(&singl_addr.device_number);
    func_code = WRITE_SINGLE_COIL_FUNC_CODE;
    start_div = ADDR_DTR_ONCE_RUN;
    singl_addr.device_number = device_number;
    singl_addr.func_code =  func_code;
    singl_addr.start_div = start_div;
    singl_addr.data = DATA_COIL_TURN_ON;
    singl_addr.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof(singl_addr) - 2);
    flag = write_single_register(singl_addr);
    if(!flag){
        QMessageBox::warning(this,QString("发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return;
    }

    //读当前坐标
    QThread::msleep(2000);
    read_current_pos(ui->lineCurrentPos);
    //    getOncePointData();

}

bool tof_calibrt::read_current_pos(QLineEdit *edit){
    bool flag = false;
    int count = 8;
    uint16_t crc;
    uint8_t device_number = DTR_CMD_DEVICE_NUM;
    uint8_t  func_code;
    uint16_t  start_div;
    QByteArray local_data;
    read_register  read_addr;
    uint8_t *pHeader = reinterpret_cast<uint8_t *>(&read_addr.device_number);
    char *sendH = (char*)pHeader;
    func_code = READ_REGISTER_FUNC_CODE;
    start_div = ADDR_GET_CUR_POS_TWO;
    read_addr.device_number = device_number;
    read_addr.func_code =  func_code;
    read_addr.start_div = start_div;
    read_addr.data_num = htou16(0x0002);
    read_addr.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof(read_addr) - 2);
    uint16_t first_register,second_register;
    flag = read_two_register_func(read_addr,first_register,second_register);
    if(!flag){
        QMessageBox::warning(this,QString("发送失败"),QString("发送读坐标命令失败"),QMessageBox::Cancel);
        return  false;
    }

    uint32_t pos = htou16(first_register) + (htou16(second_register) << 16);
    edit->setText(QString("%1").arg(pos / 100));
    return  true;
}

void tof_calibrt::on_btnLimitSig_clicked()
{
    bool flag = false;
    QByteArray local_data;
    uint16_t  crc;
    uint8_t device_number = DTR_CMD_DEVICE_NUM;
    uint8_t func_code;

    //写步距角
    write_two_address  two_addr_write;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&two_addr_write.device_number);
    func_code = WRITE_MULTIPLE_REGISTER_FUNC_CODE;
    two_addr_write.func_code = func_code;
    two_addr_write.start_div = ADDR_STEP_ANGLE_ONE;
    uint32_t stepAngle = ui->lineStepAngle->text().toFloat() * 100;
    two_addr_write.data[0] = htou16(stepAngle);
    two_addr_write.data[1] = htou16(ui->lineSubdiv->text().toInt());
    two_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (two_addr_write) -2);
    uint16_t first;
    uint16_t second;
    flag = write_two_register(two_addr_write);
    if(!flag){
        QMessageBox::warning(this,QString("配置失败"),QString("写步距角和细分失败"),QMessageBox::Cancel);
        return;
    }

    //写螺距
    two_addr_write.start_div = ADDR_PITCH_TWO;
    uint32_t picth = ui->linePitch->text().toFloat() * 100;
    two_addr_write.data[0] = htou16(picth & 0xffff);
    two_addr_write.data[1] = htou16(picth >> 16);
    two_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (two_addr_write) -2);
    flag = write_two_register(two_addr_write);
    if(!flag){
        QMessageBox::warning(this,QString("配置失败"),QString("写螺距失败"),QMessageBox::Cancel);
        return;
    }

    //写限位
    two_addr_write.start_div = ADDR_POSTV_LSIG_ONE;
    two_addr_write.data[0] = htou16(ui->linePLimitSig->text().toInt());
    two_addr_write.data[1] = htou16(ui->lineILimitSig->text().toInt());
    two_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (two_addr_write) -2);
    flag = write_two_register(two_addr_write);
    if(!flag){
        QMessageBox::warning(this,QString("配置失败"),QString("写限位失败"),QMessageBox::Cancel);
        return;
    }


    write_single_address sing_addr_write;
    //写运行方式,0相对，1绝对
    pHeader = reinterpret_cast<uint8_t *>(&sing_addr_write.device_number);
    sing_addr_write.start_div = ADDR_RUNWAY_ONE;
    sing_addr_write.func_code = WRITE_SINGLE_REGISTER_FUNC_CODE;
    sing_addr_write.data = htou16(ui->comboRunWay->currentIndex());

    sing_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (sing_addr_write) -2);
    flag = write_single_register(sing_addr_write);
    if(!flag){
        QMessageBox::warning(this,QString("配置失败"),QString("写运行方式失败"),QMessageBox::Cancel);
        return;
    }

    //写正反转启动信号
    two_addr_write.start_div = ADDR_FORWARE_ROTATION_START_SIGNAL_ONE;
    two_addr_write.data[0] = htou16(ui->lineforwardSignal->text().toInt());
    two_addr_write.data[1] = htou16(ui->lineBackSignal->text().toInt());
    two_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (two_addr_write) -2);
    flag = write_two_register(two_addr_write);
    if(!flag){
        QMessageBox::warning(this,QString("配置失败"),QString("写正反转启动信号失败"),QMessageBox::Cancel);
        return;
    }


}

void tof_calibrt::on_btnAllRun_clicked()
{
    int row = m_pDtrmodel->rowCount();
    int dis;
    int speech;
    read_current_pos(ui->lineStartingPos);
    m_pDtrmodel->horizontalHeaderItem(3)->setText(QString("起始:%1").arg(ui->lineStartingPos->text()));
    int startPos = ui->lineStartingPos->text().toInt();
    int direction;
    int CurPos ;
    int diff;
    for(int i=0;i<row;i++){
        dis = m_pDtrmodel->item(i,0)->text().toFloat() * 100;
        speech =m_pDtrmodel->item(i,1)->text().toInt();
        direction = m_pDtrmodel->item(i,2)->text().toInt();//正转为0，反转为1;
        dtr_once_cal(dis,speech,direction);
        qApp->processEvents();
        CurPos = ui->lineCurrentPos->text().toInt();
        m_pDtrmodel->setItem(i,3,new QStandardItem(QString("%1").arg(CurPos)));

        m_pDtrmodel->item(i,3)->setTextAlignment(Qt::AlignCenter);
        diff = (CurPos - startPos);
        if(direction){
            diff = - diff;
        }
        if(fabs(diff  - (dis /100)) >=3){
            QMessageBox::warning(this,QString("电机坐标有误"),QString("[行%5] 起始坐标:%1,结束坐标:%2,设定运行距离:%3,相差:%4,大于最大误差3!").arg(startPos).arg(CurPos).arg(dis /100.0).arg(diff).arg(i),QMessageBox::Cancel);
            m_pDtrmodel->item(i,0)->setBackground(QBrush(QColor("#55ff0000")));
            m_pDtrmodel->item(i,1)->setBackground(QBrush(QColor("#55ff0000")));
            m_pDtrmodel->item(i,2)->setBackground(QBrush(QColor("#55ff0000")));
            m_pDtrmodel->item(i,3)->setBackground(QBrush(QColor("#55ff0000")));
            return;
        }
        read_current_pos(ui->lineStartingPos);
        startPos = ui->lineStartingPos->text().toInt();

        qApp->processEvents();
        getOncePointData();
        qApp->processEvents();
    }



    //是否自动标定
    if(Qt::Checked ==  ui->checkBoxModulus->checkState()){
        if(!modulusPoints())
            return;
    }

    //是否自动写入模组
    if(Qt::Checked ==  ui->checkBoxWriteIn->checkState()){
        on_btnWritePararmts_clicked();
    }

    //全部标定完后，需要返回零位
    if(Qt::Checked ==  ui->checkBoxAutoZero->checkState()){
        on_btnReturnZeroPos_clicked();
        QThread::msleep(4000);
        read_current_pos(ui->lineCurrentPos);
        CurPos = ui->lineCurrentPos->text().toInt();
        if(0 != CurPos){
            QMessageBox::warning(this,tr("电机回零位失败"),tr("当前坐标为%1").arg(CurPos),QMessageBox::Cancel);
            return;
        }

    }

}

bool tof_calibrt::read_four_register_func(read_register& addr,uint16_t* data_arr){
    emit sig_dtr_flushReadCache();
    bool flag;
    QByteArray  local_data;
    uint16_t  crc;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&addr.device_number);
    char *sendH = (char*)pHeader;
    emit sig_dtr_sendInfo(flag,sendH,sizeof(addr));
    if(!flag){
        QMessageBox::warning(this,QString("读多寄存器指令发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return false;
    }
    read_four_register_rtn four_addr_read_rtn;
    int count = sizeof(read_four_register_rtn);
    local_data.clear();
    emit sig_dtr_readData(flag,count,DefaultTimeout,local_data);
    uint8_t * p_rtn_header = reinterpret_cast<uint8_t *>(&four_addr_read_rtn.device_number);

    memcpy(p_rtn_header,local_data.data(),sizeof(four_addr_read_rtn));
    {
        crc = pubFunc::CRC16_MODBUS(p_rtn_header,sizeof(four_addr_read_rtn) - 2);
        if(crc != four_addr_read_rtn.crc){
            QMessageBox::warning(this,tr("读多寄存器crc校验错误"),tr("读多寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
        if(addr.device_number != four_addr_read_rtn.device_number || addr.func_code != four_addr_read_rtn.func_code
                || 8 != four_addr_read_rtn.data_num){
            QMessageBox::warning(this,tr("读多寄存器回包内容错误"),tr("读多寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
        data_arr[0] = four_addr_read_rtn.data[0];
        data_arr[1] = four_addr_read_rtn.data[1];
        data_arr[2] = four_addr_read_rtn.data[2];
        data_arr[3] = four_addr_read_rtn.data[3];
    }

    return  true;
}

bool tof_calibrt::read_two_register_func(read_register& addr,uint16_t& data_first,uint16_t& data_second){
    emit sig_dtr_flushReadCache();
    bool flag;
    QByteArray  local_data;
    uint16_t  crc;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&addr.device_number);
    char *sendH = (char*)pHeader;
    emit sig_dtr_sendInfo(flag,sendH,sizeof(addr));
    if(!flag){
        QMessageBox::warning(this,QString("读两个寄存器指令发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return false;
    }
    read_two_register_rtn two_addr_read_rtn;
    int count = sizeof(read_two_register_rtn);
    local_data.clear();
    emit sig_dtr_readData(flag,count,DefaultTimeout,local_data);
    uint8_t * p_rtn_header = reinterpret_cast<uint8_t *>(&two_addr_read_rtn.device_number);
    if(!flag){
        QMessageBox::warning(this,tr("读两个寄存器回包错误"),tr("该指令未返回数据"),QMessageBox::Cancel);
        return  false;
    }

    memcpy(p_rtn_header,local_data.data(),sizeof(two_addr_read_rtn));
    {
        crc = pubFunc::CRC16_MODBUS(p_rtn_header,sizeof(two_addr_read_rtn) - 2);
        if(crc != two_addr_read_rtn.crc){
            QMessageBox::warning(this,tr("读两个寄存器crc校验错误"),tr("读两个寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
        if(addr.device_number != two_addr_read_rtn.device_number || addr.func_code != two_addr_read_rtn.func_code
                || 4 != two_addr_read_rtn.data_num){
            QMessageBox::warning(this,tr("读两个寄存器指令回包内容错误"),tr("读两个寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
        data_first = two_addr_read_rtn.first_data;
        data_second = two_addr_read_rtn.second_data;
    }

    return  true;
}


bool tof_calibrt::read_one_register_func(read_register& addr,uint16_t& data){
    bool flag;
    QByteArray  local_data;
    uint16_t  crc;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&addr.device_number);
    char *sendH = (char*)pHeader;
    emit sig_dtr_sendInfo(flag,sendH,sizeof(addr));
    if(!flag){
        QMessageBox::warning(this,QString("读单寄存器命令发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return false;
    }

    read_one_register_rtn one_addr_read_rtn;
    int count = sizeof(read_one_register_rtn);
    local_data.clear();
    emit sig_dtr_readData(flag,count,DefaultTimeout,local_data);
    uint8_t * p_rtn_header = reinterpret_cast<uint8_t *>(&one_addr_read_rtn.device_number);
    if(!flag){
        QMessageBox::warning(this,tr("读单寄存器回包错误"),tr("该指令未返回数据"),QMessageBox::Cancel);
        return  false;
    }

    memcpy(p_rtn_header,local_data.data(),sizeof(one_addr_read_rtn));
    {
        crc = pubFunc::CRC16_MODBUS(p_rtn_header,sizeof(one_addr_read_rtn) - 2);
        if(crc != one_addr_read_rtn.crc){
            QMessageBox::warning(this,tr("读单寄存器crc校验错误"),tr("读单寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
        if(addr.device_number != one_addr_read_rtn.device_number || addr.func_code != one_addr_read_rtn.func_code
                || 2 != one_addr_read_rtn.data_num){
            QMessageBox::warning(this,tr("读单寄存器回包内容错误"),tr("读单寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
        data = one_addr_read_rtn.data;
    }

    return  true;
}


bool tof_calibrt::write_single_register(write_single_address& addr){
    bool flag;
    QByteArray  local_data;
    uint16_t  crc;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&addr.device_number);
    char *sendH = (char*)pHeader;
    QByteArray arr;
    arr.resize(8);
    memcpy(arr.data(),sendH,sizeof(addr));
    emit sig_dtr_sendInfo(flag,sendH,sizeof(addr));
    if(!flag){
        QMessageBox::warning(this,QString("写单寄存器指令发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return false;
    }

    write_address_return_cmd one_addr_write_rtn;
    int count = sizeof(write_address_return_cmd);
    local_data.clear();
    emit sig_dtr_readData(flag,count,DefaultTimeout,local_data);
    uint8_t * p_rtn_header = reinterpret_cast<uint8_t *>(&one_addr_write_rtn.device_number);
    if(!flag){
        QMessageBox::warning(this,tr("写单寄存器回包错误"),tr("该指令未返回数据"),QMessageBox::Cancel);
        return  false;
    }

    memcpy(p_rtn_header,local_data.data(),sizeof(one_addr_write_rtn));
    {
        crc = pubFunc::CRC16_MODBUS(p_rtn_header,sizeof(one_addr_write_rtn) - 2);
        if(crc != one_addr_write_rtn.crc){
            QMessageBox::warning(this,tr("写单寄存器crc校验错误"),tr("写单寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
        if(one_addr_write_rtn != addr){
            QMessageBox::warning(this,tr("写单寄存器回包内容错误"),tr("写单寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
    }

    return  true;
}

bool tof_calibrt::write_four_register(write_four_address& addr){
    bool flag;
    QByteArray  local_data;
    uint16_t  crc;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&addr.device_number);
    char *sendH = (char*)pHeader;
    emit sig_dtr_sendInfo(flag,sendH,sizeof(addr));
    if(!flag){
        QMessageBox::warning(this,QString("写多寄存器指令发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return false;
    }
    write_address_return_cmd multi_addr_write_rtn;
    int count = sizeof(write_address_return_cmd);
    emit sig_dtr_readData(flag,count,DefaultTimeout,local_data);
    if(!flag){
        QMessageBox::warning(this,QString("写多寄存器指令发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return false;
    }
    uint8_t * p_rtn_header = reinterpret_cast<uint8_t *>(&multi_addr_write_rtn.device_number);
    memcpy(p_rtn_header,local_data.data(),sizeof(multi_addr_write_rtn));
    {
        crc = pubFunc::CRC16_MODBUS(p_rtn_header,sizeof(multi_addr_write_rtn) - 2);
        if(crc != multi_addr_write_rtn.crc){
            QMessageBox::warning(this,tr("写多寄存器crc校验错误"),tr("写四个寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
        if(addr.device_number != multi_addr_write_rtn.device_number || addr.func_code != multi_addr_write_rtn.func_code
                || addr.start_div != multi_addr_write_rtn.start_div || addr.register_num != multi_addr_write_rtn.register_num){
            QMessageBox::warning(this,tr("写多寄存器回包内容错误"),tr("写四个寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
    }

    return  true;
}

bool tof_calibrt::write_two_register(write_two_address& addr){
    bool flag;
    QByteArray  local_data;
    uint16_t  crc;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&addr.device_number);
    char *sendH = (char*)pHeader;
    emit sig_dtr_sendInfo(flag,sendH,sizeof(addr));
    if(!flag){
        QMessageBox::warning(this,QString("写两个寄存器指令发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return false;
    }
    if(addr.start_div == ADDR_FORWARE_ROTATION_START_SIGNAL_ONE){
        return true;
    }
    write_address_return_cmd multi_addr_write_rtn;
    int count = sizeof(write_address_return_cmd);

    emit sig_dtr_readData(flag,count,DefaultTimeout,local_data);
    if(!flag){
        QMessageBox::warning(this,QString("写两个寄存器指hui包失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return false;
    }

    uint8_t * p_rtn_header = reinterpret_cast<uint8_t *>(&multi_addr_write_rtn.device_number);
    memcpy(p_rtn_header,local_data.data(),sizeof(multi_addr_write_rtn));
    {
        crc = pubFunc::CRC16_MODBUS(p_rtn_header,sizeof(multi_addr_write_rtn) - 2);
        if(crc != multi_addr_write_rtn.crc){
            QMessageBox::warning(this,tr("写两个寄存器crc校验错误"),tr("写两个寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
        if(addr.device_number != multi_addr_write_rtn.device_number || addr.func_code != multi_addr_write_rtn.func_code
                || addr.start_div != multi_addr_write_rtn.start_div || addr.register_num != multi_addr_write_rtn.register_num){
            QMessageBox::warning(this,tr("写两个寄存器回包内容错误"),tr("写两个寄存器时回包错误"),QMessageBox::Cancel);
            return false;
        }
    }

    return  true;
}


void tof_calibrt::GetDtrParm()
{
    bool flag = false;
    QByteArray local_data;
    uint16_t  crc;
    uint8_t device_number = DTR_CMD_DEVICE_NUM;
    uint8_t func_code;

    //读步距角和细分
    read_register  sing_addr_read;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&sing_addr_read.device_number);
    func_code = READ_REGISTER_FUNC_CODE;
    sing_addr_read.func_code = func_code;
    sing_addr_read.start_div = ADDR_STEP_ANGLE_ONE;
    sing_addr_read.data_num = htou16(0x0002);
    sing_addr_read.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (sing_addr_read) -2);
    uint16_t first;
    uint16_t second;
    flag = read_two_register_func(sing_addr_read,first,second);
    if(!flag){
        QMessageBox::warning(this,QString("发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return;
    }
    int stepAngle = htou16(first);
    ui->lineStepAngle->setText(QString("%1").arg(stepAngle / 100.0));
    ui->lineSubdiv->setText(QString("%1").arg(htou16(second)));

    //读螺距
    sing_addr_read.start_div = ADDR_PITCH_TWO;
    sing_addr_read.data_num = htou16(0x0002);
    sing_addr_read.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (sing_addr_read) -2);
    flag = read_two_register_func(sing_addr_read,first,second);
    if(!flag){
        QMessageBox::warning(this,QString("发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return;
    }
    int pitch = htou16(first) + ((htou16(second)) << 16);
    ui->linePitch->setText(QString("%1").arg(pitch / 100));

    //读限位
    sing_addr_read.start_div = ADDR_POSTV_LSIG_ONE;
    sing_addr_read.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (sing_addr_read) -2);
    flag = read_two_register_func(sing_addr_read,first,second);
    if(!flag){
        QMessageBox::warning(this,QString("发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return;
    }
    ui->linePLimitSig->setText(QString("%1").arg(htou16(first)));
    ui->lineILimitSig->setText(QString("%1").arg(htou16(second)));

    //读运行方式
    sing_addr_read.start_div = ADDR_RUNWAY_ONE;
    sing_addr_read.data_num = htou16(0x0001);
    sing_addr_read.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (sing_addr_read) -2);
    flag = read_one_register_func(sing_addr_read,first);
    if(!flag){
        QMessageBox::warning(this,QString("发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return;
    }
    ui->comboRunWay->setCurrentIndex(htou16(first));

    //读速度、距离、方向
    sing_addr_read.start_div = ADDR_SPEECH_START_ADDRESS_ONE;
    sing_addr_read.data_num = htou16(0x0004);
    sing_addr_read.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (sing_addr_read) -2);
    uint16_t data_arr[4];
    flag = read_four_register_func(sing_addr_read,data_arr);
    if(!flag){
        QMessageBox::warning(this,QString("发送失败"),QString("发送命令失败"),QMessageBox::Cancel);
        return;
    }
    if(htou16(data_arr[3])){
        ui->checkBox->setCheckState(Qt::Unchecked);
    }else {
        ui->checkBox->setCheckState(Qt::Checked);
    }
    ui->lineSpeech->setText(QString("%1").arg(htou16(data_arr[0])));
    int dis = htou16(data_arr[1]) + ((htou16(data_arr[2])) << 16);
    ui->lineDistance->setText(QString("%1").arg(dis /100));
}


void tof_calibrt::on_btnClearModu_clicked()
{
    ui->tbwgt_fit->clearContents();
}

void tof_calibrt::on_btnTest_clicked()
{
    write_two_address  two_addr_write;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&two_addr_write.device_number);
    char *pChar = (char*)pHeader;
    uint8_t func_code = WRITE_MULTIPLE_REGISTER_FUNC_CODE;
    two_addr_write.func_code = func_code;
    two_addr_write.start_div = ADDR_DIS_START_ADDRESS_TWO;
    uint32_t stepAngle = ui->lineStepAngle->text().toFloat() * 100;
    two_addr_write.data[0] = htou16(stepAngle & 0xffff);
    two_addr_write.data[1] = htou16(stepAngle >> 16);
    two_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (two_addr_write) -2);
    QByteArray local_data(pChar);
    QByteArray cpy_data;
    cpy_data.resize(13);
    memcpy(cpy_data.data(),pChar,sizeof (write_two_address));
}

void tof_calibrt::loadConfig(){
    QString filepath = QDir::currentPath() + "/settings.ini";
    if(!QFile::exists(filepath)){
        QSettings settings(filepath, QSettings::IniFormat);
        settings.beginGroup("DTR");
        settings.setValue("stepAngle", 1.8);
        settings.setValue("subDiv", 8);
        settings.setValue("pitch", 100);
        settings.setValue("distance", 100);
        settings.setValue("speech", 70);
        settings.setValue("plimit", 2);
        settings.setValue("ilimit", 1);
        settings.setValue("runway",0);
        settings.setValue("direction",0);
        settings.setValue("forwardStartSignal",2);
        settings.setValue("backStartSignal",2);
        settings.endGroup();

        settings.beginGroup("Auto");
        settings.setValue("autoSetZero",false);
        settings.setValue("autoModulus",false);
        settings.setValue("autoWriteIn",false);
        settings.endGroup();
    }

    QSettings settings(filepath, QSettings::IniFormat);
    settings.beginGroup("DTR");
    ui->lineStepAngle->setText(QString("%1").arg(settings.value("stepAngle").toFloat()));
    ui->lineSubdiv->setText(QString("%1").arg(settings.value("subDiv").toInt()));
    ui->linePitch->setText(QString("%1").arg(settings.value("pitch").toFloat()));
    ui->lineDistance->setText(QString("%1").arg(settings.value("distance").toFloat()));
    ui->lineSpeech->setText(QString("%1").arg(settings.value("speech").toInt()));
    ui->linePLimitSig->setText(QString("%1").arg(settings.value("plimit").toInt()));
    ui->lineILimitSig->setText(QString("%1").arg(settings.value("ilimit").toInt()));
    ui->comboRunWay->setCurrentIndex(settings.value("runway").toInt());
    ui->lineforwardSignal->setText(QString("%1").arg(settings.value("forwardStartSignal").toInt()));
    ui->lineBackSignal->setText(QString("%1").arg(settings.value("backStartSignal").toInt()));
    int ck = settings.value("direction").toInt();
    if(0 == ck){
        ui->checkBox->setCheckState(Qt::Checked);
        ui->checkBox->setText("正转");
    }else {
        ui->checkBox->setCheckState(Qt::Unchecked);
        ui->checkBox->setText("反转");
    }

    settings.endGroup();

    settings.beginGroup("Auto");
    if(settings.value("autoSetZero").toBool()){
        ui->checkBoxAutoZero->setCheckState(Qt::Checked);
    }else {
        ui->checkBoxAutoZero->setCheckState(Qt::Unchecked);
    }
    if(settings.value("autoModulus").toBool()){
        ui->checkBoxModulus->setCheckState(Qt::Checked);
    }else {
        ui->checkBoxModulus->setCheckState(Qt::Unchecked);
    }
    if(settings.value("autoWriteIn").toBool()){
        ui->checkBoxWriteIn->setCheckState(Qt::Checked);
    }else {
        ui->checkBoxWriteIn->setCheckState(Qt::Unchecked);
    }
    settings.endGroup();


    QString jsonPath = QDir::currentPath() + "/dtr_config.json";

    if(!QFile::exists(jsonPath)){
        return;
    }
    QFile  file(jsonPath);
    if(file.open(QIODevice::ReadOnly)){
        QJsonParseError err;
        QByteArray fileContent = file.readAll();
        QJsonDocument  doc=QJsonDocument::fromJson(fileContent,&err);

        if(err.error){
            QMessageBox::warning(this,tr("初始化配置错误"),tr("电机json配置文件解析失败,错误为:%1").arg(err.errorString()),QMessageBox::Cancel);
        }

        int row = 0;
        QJsonArray arrays  = doc.array();
        foreach(auto array,arrays){
            auto arr =  array.toArray();
            if(arr.size() >=3){
                m_pDtrmodel->insertRow(row);
                m_pDtrmodel->setItem(row,0,new QStandardItem(QString("%1").arg(arr[0].toInt())));
                m_pDtrmodel->setItem(row,1,new QStandardItem(QString("%1").arg(arr[1].toInt())));
                m_pDtrmodel->setItem(row,2,new QStandardItem(QString("%1").arg(arr[2].toInt())));

                m_pDtrmodel->item(row,0)->setTextAlignment(Qt::AlignCenter);
                m_pDtrmodel->item(row,1)->setTextAlignment(Qt::AlignCenter);
                m_pDtrmodel->item(row,2)->setTextAlignment(Qt::AlignCenter);
            }
        }


    }

}

void tof_calibrt::saveConfig(){
    QString filepath = QDir::currentPath() + "/settings.ini";
    QSettings settings(filepath, QSettings::IniFormat);
    settings.beginGroup("DTR");
    settings.setValue("stepAngle", ui->lineStepAngle->text().toFloat());
    settings.setValue("subDiv", ui->lineSubdiv->text().toInt());
    settings.setValue("pitch", ui->linePitch->text().toFloat());
    settings.setValue("distance", ui->lineDistance->text().toInt());
    settings.setValue("speech", ui->lineSpeech->text().toInt());
    settings.setValue("plimit", ui->linePLimitSig->text().toInt());
    settings.setValue("ilimit", ui->lineILimitSig->text().toInt());
    settings.setValue("runway",ui->comboRunWay->currentIndex());
    int ck = 1;
    if(Qt::Checked == ui->checkBox->checkState()){
        ck = 0;
    }
    settings.setValue("direction",ck);
    settings.setValue("forwardStartSignal",ui->lineforwardSignal->text().toInt());
    settings.setValue("backStartSignal",ui->lineBackSignal->text().toInt());
    settings.endGroup();

    settings.beginGroup("Auto");
    if(Qt::Checked == ui->checkBoxAutoZero->checkState()){
        settings.setValue("autoSetZero",true);
    }else {
        settings.setValue("autoSetZero",false);
    }
    if(Qt::Checked == ui->checkBoxModulus->checkState()){
        settings.setValue("autoModulus",true);
    }else {
        settings.setValue("autoModulus",false);
    }
    if(Qt::Checked == ui->checkBoxWriteIn->checkState()){
        settings.setValue("autoWriteIn",true);
    }else {
        settings.setValue("autoWriteIn",false);
    }
    settings.endGroup();

    int row = ui->tableViewDtr->model()->rowCount();
    if(!row){
        return;
    }

    QJsonArray arr;
    for(int i=row-1;i>=0;i--){
        QJsonArray arr1;
        arr1.append(m_pDtrmodel->item(i,0)->text().toFloat()); //距离
        arr1.append(m_pDtrmodel->item(i,1)->text().toInt());   //速度
        arr1.append(m_pDtrmodel->item(i,2)->text().toInt());   //方向
        arr.append(arr1);
    }

    QJsonDocument doc;

    doc.setArray(arr);
    QByteArray str = doc.toJson(QJsonDocument::Compact);


    QString jsonPath = QDir::currentPath() + "/dtr_config.json";
    QFile  file(jsonPath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        file.write(str);
        file.close();
    }

}

void tof_calibrt::on_btnReadLimitSig_clicked()
{
    GetDtrParm();
}

void tof_calibrt::on_btnPositionSetZero_clicked()
{
    bool flag;
    write_single_address  one_addr_write;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&one_addr_write.device_number);
    uint8_t func_code = WRITE_SINGLE_COIL_FUNC_CODE;
    one_addr_write.func_code = func_code;
    one_addr_write.start_div = ADDR_POS_SET_ZERO;
    one_addr_write.data = DATA_COIL_TURN_ON;
    one_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (one_addr_write) -2);
    flag = write_single_register(one_addr_write);
    if(!flag){
        QMessageBox::warning(this,QString("配置失败"),QString("坐标置0失败"),QMessageBox::Cancel);
        return;
    }
}

void tof_calibrt::on_btnFrontRun_clicked()
{
    bool flag;
    write_single_address  one_addr_write;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&one_addr_write.device_number);
    uint8_t func_code = WRITE_SINGLE_COIL_FUNC_CODE;
    one_addr_write.func_code = func_code;
    one_addr_write.start_div = ADDR_FORWARD_ROTATION;
    one_addr_write.data = DATA_COIL_TURN_ON;
    one_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (one_addr_write) -2);
    flag = write_single_register(one_addr_write);
    if(!flag){
        QMessageBox::warning(this,QString("配置失败"),QString("正转失败"),QMessageBox::Cancel);
        return;
    }
}

void tof_calibrt::on_btnBackRun_clicked()
{
    bool flag;
    write_single_address  one_addr_write;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&one_addr_write.device_number);
    uint8_t func_code = WRITE_SINGLE_COIL_FUNC_CODE;
    one_addr_write.func_code = func_code;
    one_addr_write.start_div = ADDR_REVEARSE_ROTATION;
    one_addr_write.data = DATA_COIL_TURN_ON;
    one_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (one_addr_write) -2);
    flag = write_single_register(one_addr_write);
    if(!flag){
        QMessageBox::warning(this,QString("配置失败"),QString("反转失败"),QMessageBox::Cancel);
        return;
    }
}

void tof_calibrt::on_btnDtrStop_clicked()
{
    bool flag;
    write_single_address  one_addr_write;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&one_addr_write.device_number);
    uint8_t func_code = WRITE_SINGLE_COIL_FUNC_CODE;
    one_addr_write.func_code = func_code;
    one_addr_write.start_div = ADDR_DTR_STOP;
    one_addr_write.data = DATA_COIL_TURN_ON;
    one_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (one_addr_write) -2);
    flag = write_single_register(one_addr_write);
    if(!flag){
        QMessageBox::warning(this,QString("配置失败"),QString("电机停止失败"),QMessageBox::Cancel);
        return;
    }
}

void tof_calibrt::on_btnReturnZeroPos_clicked()
{
    bool flag;
    write_single_address  one_addr_write;
    uint8_t* pHeader = reinterpret_cast<uint8_t *>(&one_addr_write.device_number);
    uint8_t func_code = WRITE_SINGLE_COIL_FUNC_CODE;
    one_addr_write.func_code = func_code;
    one_addr_write.start_div = ADDR_RETURN_ZERO_POS;
    one_addr_write.data = DATA_COIL_TURN_ON;
    one_addr_write.crc = pubFunc::CRC16_MODBUS(pHeader,sizeof (one_addr_write) -2);
    flag = write_single_register(one_addr_write);
    if(!flag){
        QMessageBox::warning(this,QString("配置失败"),QString("电机停止失败"),QMessageBox::Cancel);
        return;
    }

    m_read_timer->start(100);

}


void tof_calibrt::setDTRBtnStatus(bool status){
    QGroupBox *box = ui->groupBox_dtr_control;
    QPushButton *button;
    foreach(QObject *obj,box->children()){
        if(!obj->objectName().contains("btn"))
            continue;
        button = reinterpret_cast<QPushButton *>(obj);
        if(!button->accessibleName().contains("openDTR")){
            button->setEnabled(status);
        }
    }
}

void tof_calibrt::on_btnGetCurrentPos_clicked()
{
    read_current_pos(ui->lineCurrentPos);
}

void tof_calibrt::on_btntableDtrClear_clicked()
{
    int row  = ui->tableViewDtr->model()->rowCount();
    if (!row)
        ui->tableViewDtr->model()->removeRows(0,row);
}
