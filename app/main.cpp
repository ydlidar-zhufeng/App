﻿#include "app.h"
#include <QDateTime>
#include <QApplication>
#include <QDebug>
#include <QStandardPaths>
#include <QFile>
#include <QFontDatabase>
#include <QSplashScreen>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &message) //这里使用相应的qDebug(),qError等函数来触发
{
    Q_UNUSED(context)

    QString level;

    switch (type) {
    case QtDebugMsg:
        level = "DEBUG"; break;
    case QtInfoMsg:
        level = "INFO"; break;
    case QtWarningMsg:
        level = "WARNING"; break;
    case QtCriticalMsg:
        level = "CRITICAL"; break;
    case QtFatalMsg:
        level = "FATAL"; break;
    default:
        level = "UNDEFIEND"; break;
    }

    if (type != QtWarningMsg) {

        QString text = QString("[%1] [%2] [%3] [%4] [%5] %6")
                                .arg(QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss"))
                                .arg(context.file).arg(context.function).arg(context.line)
                                .arg(level)
                                .arg(message.constData());

        static QString logPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + "/stacer.log";
#ifndef unix
        logPath.replace(QRegExp("/"),"\\");
#endif

        qDebug() << "log_path:" << logPath;
        QFile file(logPath);

        QIODevice::OpenMode openMode = file.size() > (1L << 20) ? QIODevice::Truncate : QIODevice::Append;

        if (file.open(QIODevice::WriteOnly | openMode)) {
            QTextStream stream(&file);
            stream << text << endl;

            file.close();
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qApp->setApplicationName("stacer");
    qApp->setApplicationDisplayName("Stacer");
    qApp->setApplicationVersion("1.0.9");
    qApp->setWindowIcon(QIcon(":/static/logo.png")); //设置最小化托盘图标的logo

   // QFontDatabase::addApplicationFont(":/static/font/Ubuntu-R.ttf");

    QPixmap pixSplash(":/static/splashscreen.png");

    QSplashScreen *splash = new QSplashScreen(pixSplash);  //启动屏幕

    splash->show();

    app.processEvents();
    QString logPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
            qDebug() << "log_path:" << logPath;


  //  qInstallMessageHandler(messageHandler);
    App w;
    QLatin1String hideOption("--hide");

    if (argc < 2 || QString(argv[1]) != hideOption) {
        w.show();
    }
   // qDebug() << "test2";

    splash->finish(&w);

    delete splash;
    w.show();
    return app.exec();
}
