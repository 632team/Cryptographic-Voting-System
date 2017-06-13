#include "registercenter.h"
#include <QDebug>
#include <QIODevice>
#include "rsa.h"
#include "dao.h"

std::vector<uint64_t> RegisterCenter::encryptedInfo;
std::string RegisterCenter::deencrypeInfoString;
QString RegisterCenter::id;
int RegisterCenter::e;
int RegisterCenter::n;
QString RegisterCenter::nv;
QString RegisterCenter::idv;
QString RegisterCenter::encodeNv;

RegisterCenter::RegisterCenter()
{

}

RegisterCenter RegisterCenter::getInstance()
{
    static RegisterCenter instance = RegisterCenter();
    return instance;
}

void RegisterCenter::getEncrypedInfo(const std::vector<uint64_t> &rhs, const QString& another)
{
    encryptedInfo = rhs;
    for (const auto& elem : encryptedInfo){
        qDebug() << "register center " << elem;
    }
    //test read
    isValideVoter(decode(rhs, another));
    return ;
}

QString RegisterCenter::decode(const std::vector<uint64_t> &rhs, const QString& another)
{
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
    return finalString;
}



bool RegisterCenter::isValideVoter(const QString &rhs)
{
    qDebug() << rhs;
    bool flag = Dao::isValideVoter(rhs);
    return flag;
}

QString RegisterCenter::getRandomNumberFromEncrypedInfo(const QString &rhs)
{
    int length = rhs.size();
    int i = 0;
    while (i < length && rhs[i] != '#'){
        ++i;
    }
    ++i;
    QString randomNumber;
    while (i < length){
        randomNumber.push_back(rhs[i]);
        ++i;
    }
    return randomNumber;
}

QString RegisterCenter::getIdStringFromEncrypedInfo(const QString &rhs)
{
    int length = rhs.size();
    int i = 0;
    QString idString;
    while (i < length && rhs[i] != '#'){
        idString.push_back(rhs[i]);
        ++i;
    }
    idv = idString;
    nv = getNv(idv);
    return idString;
}

std::vector<uint64_t> RegisterCenter::encodeSerialNumber(const QString &serialNum)
{
    int length = serialNum.size();
    std::string newSerialNum = serialNum.toStdString();
    std::vector<uint64_t> encodeNUM(length);
    std::string helpEncodeNv;
    for (int i = 0; i < length; ++i){
        encodeNUM[i] = RSA::PowMod((uint64_t)newSerialNum[i], e, n);
        helpEncodeNv.push_back(encodeNUM[i]);
    }
    encodeNv = QString::fromStdString(helpEncodeNv);
    return encodeNUM;
}

std::vector<uint64_t> RegisterCenter::encodeSerialMACv(const QString &macv)
{
    int length = macv.size();
    std::string newMACV = macv.toStdString();
    std::vector<uint64_t> encodeMACV(length);
    //std::string helpEncodeNv;
    for (int i = 0; i < length; ++i){
        encodeMACV[i] = RSA::PowMod((uint64_t)newMACV[i], e, n);
        //helpEncodeNv.push_back(encodeMAC);
    }
    return encodeMACV;
}


void RegisterCenter::initializeEandN()
{
    QString sql = "select * from public_key_system where system_name = 'R'";
    QSqlQuery result = Dao::findForResultSet(sql);
    QString temp;
    if (result.next()){
        temp = result.value(1).toString();
    }
    std::string newString = temp.toStdString();
    e = 0, n = 0;
    int i = 0;
    int length = newString.size();
    while (i < length && newString[i] != '#'){
        e *= 10;
        e += (newString[i] - '0');
        ++i;
    }
    ++i;
    while (i < length){
        n *= 10;
        n += (newString[i] - '0');
        ++i;
    }
    qDebug() << e;
    qDebug() << n;
    return ;
}

QString RegisterCenter::getNv(const QString &idString)
{
    QString sql = "select * from voter_information where voter_ic = '" + idString + "'";
    QSqlQuery resultSet = Dao::findForResultSet(sql);
    if (resultSet.next()){
        return resultSet.value(0).toString();
    }
    return "null";
}

QString RegisterCenter::getNv()
{
    return nv;
}

QString RegisterCenter::getIdv()
{
    return idv;
}

void RegisterCenter::setNvAndIdv()
{

}

QString RegisterCenter::encodeSerialNumber()
{
    return encodeNv;
}
