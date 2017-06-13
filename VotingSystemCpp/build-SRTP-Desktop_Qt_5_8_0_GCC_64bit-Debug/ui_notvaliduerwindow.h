/********************************************************************************
** Form generated from reading UI file 'notvaliduerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTVALIDUERWINDOW_H
#define UI_NOTVALIDUERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotValidUerWindow
{
public:
    QLabel *label;

    void setupUi(QWidget *NotValidUerWindow)
    {
        if (NotValidUerWindow->objectName().isEmpty())
            NotValidUerWindow->setObjectName(QStringLiteral("NotValidUerWindow"));
        NotValidUerWindow->resize(348, 137);
        NotValidUerWindow->setMinimumSize(QSize(348, 137));
        NotValidUerWindow->setMaximumSize(QSize(348, 137));
        label = new QLabel(NotValidUerWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 50, 131, 20));

        retranslateUi(NotValidUerWindow);

        QMetaObject::connectSlotsByName(NotValidUerWindow);
    } // setupUi

    void retranslateUi(QWidget *NotValidUerWindow)
    {
        NotValidUerWindow->setWindowTitle(QApplication::translate("NotValidUerWindow", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("NotValidUerWindow", "Not Valide Voter !!!!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NotValidUerWindow: public Ui_NotValidUerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTVALIDUERWINDOW_H
