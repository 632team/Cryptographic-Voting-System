#ifndef VOTER_H
#define VOTER_H

#include <QApplication>

class Voter
{
public:
    Voter();
    ~Voter()= default;
    Voter(const Voter& rhs) = default;
    Voter& operator=(const Voter& rhs) = default;

public:
    bool isOk();
public:
    QString name;
    int age;
    QString sex;
    QString id;
    QString password;
    QString pub;
    QString Hv;
};

#endif // VOTER_H
