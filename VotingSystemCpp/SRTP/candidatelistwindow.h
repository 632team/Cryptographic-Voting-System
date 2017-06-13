#ifndef CANDIDATELISTWINDOW_H
#define CANDIDATELISTWINDOW_H

#include <QWidget>
#include <QListWidget>
#include "candidatewindow.h"
#include "ui_candidatewindow.h"

namespace Ui {
class CandidateListWindow;
}

class CandidateListWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CandidateListWindow(QWidget *parent = 0);
    ~CandidateListWindow();
    void initilize();
private slots:
//    void QListWidget::itemDoubleClicked(QListWidgetItem *item)
    void candidateInfoShow(QListWidgetItem*);
    void on_pushButtonConfirm_pressed();
    void doubleclicked(QListWidgetItem* item);
    //void on_pushButtonConfirm_clicked();

private:
    Ui::CandidateListWindow *ui;
    CandidateWindow candidateWindow;
};

#endif // CANDIDATELISTWINDOW_H
