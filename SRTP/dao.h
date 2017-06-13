#ifndef DAO_H
#define DAO_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include "voter.h"
#include "candidate.h"

class Dao
{
public:
    Dao();
    ~Dao();
public:
    static Voter checkLogin(QString username, QString password, bool& flag);
    static bool isConnected();
    static QSqlQuery findForResultSet(QString sql);
    static bool insertInfo(QString sql);
    static bool updateInfo(QString sql);
    static bool deleteInfo(QString sql);
    static bool insertVoterInfo(const Voter& voter);
    static Candidate getCandidateById(int id);
    static Candidate getCandidateByName(const QString& name);
    static bool isValideVoter(const QString& rhs);
    static QString getPublicKeyAndPrim(const QString& rhs);
    static int getPublicKey(const QString& systemName);
    static int getPrivateKey(const QString& systemName);
    static int getPrim(const QString& systemName);
private:
    static QSqlDatabase db;
};
#endif // DAO_H
