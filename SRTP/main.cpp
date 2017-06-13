#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include "registercenter.h"
#include "voterhelp.h"

//lineEdit->setEnabled(false)
//lineEdit->setText(str)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dao dao;
    QString sql = "select voter_age from voter_information";
    QSqlQuery resultSet = dao.findForResultSet(sql);
    qDebug() << resultSet.size();
    qDebug() << Dao::isConnected();

    RegisterCenter registerCenter = RegisterCenter::getInstance();
    VoterHelp voterHelp;

    MainWindow w;
    w.show();

    w.move((QApplication::desktop()->width() - w.width())/2,
              (QApplication::desktop()->height() - w.height())/2);

//    ShowResult resultWindow;
//    resultWindow.show();
//    qDebug() << "show result window";
    qDebug() << "end total";
    return a.exec();
}
