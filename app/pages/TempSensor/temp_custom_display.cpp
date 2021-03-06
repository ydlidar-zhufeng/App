﻿#include "temp_custom_display.h"
#include "ui_temp_custom_display.h"

TEMP_Custom_Display::TEMP_Custom_Display(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TEMP_Custom_Display)
{
    ui->setupUi(this);
    init();
}

TEMP_Custom_Display::~TEMP_Custom_Display()
{
    delete ui;
}


void TEMP_Custom_Display::init(){

    qRegisterMetaType<QVector<double>>("QVector<double>");
    qRegisterMetaType<QVector<double>>("QVector<double>&");
    qRegisterMetaType<float>("float&");
    ui->qcustomDisplay->xAxis->setRange(-100,100);
    ui->qcustomDisplay->yAxis->setRange(-4000,4000);
    ui->qcustomDisplay->legend->setVisible(true);  //右上角描叙点的对话框
    ui->qcustomDisplay->legend->setFont(QFont("Helvetica", 9));  //对话框中的字体
    ui->qcustomDisplay->legend->setRowSpacing(-3); //设置行间距
    ui->qcustomDisplay->setBackground(QColor("#1b252f"));

    //ui->qcustomDisplay->;
  //  this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
 //   ui->qcustomDisplay->setWindowTitle("保密监管预警系统-注册");
    //this->setWindowIcon(QIcon(":/image/blue2.png"));//这个都被隐藏了，他们属于系统边框

    // ui->qcustomDisplay->setAttribute(Qt::WA_TranslucentBackground);

//    label = new QLabel(ui->qcustomDisplay);
//    label->setGeometry(0,30,50,20);
//    label->setAttribute(Qt::WA_TranslucentBackground, false);
//    //Qt::WA_TranslucentBackground, false
//    label->setText("text");
  //  ui->qcustomDisplay->setWindowFlag();

    ui->qcustomDisplay->rescaleAxes(true);
    QVector<QCPScatterStyle::ScatterShape> shapes;
    QVector<QColor> colors;
    colors << Qt::blue;
    colors << Qt::red;

    shapes << QCPScatterStyle::ssDisc;
    shapes << QCPScatterStyle::ssDisc;


    QPen pen;
    // add graphs with different scatter styles:
    for (int i=0; i<shapes.size(); ++i)
    {
      ui->qcustomDisplay->addGraph();
      pen.setColor(colors.at(i));

      ui->qcustomDisplay->graph(i)->setPen(pen);
      ui->qcustomDisplay->graph(i)->setName(QCPScatterStyle::staticMetaObject.enumerator(QCPScatterStyle::staticMetaObject.indexOfEnumerator("ScatterShape")).valueToKey(shapes.at(i)));
      ui->qcustomDisplay->graph(i)->setLineStyle(QCPGraph::lsLine);
      // set scatter style:
      if (shapes.at(i) != QCPScatterStyle::ssCustom)
      {
        ui->qcustomDisplay->graph(i)->setScatterStyle(QCPScatterStyle(shapes.at(i), 4));
      }
      else
      {
        QPainterPath customScatterPath;
        for (int i=0; i<3; ++i)
          customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
        ui->qcustomDisplay->graph(i)->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(Qt::black, 0), QColor(255, 255, 255, 50), 10));
      }
    }
    ui->qcustomDisplay->graph(0)->setName("距离");
    ui->qcustomDisplay->graph(1)->setName("误差");
    ui->qcustomDisplay->setInteractions( QCP::iRangeZoom);//QCP::iRangeDrag |

    // set blank axis lines:
    ui->qcustomDisplay->rescaleAxes(true);
    ui->qcustomDisplay->xAxis->setTicks(true);

    ui->qcustomDisplay->xAxis->setTickLabelColor(QColor("#7d8ea0"));
    ui->qcustomDisplay->yAxis->setTickLabelColor(QColor("#7d8ea0"));
   // ui->qcustomDisplay->xAxis->setLayer("温度");
    ui->qcustomDisplay->yAxis->setTicks(true);
    ui->qcustomDisplay->xAxis->setTickLabels(true);
    ui->qcustomDisplay->yAxis->setTickLabels(true);
    // make top right axes clones of bottom left axes:
    ui->qcustomDisplay->axisRect()->setupFullAxesBox();

    connect(this,SIGNAL(sig_replotUi(QVariant&,QVariant&,QVariant&)),this,
            SLOT(slot_replotUi(QVariant&,QVariant&,QVariant&)),Qt::DirectConnection);
    connect(ui->btnmodulus,SIGNAL(clicked()),this,SLOT(slot_modulus_clicked()));
}


void TEMP_Custom_Display::slot_replotUi(QVariant& v1,QVariant& v2,QVariant& v3){
    QVector<double> vec_temp = v1.value<QVector<double>>();
    QVector<double> vec_devition = v2.value<QVector<double>>();
    QVector<double> vec_stddevit = v3.value<QVector<double>>();
    qDebug() << "size: temp<" << vec_temp.size() << ",devit<" << vec_devition.size() << ",std<" << vec_stddevit.size();

    ui->qcustomDisplay->graph(0)->data()->clear();
    ui->qcustomDisplay->graph(1)->data()->clear();

    ui->qcustomDisplay->graph(0)->setData(vec_temp,vec_devition );
    ui->qcustomDisplay->graph(1)->setData(vec_temp,vec_stddevit);
    ui->qcustomDisplay->replot(QCustomPlot::rpQueuedReplot);
}

void TEMP_Custom_Display::slot_modulus_clicked(){
    emit sig_modulus_clicked();
}

void TEMP_Custom_Display::setTempValue(QString temp){
    ui->lbltemperature->setText(temp);
}


void  TEMP_Custom_Display::setDistance(QString distance){
    ui->lbldistance->setText(distance);
}
void  TEMP_Custom_Display::setDeviation(QString deviation){
    ui->lbldeviation->setText(deviation);
}
void  TEMP_Custom_Display::setModulus(QString modulus){
    ui->lblcoefficient->setText(modulus);
}
void  TEMP_Custom_Display::setStdDeviation(QString stdDeviation){
    ui->lblstandrddeviation->setText(stdDeviation);
}
void  TEMP_Custom_Display::setRealDeviation(QString realDeviation){
    ui->lblrealDeviation->setText(realDeviation);
}

void  TEMP_Custom_Display::setLblText(QString coffi,QString devit){

        ui->lblcoefficient->setText(coffi);
        ui->lbldeviation->setText(devit);

}
