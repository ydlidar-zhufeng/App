@echo off
SetLocal EnableDelayedExpansion
(set QT_VERSION=0.3.0)
(set QT_VER=0.3)
(set QT_VERSION_TAG=030)
(set QT_INSTALL_DOCS=D:/QtCreator/Docs/Qt-5.13.2)
(set BUILDDIR=E:/code/QtXlsxWriter-master/QtXlsxWriter-master/src/xlsx)
D:\QtCreator\5.13.2\msvc2017_64\bin\qdoc.exe %*
EndLocal
