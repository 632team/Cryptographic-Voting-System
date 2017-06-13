#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include "inputerrorwindow.h"
#include "ui_inputerrorwindow.h"
#include "registersuccessful.h"
#include "ui_registersuccessful.h"
#include "notvaliduerwindow.h"
#include "ui_notvaliduerwindow.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = 0);
    ~RegisterWindow();

private slots:
    void on_pushButtonCreate_pressed();

private:
    Ui::RegisterWindow *ui;
    InputErrorWindow errorWindow;
    RegisterSuccessful registSuccess;
    NotValidUerWindow notValideUserWindow;
};

#endif // REGISTERWINDOW_H
