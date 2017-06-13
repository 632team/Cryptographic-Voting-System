/********************************************************************************
** Form generated from reading UI file 'userinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

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

class Ui_userInfo
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
    QPushButton *pushButtonCandidate;
    QPushButton *pushButton;

    void setupUi(QWidget *userInfo)
    {
        if (userInfo->objectName().isEmpty())
            userInfo->setObjectName(QStringLiteral("userInfo"));
        userInfo->resize(342, 295);
        userInfo->setMinimumSize(QSize(342, 295));
        userInfo->setMaximumSize(QSize(342, 295));
        labelName = new QLabel(userInfo);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(31, 41, 42, 20));
        lineEditName = new QLineEdit(userInfo);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(79, 41, 142, 28));
        lineEditName->setReadOnly(true);
        labelAge = new QLabel(userInfo);
        labelAge->setObjectName(QStringLiteral("labelAge"));
        labelAge->setGeometry(QRect(31, 101, 29, 20));
        lineEditAge = new QLineEdit(userInfo);
        lineEditAge->setObjectName(QStringLiteral("lineEditAge"));
        lineEditAge->setGeometry(QRect(79, 101, 142, 28));
        lineEditAge->setReadOnly(true);
        labelId = new QLabel(userInfo);
        labelId->setObjectName(QStringLiteral("labelId"));
        labelId->setGeometry(QRect(31, 151, 19, 20));
        lineEditId = new QLineEdit(userInfo);
        lineEditId->setObjectName(QStringLiteral("lineEditId"));
        lineEditId->setGeometry(QRect(79, 151, 142, 28));
        lineEditId->setReadOnly(true);
        labelSex = new QLabel(userInfo);
        labelSex->setObjectName(QStringLiteral("labelSex"));
        labelSex->setGeometry(QRect(31, 201, 28, 20));
        lineEditSex = new QLineEdit(userInfo);
        lineEditSex->setObjectName(QStringLiteral("lineEditSex"));
        lineEditSex->setGeometry(QRect(79, 201, 142, 28));
        lineEditSex->setReadOnly(true);
        pushButtonCandidate = new QPushButton(userInfo);
        pushButtonCandidate->setObjectName(QStringLiteral("pushButtonCandidate"));
        pushButtonCandidate->setGeometry(QRect(230, 230, 111, 28));
        pushButton = new QPushButton(userInfo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 270, 111, 28));

        retranslateUi(userInfo);

        QMetaObject::connectSlotsByName(userInfo);
    } // setupUi

    void retranslateUi(QWidget *userInfo)
    {
        userInfo->setWindowTitle(QApplication::translate("userInfo", "User", Q_NULLPTR));
        labelName->setText(QApplication::translate("userInfo", "Name:", Q_NULLPTR));
        labelAge->setText(QApplication::translate("userInfo", "Age:", Q_NULLPTR));
        labelId->setText(QApplication::translate("userInfo", "ID:", Q_NULLPTR));
        labelSex->setText(QApplication::translate("userInfo", "Sex:", Q_NULLPTR));
        pushButtonCandidate->setText(QApplication::translate("userInfo", "View Candidate", Q_NULLPTR));
        pushButton->setText(QApplication::translate("userInfo", "Confirm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class userInfo: public Ui_userInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
