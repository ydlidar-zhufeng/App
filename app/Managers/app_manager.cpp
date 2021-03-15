#include "app_manager.h"
#include <QDebug>
#include <QFile>

AppManager *AppManager::instance = nullptr;

AppManager *AppManager::ins()
{
    if (! instance) {
        instance = new AppManager;
    }

    return instance;
}

AppManager::AppManager()
{


    mTrayIcon = new QSystemTrayIcon(QIcon(":/static/logo.png"));

    loadLanguageList();

    loadThemeList();

}

QSystemTrayIcon *AppManager::getTrayIcon()
{
    return mTrayIcon;
}

QSettings *AppManager::getStyleValues() const
{
    return mStyleValues;
}

void AppManager::loadLanguageList()
{
    QByteArray lanuagesJson = AppManager::readStringFromFile(":/static/languages.json").toUtf8();
    QJsonArray lanuages = QJsonDocument::fromJson(lanuagesJson).array();

    for (int i = 0; i < lanuages.count(); ++i) {

        QJsonObject ob = lanuages.at(i).toObject();

        mLanguageList.insert(ob["value"].toString(), ob["text"].toString());
    }
}

QMap<QString, QString> AppManager::getLanguageList() const
{
    return mLanguageList;
}

void AppManager::loadThemeList()
{
    QByteArray themesJson = AppManager::readStringFromFile(":/static/themes.json").toUtf8();
    QJsonArray themes = QJsonDocument::fromJson(themesJson).array();

    for (int i = 0; i < themes.count(); ++i) {

        QJsonObject ob = themes.at(i).toObject();

        mThemeList.insert(ob["value"].toString(), ob["text"].toString());
    }
}

QMap<QString, QString> AppManager::getThemeList() const
{
    return mThemeList;
}

void AppManager::updateStylesheet()
{
    QString appThemePath = QString(":/static/themes/%1/style").arg("default"); //mSettingManager->getThemeName()
    mStyleValues = new QSettings(QString("%1/values.ini").arg(appThemePath), QSettings::IniFormat);

    mStylesheetFileContent = AppManager::readStringFromFile(QString("%1/style.qss").arg(appThemePath),QIODevice::ReadOnly);

    // set values example: @color01 => #fff
    for (const QString &key : mStyleValues->allKeys()) {
        mStylesheetFileContent.replace(key, mStyleValues->value(key).toString());
    }

    qApp->setStyleSheet(mStylesheetFileContent);

    emit SignalMapper::ins()->sigChangedAppTheme();
}

QString AppManager::getStylesheetFileContent() const
{
    return mStylesheetFileContent;
}


QString AppManager::readStringFromFile(const QString &path, const QIODevice::OpenMode &mode)
{
    QSharedPointer<QFile> file(new QFile(path));

    QString data;

    if(file->open(mode)) {

      data = file->readAll();

      file->close();
    }

    return data;
}
