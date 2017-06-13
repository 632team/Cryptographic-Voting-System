/********************************************************************************
** Form generated from reading UI file 'candidatewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANDIDATEWINDOW_H
#define UI_CANDIDATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CandidateWindow
{
public:
    QLabel *labelId;
    QLineEdit *lineEditSerialNum;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelAge;
    QLineEdit *lineEditAge;
    QLabel *labelSex;
    QLineEdit *lineEditSex;
    QLabel *labelId_2;
    QLineEdit *lineEditId;
    QLabel *labelRecord;
    QTextEdit *textEditRecord;
    QLabel *labelDeclare;
    QTextEdit *textEditDeclare;
    QLabel *labelImage;

    void setupUi(QWidget *CandidateWindow)
    {
        if (CandidateWindow->objectName().isEmpty())
            CandidateWindow->setObjectName(QStringLiteral("CandidateWindow"));
        CandidateWindow->resize(638, 448);
        CandidateWindow->setMinimumSize(QSize(638, 448));
        CandidateWindow->setMaximumSize(QSize(638, 448));
        labelId = new QLabel(CandidateWindow);
        labelId->setObjectName(QStringLiteral("labelId"));
        labelId->setGeometry(QRect(22, 22, 69, 20));
        lineEditSerialNum = new QLineEdit(CandidateWindow);
        lineEditSerialNum->setObjectName(QStringLiteral("lineEditSerialNum"));
        lineEditSerialNum->setGeometry(QRect(98, 19, 141, 28));
        lineEditSerialNum->setReadOnly(true);
        labelName = new QLabel(CandidateWindow);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(23, 59, 39, 20));
        lineEditName = new QLineEdit(CandidateWindow);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(98, 59, 141, 28));
        lineEditName->setLayoutDirection(Qt::LeftToRight);
        lineEditName->setReadOnly(true);
        labelAge = new QLabel(CandidateWindow);
        labelAge->setObjectName(QStringLiteral("labelAge"));
        labelAge->setGeometry(QRect(22, 94, 26, 20));
        lineEditAge = new QLineEdit(CandidateWindow);
        lineEditAge->setObjectName(QStringLiteral("lineEditAge"));
        lineEditAge->setGeometry(QRect(98, 94, 141, 28));
        lineEditAge->setReadOnly(true);
        labelSex = new QLabel(CandidateWindow);
        labelSex->setObjectName(QStringLiteral("labelSex"));
        labelSex->setGeometry(QRect(22, 130, 25, 20));
        lineEditSex = new QLineEdit(CandidateWindow);
        lineEditSex->setObjectName(QStringLiteral("lineEditSex"));
        lineEditSex->setGeometry(QRect(98, 130, 141, 28));
        lineEditSex->setReadOnly(true);
        labelId_2 = new QLabel(CandidateWindow);
        labelId_2->setObjectName(QStringLiteral("labelId_2"));
        labelId_2->setGeometry(QRect(22, 166, 16, 20));
        lineEditId = new QLineEdit(CandidateWindow);
        lineEditId->setObjectName(QStringLiteral("lineEditId"));
        lineEditId->setGeometry(QRect(98, 166, 141, 28));
        lineEditId->setReadOnly(true);
        labelRecord = new QLabel(CandidateWindow);
        labelRecord->setObjectName(QStringLiteral("labelRecord"));
        labelRecord->setGeometry(QRect(370, 270, 66, 20));
        textEditRecord = new QTextEdit(CandidateWindow);
        textEditRecord->setObjectName(QStringLiteral("textEditRecord"));
        textEditRecord->setGeometry(QRect(450, 270, 171, 91));
        textEditRecord->setReadOnly(true);
        labelDeclare = new QLabel(CandidateWindow);
        labelDeclare->setObjectName(QStringLiteral("labelDeclare"));
        labelDeclare->setGeometry(QRect(0, 270, 91, 20));
        textEditDeclare = new QTextEdit(CandidateWindow);
        textEditDeclare->setObjectName(QStringLiteral("textEditDeclare"));
        textEditDeclare->setGeometry(QRect(98, 270, 141, 91));
        textEditDeclare->setReadOnly(true);
        labelImage = new QLabel(CandidateWindow);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(450, 10, 171, 231));
        labelImage->setTextFormat(Qt::PlainText);
        labelImage->setPixmap(QPixmap(QString::fromUtf8("Photo.jpg")));
        labelImage->setScaledContents(true);

        retranslateUi(CandidateWindow);

        QMetaObject::connectSlotsByName(CandidateWindow);
    } // setupUi

    void retranslateUi(QWidget *CandidateWindow)
    {
        CandidateWindow->setWindowTitle(QApplication::translate("CandidateWindow", "CandidateInfo", Q_NULLPTR));
        labelId->setText(QApplication::translate("CandidateWindow", "SerialNum", Q_NULLPTR));
        labelName->setText(QApplication::translate("CandidateWindow", "Name", Q_NULLPTR));
        labelAge->setText(QApplication::translate("CandidateWindow", "Age", Q_NULLPTR));
        labelSex->setText(QApplication::translate("CandidateWindow", "Sex", Q_NULLPTR));
        labelId_2->setText(QApplication::translate("CandidateWindow", "Id", Q_NULLPTR));
        labelRecord->setText(QApplication::translate("CandidateWindow", "Record", Q_NULLPTR));
        labelDeclare->setText(QApplication::translate("CandidateWindow", "Declareation", Q_NULLPTR));
        labelImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CandidateWindow: public Ui_CandidateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANDIDATEWINDOW_H
