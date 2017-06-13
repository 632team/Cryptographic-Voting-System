/********************************************************************************
** Form generated from reading UI file 'showresult.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWRESULT_H
#define UI_SHOWRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ShowResult
{
public:
    QCustomPlot *customPlot;
    QPushButton *pushButton;

    void setupUi(QWidget *ShowResult)
    {
        if (ShowResult->objectName().isEmpty())
            ShowResult->setObjectName(QStringLiteral("ShowResult"));
        ShowResult->resize(400, 300);
        ShowResult->setMinimumSize(QSize(400, 300));
        ShowResult->setMaximumSize(QSize(400, 300));
        customPlot = new QCustomPlot(ShowResult);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(0, 0, 400, 250));
        pushButton = new QPushButton(ShowResult);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 270, 85, 28));

        retranslateUi(ShowResult);

        QMetaObject::connectSlotsByName(ShowResult);
    } // setupUi

    void retranslateUi(QWidget *ShowResult)
    {
        ShowResult->setWindowTitle(QApplication::translate("ShowResult", "Result", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ShowResult", "Show", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShowResult: public Ui_ShowResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWRESULT_H
