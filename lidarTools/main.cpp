﻿#include <iostream>
#include "TempCalibrt/tempcalibrt.h"
#include <QDebug>
using namespace std;

int main()
{
    TempCalibrt *tcb = new TempCalibrt(NULL);
    tcb->port = myport::MySeriaPort::GetInstance();
    QStringList qlist = tcb->port->getPortnameList();
    qDebug() << "Hello World!" << endl;
    qDebug() << "ports:" << qlist;
    return 0;
}
