#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QDialog>

namespace Ui {
class Feedback;
}

class Feedback : public QDialog
{
    Q_OBJECT

public:
    explicit Feedback(QWidget *parent = nullptr);
    ~Feedback();

private:
    Ui::Feedback *ui;
};

#endif // FEEDBACK_H
