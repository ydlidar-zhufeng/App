#include "newcombobox.h"

NewComboBox::NewComboBox(QWidget *parent):QComboBox(parent)
{

}

void NewComboBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked(true);
    }
    QComboBox::mousePressEvent(event);
}
