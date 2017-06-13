#ifndef REGISTERCENTER_H
#define REGISTERCENTER_H

#include <QApplication>
#include <vector>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

class RegisterCenter
{
private:
    RegisterCenter();
public:
    static RegisterCenter getInstance();
    static void getEncrypedInfo(const std::vector<uint64_t>& rhs, const QString& another);
    static QString decode(const std::vector<uint64_t>& rhs, const QString& another);
    static bool isValideVoter(const QString& rhs);
    static QString getRandomNumberFromEncrypedInfo(const QString& rhs);
    static QString getIdStringFromEncrypedInfo(const QString& rhs);
    static std::vector<uint64_t> encodeSerialNumber(const QString& serialNum);
    static std::vector<uint64_t> encodeSerialMACv(const QString& macv);
    static void initializeEandN();
    static QString getNv(const QString& idString);
    static QString getNv();
    static QString getIdv();
    static void setNvAndIdv();
    static QString encodeSerialNumber();
private:
    static std::vector<uint64_t> encryptedInfo;
    static QString id;
    static std::string deencrypeInfoString;
    static int e;
    static int n;
    static QString nv;
    static QString idv;
    static QString encodeNv;
};

#endif // REGISTERCENTER_H
