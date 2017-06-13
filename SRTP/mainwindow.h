#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include "ui_userinfo.h"
#include "userinfo.h"
#include "dao.h"
#include "loginfailure.h"
#include "ui_loginfailure.h"
#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "showresult.h"
#include "ui_showresult.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonSignIn_pressed();
    void replyFinished(QNetworkReply *reply);
    void on_pushButtonSingUp_pressed();

private:
    Ui::MainWindow *ui;
    userInfo userWindow;
    LoginFailure loginFailureWindow;
    RegisterWindow registerWindow;
    ShowResult resultWindow;
    //Dao dao;
};

#endif // MAINWINDOW_H
