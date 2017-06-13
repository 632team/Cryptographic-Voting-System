#include <QDesktopWidget>
#include "userinfo.h"
#include "ui_userinfo.h"
#include "voterhelp.h"
#include "dao.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>

userInfo::userInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userInfo)
{
    ui->setupUi(this);
}

userInfo::~userInfo()
{
    delete ui;
}

void userInfo::initilize(const Voter &rhs)
{
    ui->lineEditAge->setText(QString::number(rhs.age));
    ui->lineEditName->setText(rhs.name);
    ui->lineEditId->setText(rhs.id);
    ui->lineEditSex->setText(rhs.sex);

    return ;
}

void userInfo::on_pushButtonCandidate_pressed()
{
    candidateList.initilize();
    candidateList.show();
    candidateList.move((QApplication::desktop()->width() - candidateList.width())/2,
              (QApplication::desktop()->height() - candidateList.height())/2);
}

void userInfo::on_pushButton_pressed()
{
    QString temp = VoterHelp::getFheEncrypedVector();
    this->hide();
    //QString sql = "INSERT INTO `vote_result`(`candidate_id`, `raw_result`, `result`) VALUES ( 'null', '" + temp + "',0";
    //Dao::insertInfo(sql);
   QString fileName = VoterHelp::idv + "_Info";
//    QFile file(fileName);
//    if (file.exists()){
//        return ;
//    }else{
//        file.open(QIODevice::WriteOnly);
//        QTextStream out(&file);
//        out << temp;
//    }
}
