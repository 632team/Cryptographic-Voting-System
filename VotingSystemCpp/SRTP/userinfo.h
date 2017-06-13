#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include "voter.h"
#include "candidatelistwindow.h"
#include "ui_candidatelistwindow.h"

namespace Ui {
class userInfo;
}

class userInfo : public QWidget
{
    Q_OBJECT

public:
    explicit userInfo(QWidget *parent = 0);
    ~userInfo();
public:
    void initilize(const Voter& rhs);
private slots:
    void on_pushButtonCandidate_pressed();

    void on_pushButton_pressed();

private:
    Ui::userInfo *ui;
    CandidateListWindow candidateList;
};

#endif // USERINFO_H
