﻿#ifndef TEMP_CUSTOM_DISPLAY_H
#define TEMP_CUSTOM_DISPLAY_H

#include <QWidget>
#include "qcustomplot.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


namespace Ui {
class TEMP_Custom_Display;
}

class TEMP_Custom_Display : public QWidget
{
    Q_OBJECT

public:
    enum  LabelType{
        Coffi,
        Devit
    };
    explicit TEMP_Custom_Display(QWidget *parent = nullptr);
    ~TEMP_Custom_Display();
    void  setTempValue(QString temp);
    void  setDistance(QString distance);
    void  setDeviation(QString deviation);
    void  setModulus(QString modulus);
    void  setStdDeviation(QString stdDeviation);
    void setRealDeviation(QString realDeviation);
    void  setLblText(QString coffi,QString devit);
private slots:
    void  slot_replotUi(QVariant& v1,QVariant& v2,QVariant& v3);
    void  slot_modulus_clicked();
private:
    void init();
signals:
    void sig_replotUi(QVariant& v1,QVariant& v2,QVariant& v3);
    void  sig_modulus_clicked();

private:
    Ui::TEMP_Custom_Display *ui;
};

Q_DECLARE_METATYPE(QVector<double>);

#endif // TEMP_CUSTOM_DISPLAY_H
