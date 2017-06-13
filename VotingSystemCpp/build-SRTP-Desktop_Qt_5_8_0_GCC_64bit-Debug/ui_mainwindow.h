/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonSignIn;
    QLabel *username;
    QLineEdit *lineEditUserName;
    QLabel *password;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonSingUp;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(675, 453);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonSignIn = new QPushButton(centralWidget);
        pushButtonSignIn->setObjectName(QStringLiteral("pushButtonSignIn"));
        pushButtonSignIn->setGeometry(QRect(360, 250, 85, 28));
        pushButtonSignIn->setAutoDefault(true);
        username = new QLabel(centralWidget);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(170, 110, 66, 20));
        lineEditUserName = new QLineEdit(centralWidget);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(230, 110, 201, 28));
        password = new QLabel(centralWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(150, 160, 66, 20));
        lineEditPassword = new QLineEdit(centralWidget);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(230, 160, 201, 28));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        pushButtonSingUp = new QPushButton(centralWidget);
        pushButtonSingUp->setObjectName(QStringLiteral("pushButtonSingUp"));
        pushButtonSingUp->setGeometry(QRect(480, 250, 85, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 675, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEditUserName, lineEditPassword);
        QWidget::setTabOrder(lineEditPassword, pushButtonSignIn);
        QWidget::setTabOrder(pushButtonSignIn, pushButtonSingUp);

        retranslateUi(MainWindow);

        pushButtonSignIn->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SRTP", Q_NULLPTR));
        pushButtonSignIn->setText(QApplication::translate("MainWindow", "Sign In", Q_NULLPTR));
        username->setText(QApplication::translate("MainWindow", "userid:", Q_NULLPTR));
        password->setText(QApplication::translate("MainWindow", "password:", Q_NULLPTR));
        pushButtonSingUp->setText(QApplication::translate("MainWindow", "Sign Up", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
