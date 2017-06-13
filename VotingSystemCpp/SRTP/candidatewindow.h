#ifndef CANDIDATEWINDOW_H
#define CANDIDATEWINDOW_H

#include <QWidget>
#include <QPixmap>
#include "candidate.h"

namespace Ui {
class CandidateWindow;
}

class CandidateWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CandidateWindow(QWidget *parent = 0);
    ~CandidateWindow();
    void inserInfo(const Candidate& rhs);
private:
    Ui::CandidateWindow *ui;
    QPixmap picture;
};

#endif // CANDIDATEWINDOW_H
