#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include "sliding_stacked_widget.h"
#include "pages/TempSensor/temp_sensor_page.h"
#include "pages/TofCalibrt/tof_calibrt.h"
#include <QLibrary>
//#include "TempCalibrt/tempcalibrt.h"
QT_BEGIN_NAMESPACE
//QLibrarydll("lidarTools.dll");
namespace Ui { class App; }

QT_END_NAMESPACE

class App : public QMainWindow
{
    Q_OBJECT
public:
    App(QWidget *parent = nullptr);
    ~App();
private slots:
    void on_btntofCalibrt_clicked();
    void slot1();
    void on_btnTempSensor_clicked();
signals:
    void closeSignal();

private:
    void  init();
    void pageClick(QWidget *widget, bool slide = true);
    void test1();
    void SetIcon(QLabel* lab, QChar c, int size = 10);
    void SetIcon(QPushButton* btn, QChar c, int size = 10, QString str="");

//    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
//    void mousePressEvent(QMouseEvent *e);
//    void mouseMoveEvent(QMouseEvent *e);
protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *event);

private:
    Ui::App *ui;
    SlidingStackedWidget  *mSlidingStacked;
    TempSensorPage  *tempSensorPage;
    tof_calibrt     *tofCalibrtPage;
    // Pages
    QList<QWidget*> mListPages;
    QList<QPushButton*> mListSidebarButtons;
    QFont   *iconFont;
    bool  m_bIsMax;

    int boundaryWidth;
    QPoint clickPos;

    QPoint mousePoint;
    QRect location;
    bool mousePressed;

    //Ui::Temp_Sensor_Settings *ss;

    //TempCalibrt *cal;
private slots:
    void closeMenuBntClicked();
    void minMenuBntClicked();
    void maxMenuBntClicked();
};
#endif // APP_H
