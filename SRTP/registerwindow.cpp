#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "voter.h"
#include "dao.h"
#include <QDebug>
#include "registercenter.h"
#include "rsa.h"
#include <string>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDesktopWidget>
#include "voterhelp.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButtonCreate_pressed()
{
    Voter voter;
    voter.age = ui->lineEditAge->text().toInt();
    voter.name = ui->lineEditName->text();
    voter.sex = ui->lineEditSex->text();
    voter.password = ui->lineEditPassword->text();
    voter.id = ui->lineEditId->text();
    if (voter.isOk()){
        //bool flag = Dao::insertVoterInfo(voter);
        RSA_PARAM r;
        uint64_t temp;
        //if (flag){
//            registSuccess.show();
            qDebug() << "Encrypt the info";
            auto encryptFunc = [&](const QString& id){
                int randomNumber = RSA::g_Rnd.Random(100);
                voter.Hv = QString::number(randomNumber);
                //qDebug() << randomNumber;
                QString toEncrypt = id + "#" + QString::number(randomNumber);
                //voter.pub = toEncrypt;
                std::string stdStringToEncrypt = toEncrypt.toStdString();
                auto lengthToEncrypt = stdStringToEncrypt.size();
                std::vector<uint64_t> encryptInfo;
                //const uint64_t* q = stdStringToEncrypt.data();
                //uint64_t* q = toEncrypt.data();
                r = RSA::RsaGetParam();
                //uint64_t t_e = r.e, t_n = r.n;
                voter.pub = QString::number(r.e) + "#" + QString::number(r.n);
                for (int i = 0; i < lengthToEncrypt; ++i){
                    temp = (uint64_t)stdStringToEncrypt[i];
                    qDebug() << temp;
                    uint64_t val = RSA::PowMod(temp, r.e, r.n);
                    qDebug() << "encode : " << val;
                    encryptInfo.push_back(val);
                }
                QString privateKeyAndPrim = QString::number(r.d) + "#" + QString::number(r.n);
                QFile file(voter.id);
                file.open(QIODevice::WriteOnly);
                QTextStream out(&file);
                out << privateKeyAndPrim;
                return encryptInfo;
            };
            std::vector<uint64_t> encryptedInfo = encryptFunc(voter.id);
            RegisterCenter::getEncrypedInfo(encryptedInfo, voter.id);
            if (RegisterCenter::isValideVoter(voter.id) && Dao::insertVoterInfo(voter)){
                this -> hide();
                VoterHelp::idv = voter.id;
                registSuccess.show();
                qDebug() << "successful";
            }else{
                notValideUserWindow.show();
                notValideUserWindow.move((QApplication::desktop()->width() - notValideUserWindow.width())/2,
                          (QApplication::desktop()->height() - notValideUserWindow.height())/2);
            }

        //}

    }else{
        errorWindow.show();
        errorWindow.move((QApplication::desktop()->width() - errorWindow.width())/2,
                  (QApplication::desktop()->height() - errorWindow.height())/2);
    }
    qDebug() << "end";
    return ;
}
