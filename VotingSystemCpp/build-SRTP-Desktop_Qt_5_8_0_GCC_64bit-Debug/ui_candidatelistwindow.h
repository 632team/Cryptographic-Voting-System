/********************************************************************************
** Form generated from reading UI file 'candidatelistwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANDIDATELISTWINDOW_H
#define UI_CANDIDATELISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CandidateListWindow
{
public:
    QListWidget *listWidget;
    QPushButton *pushButtonConfirm;

    void setupUi(QWidget *CandidateListWindow)
    {
        if (CandidateListWindow->objectName().isEmpty())
            CandidateListWindow->setObjectName(QStringLiteral("CandidateListWindow"));
        CandidateListWindow->resize(142, 189);
        CandidateListWindow->setMinimumSize(QSize(142, 189));
        CandidateListWindow->setMaximumSize(QSize(142, 189));
        listWidget = new QListWidget(CandidateListWindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 141, 151));
        pushButtonConfirm = new QPushButton(CandidateListWindow);
        pushButtonConfirm->setObjectName(QStringLiteral("pushButtonConfirm"));
        pushButtonConfirm->setGeometry(QRect(56, 160, 85, 28));

        retranslateUi(CandidateListWindow);

        QMetaObject::connectSlotsByName(CandidateListWindow);
    } // setupUi

    void retranslateUi(QWidget *CandidateListWindow)
    {
        CandidateListWindow->setWindowTitle(QApplication::translate("CandidateListWindow", "Form", Q_NULLPTR));
        pushButtonConfirm->setText(QApplication::translate("CandidateListWindow", "Confirm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CandidateListWindow: public Ui_CandidateListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANDIDATELISTWINDOW_H
