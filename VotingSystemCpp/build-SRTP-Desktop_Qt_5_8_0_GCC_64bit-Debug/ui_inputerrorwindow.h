/********************************************************************************
** Form generated from reading UI file 'inputerrorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTERRORWINDOW_H
#define UI_INPUTERRORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_InputErrorWindow
{
public:
    QLabel *label;

    void setupUi(QDialog *InputErrorWindow)
    {
        if (InputErrorWindow->objectName().isEmpty())
            InputErrorWindow->setObjectName(QStringLiteral("InputErrorWindow"));
        InputErrorWindow->resize(317, 104);
        InputErrorWindow->setMinimumSize(QSize(317, 104));
        InputErrorWindow->setMaximumSize(QSize(317, 104));
        label = new QLabel(InputErrorWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 40, 101, 20));

        retranslateUi(InputErrorWindow);

        QMetaObject::connectSlotsByName(InputErrorWindow);
    } // setupUi

    void retranslateUi(QDialog *InputErrorWindow)
    {
        InputErrorWindow->setWindowTitle(QApplication::translate("InputErrorWindow", "InputError", Q_NULLPTR));
        label->setText(QApplication::translate("InputErrorWindow", "Input Error !!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputErrorWindow: public Ui_InputErrorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTERRORWINDOW_H
