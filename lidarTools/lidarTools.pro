TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT += core printsupport serialport
TEMPLATE = lib
TARGET = lidarTools
CONFIG += static

DEFINES += QT_DEPRECATED_WARNINGS
SOURCES += \
        DistanceCalibrt/distancecalibrt.cpp \
        DistanceCalibrt/machinecontrl.cpp \
        TempCalibrt/tempcalibrt.cpp \
        myseriaport.cpp

DESTDIR = $$PWD\..\app\lib
#E:\code\App\lidarTools\bin

HEADERS += \
    DistanceCalibrt/distancecalibrt.h \
    DistanceCalibrt/machinecontrl.h \
    TempCalibrt/tempcalibrt.h \
    config.h \
    myseriaport.h
#DEFINES += QT_NO_DEBUG_OUTPUT


