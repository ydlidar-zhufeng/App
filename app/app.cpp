#include "app.h"
#include "ui_app.h"
#include <QStyle>
#include <QDesktopWidget>
#include "utilities.h"
#include <QDebug>
#include "Managers/app_manager.h"
#include <QFont>
#include <Windows.h>
#include <windowsx.h>
#include <QMoveEvent>
const int MenuWidgetWidth = 30;
const int MenuWidgetHeight = 30;

App::App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::App)
    , mSlidingStacked(new SlidingStackedWidget(this))
    , m_bIsMax(false)
{
    ui->setupUi(this);
    mousePressed = false;
    qRegisterMetaType<bool>("bool&");
    init();


}

App::~App()
{
    delete ui;
}

void App::test1(){

}

void App::init(){
//    setGeometry(
//        QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter      //第一个参数是文本显示方式，第二个参数是对齐方式，
//          ,size(),qApp->desktop()->QDesktopWidget::availableGeometry(this)));
     //this->showNormal();
 //setWindowFlags(Qt::CustomizeWindowHint);
      ///> form  settings
      ///

    this->setMinimumSize(45,45);                        //设置最小尺寸
 //   this->setStyleSheet("background:#D1EEEE");
    boundaryWidth=4;
    int fontId = QFontDatabase::addApplicationFont(":/static/font/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconFont = new QFont(fontName);
    QHBoxLayout* menuLayout = new QHBoxLayout;
    menuLayout->setMargin(0);
    menuLayout->setSpacing(0);
    menuLayout->addStretch();

    QPushButton* minBnt = new QPushButton;
    minBnt->setProperty("flag", "menu");
    SetIcon(minBnt, 0x2d,20);//0xf068
    minBnt->setFixedSize(MenuWidgetWidth, MenuWidgetHeight);
    connect(minBnt, SIGNAL(clicked()), this, SLOT(minMenuBntClicked()));
    QPushButton* maxBnt = new QPushButton;
    maxBnt->setProperty("flag", "menu");
    SetIcon(maxBnt, 0x2b,20); //0xf067
    maxBnt->setFixedSize(MenuWidgetWidth, MenuWidgetHeight);
    connect(maxBnt, SIGNAL(clicked()), this, SLOT(maxMenuBntClicked()));
    QPushButton* cloBnt = new QPushButton;
    cloBnt->setProperty("flag", "menu");
    SetIcon(cloBnt, QChar(0x78), 20); //f00d
    cloBnt->setFixedSize(MenuWidgetWidth, MenuWidgetHeight);
    connect(cloBnt, SIGNAL(clicked()), this, SLOT(closeMenuBntClicked()));
    menuLayout->addWidget(minBnt);
    menuLayout->addWidget(maxBnt);
    menuLayout->addWidget(cloBnt);
    ui->menu_widget->setLayout(menuLayout);
    ui->menu_widget->setStyleSheet("background:#D1EEEE");
   // bodyLayout->addWidget(menuWidget);


    this->setWindowFlags(Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_AlwaysShowToolTips);
    ui->gridLayout->setContentsMargins(0,0,0,0);
    ui->gridLayout->setSpacing(0);

    tempSensorPage = new TempSensorPage(mSlidingStacked);
    tofCalibrtPage = new tof_calibrt(mSlidingStacked);

    ui->pageContentLayout->addWidget(mSlidingStacked);

    mListPages = {
     tempSensorPage,tofCalibrtPage
    };

    mListSidebarButtons = {
     ui->btnTempSensor, ui->btntofCalibrt //
    };

    for(QWidget *page: mListPages) {
      mSlidingStacked->addWidget(page);
    }
    //  pageClick(tempSensorPage,true);
    AppManager::ins()->updateStylesheet();
    //  this->show();

    Utilities::addDropShadow(ui->sidebar, 60);
    pageClick(tempSensorPage);

    activateWindow();

}

void App::slot1(){
    qDebug() << "退出前";
}

void App::pageClick(QWidget *widget, bool slide)
{
    if (widget) {
        ui->pageTitle->setText(widget->windowTitle());
        if (slide) {
            mSlidingStacked->slideInIdx(mSlidingStacked->indexOf(widget));
        } else {
            mSlidingStacked->setCurrentWidget(widget);
        }
    }
}

void App::on_btntofCalibrt_clicked()
{
    pageClick(tofCalibrtPage);
}

void App::on_btnTempSensor_clicked()
{
    pageClick(tempSensorPage);
}



void App::SetIcon(QLabel *lab, QChar c, int size)
{
    iconFont->setPointSize(size);
    lab->setFont(*iconFont);
    lab->setText(c);
}

void App::SetIcon(QPushButton *btn, QChar c, int size, QString str)
{
    iconFont->setPointSize(size);
    btn->setFont(*iconFont);
    if(str.isEmpty())
        btn->setText(c);
    else {
        btn->setText(QString("%1\r\n%2").arg(c).arg(str));
    }
}


void App::maxMenuBntClicked()
{
    if (m_bIsMax)
    {
        showNormal();
        m_bIsMax = false;
    }
    else
    {
        showFullScreen();
        m_bIsMax = true;
    }

//    static QRect location = m_parentWidget->geometry();

//    if (m_bIsMax) {
//        m_parentWidget->setGeometry(location);
//    } else {
//        location = m_parentWidget->geometry();
//        m_parentWidget->setGeometry(qApp->desktop()->availableGeometry());
//    }

//    m_parentWidget->setProperty("canMove", m_bIsMax);
//    m_bIsMax = !m_bIsMax;
}

void App::minMenuBntClicked()
{
    showMinimized();
}

void App::closeMenuBntClicked()
{
    close();
}


//bool App::nativeEvent(const QByteArray &eventType, void *message, long *result)
//{
//    MSG* msg = (MSG*)message;
//    switch(msg->message)
//        {
//        case WM_NCHITTEST:
//            int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
//            int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
//            if(xPos < boundaryWidth && yPos<boundaryWidth)                    //左上角
//                *result = HTTOPLEFT;
//            else if(xPos>=width()-boundaryWidth&&yPos<boundaryWidth)          //右上角
//                *result = HTTOPRIGHT;
//            else if(xPos<boundaryWidth&&yPos>=height()-boundaryWidth)         //左下角
//                *result = HTBOTTOMLEFT;
//            else if(xPos>=width()-boundaryWidth&&yPos>=height()-boundaryWidth)//右下角
//                *result = HTBOTTOMRIGHT;
//            else if(xPos < boundaryWidth)                                     //左边
//                *result =  HTLEFT;
//            else if(xPos>=width()-boundaryWidth)                              //右边
//                *result = HTRIGHT;
//            else if(yPos<boundaryWidth)                                       //上边
//                *result = HTTOP;
//            else if(yPos>=height()-boundaryWidth)                             //下边
//                *result = HTBOTTOM;
//            else              //其他部分不做处理，返回false，留给其他事件处理器处理
//               return false;
//            return true;
//        }
//        return false;         //此处返回false，留给其他事件处理器处理
//}


//void App::mousePressEvent(QMouseEvent *e)
//{
//    if(e->button()==Qt::LeftButton)
//        clickPos=e->pos();
//}
//void App::mouseMoveEvent(QMouseEvent *e)
//{
//    if(e->buttons()&Qt::LeftButton)
//        move(e->pos()+pos()-clickPos);
//}


void App::mouseMoveEvent(QMouseEvent *e)
{
    if (mousePressed && (e->buttons() && Qt::LeftButton)) {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}

void App::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void App::mouseReleaseEvent(QMouseEvent *)
{
    mousePressed = false;
}

void App::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Escape:
        break;
    default:
        event->accept();
    }
}


void App::paintEvent(QPaintEvent *)
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(6, 6, this->width()-12, this->height()-12);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for(int i=0; i<6; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(6-i, 6 -i, this->width()-(6-i)*2, this->height()-(6-i) * 2);
        int alpha = 115 - qSqrt(i)*50;
        if (alpha < 0)
            continue;
        color.setAlpha(alpha);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void App::closeEvent(QCloseEvent *event){
    emit tofCalibrtPage->sig_exit_thread();
}

