#include "dao.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

QSqlDatabase Dao::db = QSqlDatabase::addDatabase("QMYSQL");

Dao::Dao()
{
    //db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("139.224.134.144");
    //db.setPort(3306);
    db.setDatabaseName("cryptographic_voting_system");
    db.setUserName("root");
    db.setPassword("team632");
    if(!db.open()){
        qDebug()<<"Unable to open database";
    }else{
        qDebug()<<"Database connection established";
        qDebug()<<"hello zhao huan";
    }
}

Dao::~Dao()
{
    db.close();
}

Voter Dao::checkLogin(QString username, QString password, bool& flag)
{
    if (!db.open())
        return Voter();
    QSqlQuery query;
    QString statement = "select * from voter_information where voter_ic = '" + username + "' and voter_password = '" + password + "'";
    //QString statement = "select * from voter_information";

    query.exec(statement);
    qDebug() << statement;
    qDebug() << "here";
    qDebug() << "size is : " << query.size();

    if (query.size() == 1){
        flag = true;
        Voter voter;
        if (query.next()){
            qDebug() << query.value(1).toString();
            voter.name = query.value(1).toString();
            voter.age = query.value(2).toInt();
            voter.sex = query.value(3).toString();
            voter.id = query.value(4).toString();
        }
        return voter;
    }else{
        return Voter();
    }
    return Voter();
}

bool Dao::isConnected()
{
    return db.open();
}

QSqlQuery Dao::findForResultSet(QString sql)
{
    if (!isConnected())
        return QSqlQuery();
    QSqlQuery query;
    query.exec(sql);
    qDebug() << "find For ResultSet";
    qDebug() << sql;
    qDebug() << query.size();
    return query;
}

bool Dao::insertInfo(QString sql)
{
    if (!isConnected())
        return false;
    QSqlQuery query;
    return query.exec(sql);
}

bool Dao::updateInfo(QString sql)
{
    return insertInfo(sql);
}

bool Dao::deleteInfo(QString sql)
{
    return insertInfo(sql);
}

//INSERT INTO Persons VALUES ('Gates', 'Bill', 'Xuanwumen 10', 'Beijing')
bool Dao::insertVoterInfo(const Voter &voter)
{
    QString sql = "INSERT INTO `voter_information`(`voter_id`, `voter_name`, `voter_age`, `voter_sex`, `voter_ic`, "
                  "`voter_password`, `voter_public_key`, `Hv`, `av`) VALUES (NULL,'" + voter.name +"',"
            + QString::number(voter.age, 10) + ",'" + voter.sex + "','" + voter.id + "','" + voter.password + "','" + voter.pub +"','" + voter.Hv + "',NULL)";
    qDebug() << "sql is : " << sql << endl;
    QSqlQuery query;
    bool flag =  query.exec(sql);
    qDebug() << "flag is : " << flag;
    return flag;
}

Candidate Dao::getCandidateById(int id)
{
    QString sql = "select * from candidate_information where candidate_id = '" + QString::number(id, 10)+ "'";
    QSqlQuery resultSet = findForResultSet(sql);
    if (resultSet.size() <= 0)
        return Candidate();
    return Candidate();
}

Candidate Dao::getCandidateByName(const QString &name)
{
    QString sql = "select * from candidate_information where candidate_name = '" + name + "'";
    QSqlQuery resultSet = findForResultSet(sql);
    if (resultSet.next()){
        Candidate canTemp;
        canTemp.srialNum = resultSet.value(0).toInt();
        canTemp.name = resultSet.value(1).toString();
        canTemp.age = resultSet.value(2).toInt();
        canTemp.sex = resultSet.value(3).toString();
        canTemp.id = resultSet.value(4).toString();
        canTemp.record = resultSet.value(5).toString();
        canTemp.declaration = resultSet.value(6).toString();
        canTemp.image = resultSet.value(7).toString();
        return canTemp;
    }
    return Candidate();
}

bool Dao::isValideVoter(const QString &rhs)
{
    QString sql = "select * from valid_voter where voter_ic = '" + rhs + "'";
    QSqlQuery resultSet = findForResultSet(sql);
    if (resultSet.size() <= 0){
        return false;
    }
    qDebug() << "valid voter";
    return true;
}

QString Dao::getPublicKeyAndPrim(const QString& rhs)
{
    QString sql = "SELECT * FROM `public_key_system` WHERE system_name = '" + rhs + "'";
    QSqlQuery resultSet = findForResultSet(sql);
    if (resultSet.next()){
        return resultSet.value(1).toString();
    }
    return "null";
}

int Dao::getPublicKey(const QString& systemName)
{
    QString sql = "SELECT * FROM `public_key_system` WHERE system_name = '" + systemName + "'";
    QSqlQuery resultSet = findForResultSet(sql);
    QString whole;
    if (resultSet.next()){
        whole = resultSet.value(1).toString();
    }
    int i = 0;
    std::string temp = whole.toStdString();
    int length = temp.size();
    int sum = 0;
    for (int i = 0; i < length; ++i){
        if (temp[i] == '#'){
            break;
        }else{
            sum *= 10;
            sum += temp[i] - '0';
        }
    }
    qDebug() << "public key is : " << sum;
    return sum;
}

int Dao::getPrivateKey(const QString &systemName)
{
    QFile file(systemName);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString temp;
    in >> temp;
    std::string newTemp = temp.toStdString();
    int i = 0;
    int length = newTemp.size();
    int sum = 0;
    while (i < length && newTemp[i] != '#'){
        sum *= 10;
        sum += newTemp[i] - '0';
    }
    qDebug() << "privateKey is " << sum;
    return sum;
}

int Dao::getPrim(const QString& systemName)
{
    QFile file(systemName);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString temp;
    in >> temp;
    std::string newTemp = temp.toStdString();
    int i = 0;
    int length = newTemp.size();
    int sum = 0;
    while (i < length && newTemp[i] != '#'){
        ++i;
    }
    ++i;
    while (i < length){
        sum *= 10;
        sum += newTemp[i] - '0';
    }
    qDebug() << "prim is : " << sum;
    return sum;
}




