#include "temp_sensor_page.h"
#include "ui_temp_sensor_page.h"
#include "utilities.h"
#include "myseriaport.h"
#include <QDebug>
#include <QMessageBox>
#include "config.h"
#include "xlsxdocument.h"
#include "xlsxworkbook.h"
#include <QFileDialog>
#include <QCoreApplication>
#include <QVariant>
#include "Eigen/Core"
#include "Eigen/Dense"
using namespace Eigen;

const QString defaultFileNmme = "tempSensor.xlsx";
TempSensorPage::TempSensorPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TempSensorPage),
    slidingStackedWidget(new SlidingStackedWidget(this)),
    status(false),p_timer(new QTimer(this)),fileNum(0)
{
    ui->setupUi(this);
    vec_temp.resize(DefaultVectorSize);
    vec_dist.resize(DefaultVectorSize);
    vec_stddevit.resize(DefaultVectorSize);
    vec_devit.resize(DefaultVectorSize);

    clear_vector();
    qDebug() << "主线程:" << QThread::currentThread();

    init();
    initConnect();
    fileStatus = false;
}

TempSensorPage::~TempSensorPage()
{

    delete ui;
    emit destroyed();
    //terminate();
}

void TempSensorPage::init(){

   ui->contentGridLayout->addWidget(slidingStackedWidget, 1, 0, 1, 1);
   tempSensorSettings = new Temp_Sensor_Settings(slidingStackedWidget);
   tempCustomDisplay  = new TEMP_Custom_Display(slidingStackedWidget);

   slidingStackedWidget->addWidget(tempCustomDisplay);
   slidingStackedWidget->addWidget(tempSensorSettings);

   QList<QWidget*> widgets = {ui->btnCustomDisplay,ui->btnTempSettings};
   Utilities::addDropShadow(widgets,40);
}

void TempSensorPage::initConnect(){

    connect(tempSensorSettings,SIGNAL(sig_getports(QStringList&)),this,SLOT(getPortNames(QStringList&)),Qt::DirectConnection);
    connect(tempSensorSettings,SIGNAL(sig_open_clicked()),this,SLOT(slot_open_clicked()),Qt::DirectConnection);
    connect(tempSensorSettings,SIGNAL(sig_send_clicked()),this,SLOT(slot_send_clicked()));
    connect(tempSensorSettings,SIGNAL(sig_save_clicked()),this,SLOT(slot_save_clicked()),Qt::DirectConnection);
    connect(this,SIGNAL(sig_stop_clicked()),this,SLOT(slot_stop_clicked()));
    connect(tempSensorSettings,SIGNAL(sig_stop_clicked()),this,SLOT(slot_stop_clicked()));
    connect(p_timer, SIGNAL(timeout()), this, SLOT(slot_handle_timeout()));

    connect(this,SIGNAL(sig_stop_clicked()),this,SLOT(slot_stop_clicked()));
        // m_pTimer->start(timeout);
    p_thread = new QThread();
    p_thread->start();

    p_tempcalibrt = new TempCalibrt(nullptr);

    p_tempcalibrt->moveToThread(p_thread);
    connect(this,&TempSensorPage::sig_open,p_tempcalibrt,&TempCalibrt::open,Qt::BlockingQueuedConnection);
    connect(this,&TempSensorPage::sig_startDistanceScan,p_tempcalibrt,&TempCalibrt::startDistanceScan,Qt::BlockingQueuedConnection);
    connect(this,&TempSensorPage::sig_getTempValue,p_tempcalibrt,&TempCalibrt::getTempValue,Qt::BlockingQueuedConnection);
    connect(this,&TempSensorPage::sig_stopScanDistance,p_tempcalibrt,&TempCalibrt::stopScanDistance,Qt::BlockingQueuedConnection);
    connect(this,&TempSensorPage::sig_close,p_tempcalibrt,&TempCalibrt::close,Qt::BlockingQueuedConnection);
    connect(this,&TempSensorPage::sig_sendInfo,p_tempcalibrt,&TempCalibrt::sendInfo,Qt::BlockingQueuedConnection);
    connect(this,&TempSensorPage::sig_flushReadCache,p_tempcalibrt,&TempCalibrt::flushReadCache,Qt::BlockingQueuedConnection);
    connect(this,&TempSensorPage::sig_waitForData,p_tempcalibrt,&TempCalibrt::waitForData,Qt::BlockingQueuedConnection);
    connect(this,&TempSensorPage::sig_getPortnameList,p_tempcalibrt,&TempCalibrt::getPortnameList,Qt::BlockingQueuedConnection);
    connect(this,&TempSensorPage::sig_getValidSize,p_tempcalibrt,&TempCalibrt::getValidSize,Qt::BlockingQueuedConnection);
    connect(this,&TempSensorPage::sig_getOpenStatus,p_tempcalibrt,&TempCalibrt::getOpenStatus,Qt::BlockingQueuedConnection);

    this->showMaximized();

    connect(tempCustomDisplay,SIGNAL(sig_modulus_clicked()),this,SLOT(slot_modulus_clicked()),Qt::DirectConnection);



    QStringList qlist;
    emit sig_getPortnameList(qlist);
    tempSensorSettings->setCombPortName(qlist);
}


void TempSensorPage::clear_vector(){
    vec_devit.clear();
    vec_temp.clear();
    vec_dist.clear();
    vec_stddevit.clear();
}

void TempSensorPage::getPortNames(QStringList& qlist){
    qDebug() << "getPortNames";
    emit sig_getPortnameList(qlist);
}

void TempSensorPage::slot_open_clicked(){
    qDebug() << "page_open_thread:" << QThread::currentThreadId();
    if(!status){
        qDebug() << "control_open";
        QString portname;
        int baudrate = 0;
        tempSensorSettings->getCombPortName(portname);
        tempSensorSettings->getCombBaudrate(baudrate);
        if (portname == "" || baudrate == 0){
            QMessageBox::warning(tempSensorSettings,"error","串口或波特率为空");
            return;
            //portname = "COM3";
        }


        qDebug() << "port:" << portname << ",baudrate:" << baudrate;
        bool isOk = false;
        emit sig_open(isOk,baudrate,portname);
        if(!isOk){
            qDebug() << "open failed";
            QMessageBox::warning(tempSensorSettings,"error","串口打开失败");
            return;
        }
        qDebug() << "testConnect";
        QByteArray  arr;
        arr.resize(2);
        arr[0] = 0xa5;
        arr[1] = 0x65;
        emit sig_sendInfo(isOk,arr.data(),2);
        emit sig_flushReadCache();
        if(!testConnect()){
            return;
        }
        qDebug() << "getTempValue";
        float temp;
        emit sig_getTempValue(temp,isOk);
        if(!isOk){
            QMessageBox::warning(this,"错误","A获取温度失败");
            return;
        }
        tempCustomDisplay->setTempValue(QString("%1").arg(temp));
        refValue = temp*100;

        tempSensorSettings->getStandardValue(stdValue);
        if(!stdValue){
            stdValue = 3000;
        }
        tempSensorSettings->setContrlBtnText(false);
        status = true;
        return;
    }

   qDebug() << "开始关闭";
    emit sig_close();
    status = false;
    tempSensorSettings->setContrlBtnText(true);
}

void TempSensorPage::slot_send_clicked(){
    qDebug() << "进入send槽2";
    if(!status){
        QMessageBox::warning(tempSensorSettings,"error","串口未打开");
        return;
    }
    int interval = 0;
    tempSensorSettings->getScanIntervalTime(interval);
    if(interval==0 && interval <100){
        interval = 1000;
        if(interval >0)
            interval = 100;
    }
    p_timer->start(interval);
}

void TempSensorPage::slot_stop_clicked(){
    p_timer->stop();
}

bool TempSensorPage::testConnect(){

    bool isOk = false;
    emit sig_getOpenStatus(isOk);
//    isOk = p_tempcalibrt->port->isOpen();
    if(!isOk){
        QMessageBox::warning(tempSensorSettings,"error","串口未打开");
        return false;
    }

    emit sig_flushReadCache();
    QByteArray arr;
    arr.resize(2);
    arr[0] = 0xa5;arr[1] = 0xad;
    emit sig_sendInfo(isOk,arr.data(),2);

    if(!isOk){
        qDebug() << "test_connect_1";
        QMessageBox::warning(tempSensorSettings,"error",QString("串口发送%1指令失败").arg(arr.data()));
        return false;
    }
    int count = 10;
    qDebug() << "test_connect_2";
    emit sig_waitForData(isOk,count,DefaultTimeout);
    qDebug() << "test_connect_3";

    if(!isOk){
        QMessageBox::warning(tempSensorSettings,"error",QString("串口配置信息错误"));
        return false;
    }
    return true;

}

void TempSensorPage::slot_save_clicked(){
    QString excelPath;
    if(fileStatus ==true){
        QString dir = QCoreApplication::applicationDirPath();
        excelPath = QString("%1\\%2%3").arg(dir).arg(defaultFileNmme).arg(fileNum);
        fileNum++;
        fileStatus = false;
    }else{
        excelPath = QFileDialog::getSaveFileName(this,"输出文件选择",".",tr("file (*.xlsx  *.xls)"));
    }

    //excelPath = "/root/scan.xlsx";
    if(excelPath == ""){
        qDebug() << "excel path is empth or qmap is empty!";
        return;
    }
    QFile::remove(excelPath);
    QXlsx::Document xlsx(excelPath);//打开需要打开的excel文件，filePath为打开的文件名

    xlsx.setColumnWidth(1,15);
    xlsx.setColumnWidth(2,15);
    xlsx.setColumnWidth(3,15);

    xlsx.write(1,1,"温度");
    xlsx.write(1,2,"距离");
    xlsx.write(1,3,"标准差");
    xlsx.write(1,4,"误差");

    if(stdValue ==0){
        stdValue = 3000;
    }
    for(int i =0;i<vec_temp.size();i++){
        xlsx.write(i+2,1,QString("%1").arg(vec_temp[i]));
        xlsx.write(i+2,2,vec_dist[i]);
        xlsx.write(i+2,3,vec_stddevit[i]);
        xlsx.write(i+2,4,vec_dist[i] - stdValue);
    }

    xlsx.saveAs(excelPath);//写完之后一定要保存
}

void TempSensorPage::on_btnTempSettings_clicked()
{
    slidingStackedWidget->slideInIdx(slidingStackedWidget->indexOf(tempSensorSettings));
}

void TempSensorPage::on_btnCustomDisplay_clicked()
{
    slidingStackedWidget->slideInIdx(slidingStackedWidget->indexOf(tempCustomDisplay));
}

void TempSensorPage::slot_handle_timeout(){
    float temp;
    bool isOk = false;
    emit sig_getTempValue(temp,isOk,DefaultTimeout);
    if(!isOk){
        QMessageBox::warning(this,"错误","B获取温度失败");
        emit sig_stop_clicked();
        return;
    }
    qDebug() << "temp:" << temp;
    QString strtemp = QString("%1").arg(temp);
    tempCustomDisplay->setTempValue(strtemp);
    if(temp*100 - refValue >TemperatureDiff){
        float distance,devit;
        emit sig_startDistanceScan(distance,devit);
        if(vec_temp.size() >=1000){
            qWarning() << "开始情况向量";
           fileStatus = true;
           slot_save_clicked();
           clear_vector();
        }
        vec_dist.append(distance);
        int realDevit = distance - stdValue;
        vec_devit.append(realDevit);
        vec_temp.append(temp);
        vec_stddevit.append(devit);
        QVariant v1,v2,v3;
        v1.setValue(vec_temp);
        v2.setValue(vec_devit);
        v3.setValue(vec_stddevit);
        qDebug() << "size:" << vec_temp.size();
        tempCustomDisplay->setDistance(QString("%1").arg(distance));
        tempCustomDisplay->setRealDeviation(QString("%1").arg(realDevit));
        tempCustomDisplay->setStdDeviation(QString("%1").arg(devit));
        refValue = temp * 100;
        emit  tempCustomDisplay->sig_replotUi(v1,v2,v3);
    }

}


void TempSensorPage::readXlsx(QString fileName,QVector<double>& vec_temp,QVector<double>& vec_devit){
   //打开需要打开的excel文件，filePath为打开的文件名
    QXlsx::Document xlsx(fileName);
    QXlsx::Workbook *workBook = xlsx.workbook();
    QXlsx::Worksheet *workSheet = static_cast<QXlsx::Worksheet*>(workBook->sheet(0));//第一个标签页
    qDebug() << workBook->sheet(0)->sheetName();
    int rowCount = workSheet->dimension().rowCount();
    if(rowCount >= 1000){
        rowCount = 1000;
    }
    qDebug() << "rowCount" << rowCount;
    double temp;
    for (int i = 1; i <= rowCount; i++)
    {
        if(i == 1){
            continue;
        }
        QXlsx::Cell *cell = workSheet->cellAt(i, 1);
        if(cell ==0){

            qDebug() << QString("当前%1行第1列为空").arg(i+1);
            continue;
        }
         qDebug() << i <<":1" << cell->value().toDouble();
        temp =cell->value().toDouble();

        //temp = cell->value().toString();

        cell = workSheet->cellAt(i, 4);
        if(cell ==0){
            qDebug() << QString("当前%1行第4列为空").arg(i+1);
            continue;
        }
        qDebug() << i <<":4" << cell->value().toDouble();
        vec_temp.append(temp);
        vec_devit.append(cell->value().toDouble());
        //value = cell->value().toString();
    }
}


void TempSensorPage::slot_modulus_clicked(){
    QString filename = QFileDialog::getOpenFileName(this,"输出文件选择",".",tr("file (*.xlsx  *.xls)"));
    if(filename == ""){
        return;
    }
    QVector<double> a,b;
    a.resize(1000);
    b.resize(1000);
    a.clear();
    b.clear();
    readXlsx(filename,a,b);
    int rows = b.size();
    if(rows <=5){
        QMessageBox::warning(this,"error","excel必须有5行有效数据");
        return;
    }
    MatrixXd X(rows,2);//peak
    MatrixXd Y(rows,1);//bias
    Vector2d RES;//结果

    //全部元素置1
    X = MatrixXd::Constant(rows,2,1);

    //数组转矩阵
    for(quint8 i = 0; i < rows; i++)
    {
        X(i,0) = a[i];//信号质量
        Y(i,0) = b[i];//偏差
    }
    //拟合公式
    RES = (X.transpose() * X).inverse() * (X.transpose() * Y);
    tempCustomDisplay->setLblText(QString("%1").arg(RES[0]),QString("%1").arg(RES[1]));


}
