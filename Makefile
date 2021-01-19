#############################################################################
# Makefile for building: App
# Generated by qmake (3.1) (Qt 5.13.2)
# Project:  App.pro
# Template: subdirs
# Command: D:\qt\Qt5.13.2\5.13.2\msvc2017_64\bin\qmake.exe -o Makefile App.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

EQ            = =

first: make_first
QMAKE         = D:\qt\Qt5.13.2\5.13.2\msvc2017_64\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = D:\qt\Qt5.13.2\5.13.2\msvc2017_64\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = D:\qt\Qt5.13.2\5.13.2\msvc2017_64\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		sub-lidarTools \
		sub-app


sub-lidarTools-qmake_all:  FORCE
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	cd lidarTools\ && $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && $(MAKE) -f Makefile qmake_all
sub-lidarTools: $(MAKEFILE) FORCE
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile
sub-lidarTools-make_first: FORCE
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile 
sub-lidarTools-all: FORCE
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile all
sub-lidarTools-clean: FORCE
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile clean
sub-lidarTools-distclean: FORCE
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile distclean
sub-lidarTools-install_subtargets: FORCE
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile install
sub-lidarTools-uninstall_subtargets: FORCE
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile uninstall
sub-app-qmake_all:  FORCE
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	cd app\ && $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && $(MAKE) -f Makefile qmake_all
sub-app: $(MAKEFILE) FORCE
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile
sub-app-make_first: FORCE
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile 
sub-app-all: FORCE
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile all
sub-app-clean: FORCE
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile clean
sub-app-distclean: FORCE
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile distclean
sub-app-install_subtargets: FORCE
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile install
sub-app-uninstall_subtargets: FORCE
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile uninstall

Makefile: App.pro D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\win32-msvc\qmake.conf D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\spec_pre.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\common\angle.conf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\common\windows-desktop.conf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\win32\windows_vulkan_sdk.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\common\windows-vulkan.conf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\common\msvc-desktop.conf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\qconfig.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3danimation.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3danimation_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dcore.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dcore_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dextras.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dextras_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dinput.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dinput_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dlogic.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dlogic_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquick.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquick_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickanimation.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickanimation_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickextras.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickextras_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickinput.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickinput_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickrender.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickrender_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickscene2d.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickscene2d_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3drender.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3drender_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_accessibility_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axbase.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axbase_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axcontainer.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axcontainer_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axserver.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axserver_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_bluetooth.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_bluetooth_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_bootstrap_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_charts.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_charts_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_concurrent.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_concurrent_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_core.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_core_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_datavisualization.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_datavisualization_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_dbus.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_dbus_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_designer.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_designer_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_designercomponents_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_devicediscovery_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_edid_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_egl_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_eventdispatcher_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_fb_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_fontdatabase_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_gamepad.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_gamepad_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_gui.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_gui_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_help.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_help_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_location.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_location_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_multimedia.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_multimedia_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_multimediawidgets.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_network.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_network_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_networkauth.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_networkauth_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_nfc.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_nfc_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_opengl.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_opengl_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_openglextensions.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_openglextensions_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_packetprotocol_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_platformcompositor_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_positioning.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_positioning_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_positioningquick.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_positioningquick_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_printsupport.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_printsupport_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_purchasing.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_purchasing_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qml.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qml_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qmldebug_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qmltest.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qmltest_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quick.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quick_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickcontrols2.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickcontrols2_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickparticles_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickshapes_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quicktemplates2.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quicktemplates2_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickwidgets.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_remoteobjects.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_remoteobjects_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_repparser.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_repparser_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_script.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_script_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_scripttools.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_scripttools_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_scxml.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_scxml_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_sensors.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_sensors_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_serialbus.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_serialbus_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_serialport.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_serialport_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_sql.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_sql_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_svg.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_svg_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_testlib.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_testlib_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_texttospeech.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_texttospeech_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_theme_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_uiplugin.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_uitools.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_uitools_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_vulkan_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webchannel.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webchannel_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webengine.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webengine_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webenginecore.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webenginecore_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webenginewidgets.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_websockets.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_websockets_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webview.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webview_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_widgets.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_widgets_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_windowsuiautomation_support_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_winextras.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_winextras_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_xml.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_xml_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_xmlpatterns.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_zlib_private.pri \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\qt_functions.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\qt_config.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\win32-msvc\qmake.conf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\spec_post.prf \
		.qmake.stash \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\exclusive_builds.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\common\msvc-version.conf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\toolchain.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\default_pre.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\win32\default_pre.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\resolve_config.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\exclusive_builds_post.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\default_post.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\qml_debug.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\precompile_header.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\warn_on.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\qmake_use.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\file_copies.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\win32\windows.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\testcase_targets.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\exceptions.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\yacc.prf \
		D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\lex.prf \
		App.pro
	$(QMAKE) -o Makefile App.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\spec_pre.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\common\angle.conf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\common\windows-desktop.conf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\win32\windows_vulkan_sdk.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\common\windows-vulkan.conf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\common\msvc-desktop.conf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\qconfig.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3danimation.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3danimation_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dcore.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dcore_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dextras.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dextras_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dinput.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dinput_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dlogic.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dlogic_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquick.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquick_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickanimation.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickanimation_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickextras.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickextras_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickinput.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickinput_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickrender.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickrender_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickscene2d.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3dquickscene2d_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3drender.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_3drender_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_accessibility_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axbase.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axbase_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axcontainer.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axcontainer_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axserver.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_axserver_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_bluetooth.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_bluetooth_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_bootstrap_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_charts.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_charts_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_concurrent.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_concurrent_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_core.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_core_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_datavisualization.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_datavisualization_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_dbus.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_dbus_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_designer.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_designer_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_designercomponents_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_devicediscovery_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_edid_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_egl_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_eventdispatcher_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_fb_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_fontdatabase_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_gamepad.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_gamepad_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_gui.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_gui_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_help.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_help_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_location.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_location_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_multimedia.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_multimedia_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_multimediawidgets.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_network.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_network_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_networkauth.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_networkauth_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_nfc.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_nfc_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_opengl.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_opengl_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_openglextensions.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_openglextensions_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_packetprotocol_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_platformcompositor_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_positioning.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_positioning_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_positioningquick.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_positioningquick_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_printsupport.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_printsupport_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_purchasing.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_purchasing_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qml.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qml_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qmldebug_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qmldevtools_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qmltest.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qmltest_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quick.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quick_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickcontrols2.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickcontrols2_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickparticles_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickshapes_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quicktemplates2.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quicktemplates2_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickwidgets.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_quickwidgets_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_remoteobjects.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_remoteobjects_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_repparser.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_repparser_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_script.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_script_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_scripttools.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_scripttools_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_scxml.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_scxml_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_sensors.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_sensors_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_serialbus.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_serialbus_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_serialport.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_serialport_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_sql.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_sql_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_svg.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_svg_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_testlib.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_testlib_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_texttospeech.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_texttospeech_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_theme_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_uiplugin.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_uitools.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_uitools_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_vulkan_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webchannel.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webchannel_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webengine.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webengine_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webenginecore.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webenginecore_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webenginewidgets.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_websockets.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_websockets_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webview.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_webview_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_widgets.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_widgets_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_windowsuiautomation_support_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_winextras.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_winextras_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_xml.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_xml_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_xmlpatterns.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\modules\qt_lib_zlib_private.pri:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\qt_functions.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\qt_config.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\win32-msvc\qmake.conf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\spec_post.prf:
.qmake.stash:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\exclusive_builds.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\common\msvc-version.conf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\toolchain.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\default_pre.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\win32\default_pre.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\resolve_config.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\exclusive_builds_post.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\default_post.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\qml_debug.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\precompile_header.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\warn_on.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\qmake_use.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\file_copies.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\win32\windows.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\testcase_targets.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\exceptions.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\yacc.prf:
D:\qt\Qt5.13.2\5.13.2\msvc2017_64\mkspecs\features\lex.prf:
App.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile App.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: sub-lidarTools-qmake_all sub-app-qmake_all FORCE

make_first: sub-lidarTools-make_first sub-app-make_first  FORCE
all: sub-lidarTools-all sub-app-all  FORCE
clean: sub-lidarTools-clean sub-app-clean  FORCE
distclean: sub-lidarTools-distclean sub-app-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash
install_subtargets: sub-lidarTools-install_subtargets sub-app-install_subtargets FORCE
uninstall_subtargets: sub-lidarTools-uninstall_subtargets sub-app-uninstall_subtargets FORCE

sub-lidarTools-debug:
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile debug
sub-app-debug:
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile debug
debug: sub-lidarTools-debug sub-app-debug

sub-lidarTools-release:
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile release
sub-app-release:
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile release
release: sub-lidarTools-release sub-app-release

sub-lidarTools-check:
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile check
sub-app-check:
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile check
check: sub-lidarTools-check sub-app-check

sub-lidarTools-benchmark:
	@if not exist lidarTools\ mkdir lidarTools\ & if not exist lidarTools\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd lidarTools\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\lidarTools\lidarTools.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile benchmark
sub-app-benchmark:
	@if not exist app\ mkdir app\ & if not exist app\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd app\ && ( if not exist Makefile $(QMAKE) -o Makefile E:\code\App\app\app.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug" ) && $(MAKE) -f Makefile benchmark
benchmark: sub-lidarTools-benchmark sub-app-benchmark
install:install_subtargets  FORCE

uninstall: uninstall_subtargets FORCE

FORCE:
