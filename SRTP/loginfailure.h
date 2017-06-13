#ifndef LOGINFAILURE_H
#define LOGINFAILURE_H

#include <QDialog>

namespace Ui {
class LoginFailure;
}

class LoginFailure : public QDialog
{
    Q_OBJECT

public:
    explicit LoginFailure(QWidget *parent = 0);
    ~LoginFailure();

private slots:
    void on_pushButtonClose_pressed();

private:
    Ui::LoginFailure *ui;
};

#endif // LOGINFAILURE_H
