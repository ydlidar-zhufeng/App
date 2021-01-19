@echo off
SetLocal EnableDelayedExpansion
(set PATH=E:\code\QtXlsxWriter-master\QtXlsxWriter-master\bin;D:\QtCreator\5.13.2\msvc2017_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=D:\QtCreator\5.13.2\msvc2017_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=D:\QtCreator\5.13.2\msvc2017_64\plugins
)
%*
EndLocal
