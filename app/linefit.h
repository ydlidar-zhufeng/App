﻿#ifndef LINEFIT_H
#define LINEFIT_H
//#include "mainwindow.h"
#include <QVector>
#include "Eigen/Core"
#include "Eigen/Dense"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
using namespace Eigen;

typedef struct
{
    //int index;
    double tof_value;
    double tof_bias;
    double peak_value;
}Tof_type;
typedef struct
{
    int tof_thr;
    int peak_thr;
    int line_A;
    int line_B;
}Fit_para_type;


//peak阈值计算参数
const int peak_para = 10;
#if 0
class Tof_type
{
public:
    ArrayXXd dis;
    ArrayXXd dis_bias;
    ArrayXXd peak;

    int get_rows(int index)//计算列数
    {
        if(index < 5)
        {
            if(index == 3)//第3组 4个数据
            {
                dis_bias.resize(4,1);
                dis.resize(4,1);
                peak.resize(4,1);
                return 4;
            }
            else// 1、2、4组 6个数据
            {
                dis_bias.resize(6,1);
                dis.resize(6,1);
                peak.resize(6,1);
                return 6;
            }
        }
        return -1;
    }
};
#endif
class LineFit
{
private:
    //Tof_type *tof_data;//包含4组中的一组数据
    int get_rows(int index);//计算列数

    int rows;
public:
    LineFit();
    ~LineFit();

    QVector<Tof_type> tof_org;//包含4组中的一组数据
    int index;//分组数
    Fit_para_type tof_para[4];////4组拟合参数

    void tof_original_data_change();
    void line_parameter_generate();

    void tof_bias_cal();
    void thr_cal();
};

#endif // LINEFIT_H
