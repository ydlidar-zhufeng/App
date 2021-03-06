﻿#include "linefit.h"
#include <QDebug>
#if 1
LineFit::LineFit()
{

    //tof_data = new Tof_type;
}
LineFit::~LineFit()
{
   // delete tof_data ;
}
int LineFit::get_rows(int index)
{
    if(index < 5)
    {
        if(index == 3)//第3组 4个数据
        {
            return 4;
        }
        else// 1、2、4组 6个数据
        {
            return 6;
        }
    }
    return -1;
}

//线性拟合参数计算
 void LineFit::line_parameter_generate()
{
    rows = get_rows(index);

    #if 0
    MatrixXd X(rows,2);//peak
    MatrixXd Y(rows,1);//bias
    Matrix<double,2,1> RES;//结果
#else
    MatrixXd X(rows,2);//peak
    MatrixXd Y(rows,1);//bias
    Vector2d RES;//结果
    #endif
    //全部元素置1
    X = MatrixXd::Constant(rows,2,1);

    //数组转矩阵
    for(quint8 i = 0; i < rows; i++)
    {
        X(i,0) = tof_org[i].peak_value;//信号质量
        Y(i,0) = tof_org[i].tof_bias;//偏差
    }
    //拟合公式
    RES = (X.transpose() * X).inverse() * (X.transpose() * Y);

    tof_para[index - 1].line_A = RES[0] * 1000;
    tof_para[index - 1].line_B = RES[1] * 1000;
    //qDebug()<<"line_A:"<< QString::number(tof_para[index - 1].line_A) <<"line_B:" <<QString::number(tof_para[index - 1].line_B);
}
//阈值计算
void LineFit::thr_cal()
{
    //tof阈值
    int tof_thr = tof_org[tof_org.size()-2].tof_value * 1000;
    //peak 阈值
    int peak_thr = tof_org[tof_org.size() - 1].peak_value * 1000;
    foreach (Tof_type tem, tof_org) {
        if(tem.tof_value > tof_thr)
        {
            tof_thr = tem.tof_value * 1000;
        }
        if(tem.peak_value < peak_thr)
        {
            peak_thr = tem.peak_value *1000;
        }
    }

    tof_para[index - 1].tof_thr =tof_thr;//tof阈值
    tof_para[index - 1].peak_thr = peak_thr;//peak 阈值


    //qDebug()<<"tof_thr:"<< QString::number(tof_para[index - 1].tof_thr) <<"peak_thr:" <<QString::number(tof_para[index - 1].peak_thr);
}
#endif






