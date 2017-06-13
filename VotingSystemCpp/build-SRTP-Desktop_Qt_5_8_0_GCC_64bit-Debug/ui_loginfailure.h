/********************************************************************************
** Form generated from reading UI file 'loginfailure.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFAILURE_H
#define UI_LOGINFAILURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginFailure
{
public:
    QLabel *labelInfo;
    QPushButton *pushButtonClose;

    void setupUi(QDialog *LoginFailure)
    {
        if (LoginFailure->objectName().isEmpty())
            LoginFailure->setObjectName(QStringLiteral("LoginFailure"));
        LoginFailure->resize(348, 137);
        labelInfo = new QLabel(LoginFailure);
        labelInfo->setObjectName(QStringLiteral("labelInfo"));
        labelInfo->setGeometry(QRect(120, 50, 101, 20));
        pushButtonClose = new QPushButton(LoginFailure);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(240, 90, 85, 28));

        retranslateUi(LoginFailure);

        pushButtonClose->setDefault(true);


        QMetaObject::connectSlotsByName(LoginFailure);
    } // setupUi

    void retranslateUi(QDialog *LoginFailure)
    {
        LoginFailure->setWindowTitle(QApplication::translate("LoginFailure", "Error", Q_NULLPTR));
        labelInfo->setText(QApplication::translate("LoginFailure", "User Not Exit !!", Q_NULLPTR));
        pushButtonClose->setText(QApplication::translate("LoginFailure", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginFailure: public Ui_LoginFailure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFAILURE_H
