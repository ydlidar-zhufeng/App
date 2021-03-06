#ifndef NEWCOMBOBOX_H
#define NEWCOMBOBOX_H

#include <QWidget>
#include <QComboBox>
#include <QMouseEvent>

class NewComboBox : public QComboBox
{
    Q_OBJECT
public:
    NewComboBox(QWidget*parent=0);
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked(bool);
};

#endif // NEWCOMBOBOX_H
