/********************************************************************************
** Form generated from reading UI file 'registersuccessful.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERSUCCESSFUL_H
#define UI_REGISTERSUCCESSFUL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_RegisterSuccessful
{
public:
    QLabel *label;

    void setupUi(QDialog *RegisterSuccessful)
    {
        if (RegisterSuccessful->objectName().isEmpty())
            RegisterSuccessful->setObjectName(QStringLiteral("RegisterSuccessful"));
        RegisterSuccessful->resize(317, 104);
        RegisterSuccessful->setMinimumSize(QSize(317, 104));
        RegisterSuccessful->setMaximumSize(QSize(317, 104));
        label = new QLabel(RegisterSuccessful);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 40, 111, 20));

        retranslateUi(RegisterSuccessful);

        QMetaObject::connectSlotsByName(RegisterSuccessful);
    } // setupUi

    void retranslateUi(QDialog *RegisterSuccessful)
    {
        RegisterSuccessful->setWindowTitle(QApplication::translate("RegisterSuccessful", "Successful", Q_NULLPTR));
        label->setText(QApplication::translate("RegisterSuccessful", "Successful   !!!!!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterSuccessful: public Ui_RegisterSuccessful {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERSUCCESSFUL_H
