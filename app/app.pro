QT       += core gui printsupport
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += -static

#LIBS += -L$$PWD\lib -llidarTools
LIBS += -L$$PWD\lib -llidarTools
INCLUDEPATH += $$PWD\..\lidarTools \
#DEPENDPATH += $$PWD\..\lidarTools \

INCLUDEPATH += \
    $$PWD\..\3rdParty\eigen-3.3.7
win32{
#LIBS +=-L$$PWD\lib -llidarTools
}
SOURCES += \
    CustomPlotTooltip.cpp \
    Managers/app_manager.cpp \
    feedback.cpp \
    main.cpp \
    app.cpp \
    newcombobox.cpp \
    pages/TempSensor/temp_custom_display.cpp \
    pages/TempSensor/temp_sensor_page.cpp \
    pages/TempSensor/temp_sensor_settings.cpp \
    pages/TofCalibrt/tof_calibrt.cpp \
    qcustomplot.cpp \
    signal_mapper.cpp \
    sliding_stacked_widget.cpp

HEADERS += \
    CustomPlotTooltip.h \
    Managers/app_manager.h \
    app.h \
    feedback.h \
    newcombobox.h \
    pages/TempSensor/temp_custom_display.h \
    pages/TempSensor/temp_sensor_page.h \
    pages/TempSensor/temp_sensor_settings.h \
    pages/TofCalibrt/tof_calibrt.h \
    qcustomplot.h \
    signal_mapper.h \
    sliding_stacked_widget.h \
    utilities.h

FORMS += \
    app.ui \
    feedback.ui \
    pages/TempSensor/temp_custom_display.ui \
    pages/TempSensor/temp_sensor_page.ui \
    pages/TempSensor/temp_sensor_settings.ui \
    pages/TofCalibrt/tof_calibrt.ui

include(../3rdParty/qtxlsx/src/xlsx/qtxlsx.pri)

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    static.qrc
