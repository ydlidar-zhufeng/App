#include "feedback.h"
#include "ui_feedback.h"

Feedback::Feedback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Feedback)
{
    ui->setupUi(this);
}

Feedback::~Feedback()
{
    delete ui;
}
