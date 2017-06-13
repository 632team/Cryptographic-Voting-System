/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelAge;
    QLineEdit *lineEditAge;
    QLabel *labelId;
    QLineEdit *lineEditId;
    QLabel *labelSex;
    QLineEdit *lineEditSex;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonCreate;

    void setupUi(QWidget *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QStringLiteral("RegisterWindow"));
        RegisterWindow->resize(525, 243);
        RegisterWindow->setMinimumSize(QSize(525, 243));
        RegisterWindow->setMaximumSize(QSize(525, 243));
        labelName = new QLabel(RegisterWindow);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(32, 21, 42, 20));
        lineEditName = new QLineEdit(RegisterWindow);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(80, 21, 142, 28));
        labelAge = new QLabel(RegisterWindow);
        labelAge->setObjectName(QStringLiteral("labelAge"));
        labelAge->setGeometry(QRect(302, 21, 29, 20));
        lineEditAge = new QLineEdit(RegisterWindow);
        lineEditAge->setObjectName(QStringLiteral("lineEditAge"));
        lineEditAge->setGeometry(QRect(337, 21, 142, 28));
        labelId = new QLabel(RegisterWindow);
        labelId->setObjectName(QStringLiteral("labelId"));
        labelId->setGeometry(QRect(50, 80, 19, 21));
        lineEditId = new QLineEdit(RegisterWindow);
        lineEditId->setObjectName(QStringLiteral("lineEditId"));
        lineEditId->setGeometry(QRect(80, 80, 142, 28));
        labelSex = new QLabel(RegisterWindow);
        labelSex->setObjectName(QStringLiteral("labelSex"));
        labelSex->setGeometry(QRect(300, 80, 28, 20));
        lineEditSex = new QLineEdit(RegisterWindow);
        lineEditSex->setObjectName(QStringLiteral("lineEditSex"));
        lineEditSex->setGeometry(QRect(340, 80, 142, 28));
        labelPassword = new QLabel(RegisterWindow);
        labelPassword->setObjectName(QStringLiteral("labelPassword"));
        labelPassword->setGeometry(QRect(10, 150, 66, 20));
        lineEditPassword = new QLineEdit(RegisterWindow);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(80, 150, 142, 28));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        pushButtonCreate = new QPushButton(RegisterWindow);
        pushButtonCreate->setObjectName(QStringLiteral("pushButtonCreate"));
        pushButtonCreate->setGeometry(QRect(340, 150, 142, 28));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QWidget *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QApplication::translate("RegisterWindow", "Register", Q_NULLPTR));
        labelName->setText(QApplication::translate("RegisterWindow", "Name:", Q_NULLPTR));
        labelAge->setText(QApplication::translate("RegisterWindow", "Age:", Q_NULLPTR));
        labelId->setText(QApplication::translate("RegisterWindow", "ID:", Q_NULLPTR));
        labelSex->setText(QApplication::translate("RegisterWindow", "Sex:", Q_NULLPTR));
        labelPassword->setText(QApplication::translate("RegisterWindow", "Password:", Q_NULLPTR));
        pushButtonCreate->setText(QApplication::translate("RegisterWindow", "Create an account", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
