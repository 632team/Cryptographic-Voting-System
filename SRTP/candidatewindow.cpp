#include "candidatewindow.h"
#include "ui_candidatewindow.h"
#include <QDebug>
#include <QCoreApplication>
#include <QDir>

CandidateWindow::CandidateWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CandidateWindow)
{
    ui->setupUi(this);
//    ui->labelImage->
    //    QPixmap picture;
    QString dir = QCoreApplication::applicationFilePath();
    QDir temp;
//    QString trueDir = temp.
  //  qDebug() << trueDir;
    qDebug() << dir;
    qDebug() << picture.load("Photo.jpg") << "photo";
    ui->labelImage->setPixmap(picture);
    ui->labelImage->setFixedSize(171, 231);
}

CandidateWindow::~CandidateWindow()
{
    delete ui;
}

void CandidateWindow::inserInfo(const Candidate &rhs)
{
    qDebug() << "candidate age" << rhs.age;
    ui->lineEditAge->setText(QString::number(rhs.age));
    ui->lineEditId->setText(rhs.id);
    ui->lineEditName->setText(rhs.name);
    ui->lineEditSerialNum->setText(QString::number(rhs.srialNum));
    ui->lineEditSex->setText(rhs.sex);
    ui->textEditDeclare->setText(rhs.declaration);
    ui->textEditRecord->setText(rhs.record);


    return ;
}
