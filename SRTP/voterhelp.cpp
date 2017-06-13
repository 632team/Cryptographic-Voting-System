#include "voterhelp.h"
#include "registercenter.h"
#include <QDebug>
#include "rsa.h"
#include <QFile>
#include <QTextStream>
#include <fstream>
#include "fhe_can.h"

QString VoterHelp::R_Nv;
QString VoterHelp::FUE_publicKey;
QString VoterHelp::S_Gv;
std::vector<uint64_t> VoterHelp::voteContent;
QString VoterHelp::R_MACv;
QString VoterHelp::SIGr_Nv;
QString VoterHelp::Ec_MvX;
QString VoterHelp::Ec_Gv;
QString VoterHelp::Av;
QString VoterHelp::V_MvX;
QString VoterHelp::V_Mv;
FHE_SOLVE VoterHelp::fhe_solve("/home/mrsiz/SRTP/");
QString VoterHelp::temp_Mv;
QString VoterHelp::idv;

VoterHelp::VoterHelp()
{
    qDebug() << "VoterHelp";
}

void VoterHelp::getEncrypedNvFromRegisterCenter()
{
    R_Nv = RegisterCenter::encodeSerialNumber();
}

QString VoterHelp::getFheEncrypedVector()
{
    std::vector<long> tempVec(voteContent.size());
    qDebug() << voteContent.size();
    for (int i = 0; i < voteContent.size(); ++i){
        tempVec[i] = voteContent[i];
        qDebug() << tempVec[i];
    }
    qDebug() << "ni shi zz ma";
    QString temp = fhe_solve.Encode(tempVec);
    std::string toFileString = QStringConvertStdString(temp);
    std::string fileName = VoterHelp::idv.toStdString() + "_Info";
//     qDebug() << fileName;
//        QFile file(fileName);
//        if (file.exists()){
//        return "";
//     }else{
//        file.open(QIODevice::WriteOnly);
//        QTextStream out(&file);
//        qDebug() << "shu chu dao wen jian";
//        out << temp;
//    }
    int a = 0;
    for(int i = 0; i < toFileString.size(); ++i){
        if(toFileString[i] < 0) a = 1;
    }
    qDebug() << "xie fushu" << a;
      fstream out(fileName, fstream::out|fstream::trunc);
       out << toFileString;
       out.close();
    //temp_Mv = QString(QString::fromLocal8Bit(temp.c_str()));

    qDebug() << "end ";
    return  "";
}

QString VoterHelp::getMvXinVoter()
{
    getEncrypedNvFromRegisterCenter();
    getFheEncrypedVector();
    V_Mv = R_Nv + "#" + temp_Mv;
    return V_Mv;
}

QString VoterHelp::getMvX()
{
    getMvXinVoter();
    QString another = RegisterCenter::getIdv();
    QFile file(another);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString temp;
    in >> temp;
    qDebug() << "decode information";
    qDebug() << temp;
    qDebug() << "decode end";
    std::string tempInfo = temp.toStdString();
    uint64_t privateKey = 0, prim = 0;
    int length = tempInfo.size();
    int i = 0;
    for (; i < length; ++i){
        if (tempInfo[i] != '#'){
            privateKey = privateKey * 10;
            privateKey += tempInfo[i] - '0';
        }else{
            ++i;
            break;
        }
    }
    qDebug() << privateKey;
    qDebug() << i;
    while (i < length){
        prim = prim * 10;
        prim += tempInfo[i] - '0';
        ++i;
    }
    qDebug() << prim;

    std::string stringMV = V_Mv.toStdString();
    std::vector<uint64_t> rhs;
    for (const auto& elem : stringMV){
        rhs.push_back((uint64_t)stringMV[i]);
    }
    int lengthVec = rhs.size();
    std::vector<uint64_t> decodeVec(lengthVec);
    std::string rawString;
    for (int i = 0; i < lengthVec; ++i){
        qDebug() << "decod : " << rhs[i];
        decodeVec[i] = RSA::PowMod(rhs[i], privateKey, prim);
        qDebug() << decodeVec[i];
        rawString.push_back(char(decodeVec[i]));
    }
    QString finalString = QString::fromStdString(rawString);
    qDebug() << finalString;
    V_MvX = finalString;
    return finalString;
}

QString VoterHelp::encodeWithRSA(const QString &enString, const QString &systemName)
{

}




