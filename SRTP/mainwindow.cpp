#include <QDebug>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinfo.h"
#include "ui_userinfo.h"
#include "loginfailure.h"
#include "ui_loginfailure.h"
#include "voterhelp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(600, 400);
    resultWindow.show();
/*
 * load picture from the internet
 */
//    QPixmap picture;
//    picture.load("/home/mrsiz/图片/ww.png");
//    picture.load("http://7xsy54.com1.z0.glb.clouddn.com/1.jpg");
//    qDebug() << picture.isNull();
//    ui ->password ->setPixmap(picture);
//    QNetworkAccessManager manager;
//    manager.get(QNetworkRequest(QUrl("http://7xsy54.com1.z0.glb.clouddn.com/1.jpg")));
//    connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonSignIn_pressed()
{
    QString username = ui -> lineEditUserName ->text();
    QString password = ui -> lineEditPassword ->text();
    qDebug() << "username: " << username << '\n';
    qDebug() << "password: " << password << '\n';
//    ui -> lineEditPassword ->QWidget
//    this->hide();
    //LoginFailure loginFailureWindow;
//    loginFailureWindow.show();
    bool flag = false;
    Voter temp = Dao::checkLogin(username, password, flag);

    if (!flag){
        loginFailureWindow.show();
    }else{
        //this->hide();
//        userWindow.ui->lineEditAge->setText(QString::number(temp.age));
//        userWindow.ui->lineEditName->setText(temp.name);
//        userWindow.ui->lineEditId->setText(temp.id);
//        userWindow.ui->lineEditSex->setText(temp.sex);
        VoterHelp::idv = username;
        userWindow.initilize(temp);
        userWindow.show();
        userWindow.move((QApplication::desktop()->width() - userWindow.width())/2,
                  (QApplication::desktop()->height() - userWindow.height())/2);
    }
//   userWindow.setWindowFlags(userWindow.windowFlags() | Qt::WindowStaysOnTopHint);
    return ;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QPixmap pixmap;
    pixmap.loadFromData(reply->readAll());
    qDebug() << "is OK : " << pixmap.isNull();
    ui -> password ->setPixmap(pixmap);
    return ;
}

void MainWindow::on_pushButtonSingUp_pressed()
{
    registerWindow.show();
    registerWindow.move((QApplication::desktop()->width() - registerWindow.width())/2,
              (QApplication::desktop()->height() - registerWindow.height())/2);
}
