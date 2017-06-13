#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <QApplication>

class Candidate
{
public:
    Candidate();
    ~Candidate() = default;
    Candidate(const Candidate& rhs) = default;
    Candidate& operator=(Candidate) = delete;
public:
    int srialNum;
    QString name;
    int age;
    QString sex;
    QString id;
    QString record;
    QString declaration;
    QString image;
};

#endif // CANDIDATE_H
