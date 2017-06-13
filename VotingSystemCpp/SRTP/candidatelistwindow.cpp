#include "candidatelistwindow.h"
#include "ui_candidatelistwindow.h"
#include "dao.h"
#include <QDebug>
#include <QCheckBox>
#include <QListWidget>
#include <QListWidgetItem>
#include "voterhelp.h"

CandidateListWindow::CandidateListWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CandidateListWindow)
{
    qDebug() << "mmmmm";

    ui->setupUi(this);
     bool flag = QObject::connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(doubleclicked(QListWidgetItem*)));

    //show the candidate list
    //QObject::connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(candidateInfoShow(QListWidgetItem*)));
    //QObject::connect(ui->listWidget, SIGNAL(itemPressed(QListWidgetItem*)), this, SLOT(clear()));

    qDebug() << "flag : " << flag;
    qDebug() << "bind function here";
}

CandidateListWindow::~CandidateListWindow()
{
    delete ui;
}

void CandidateListWindow::initilize()
{
    QString sql = "select * from candidate_information";
    QSqlQuery result = Dao::findForResultSet(sql);
    ui->listWidget->clear();
    while(result.next()){
        qDebug() << result.value(1).toString();
        QListWidgetItem *listItem = new QListWidgetItem(result.value(1).toString());
        //QCheckBox *checkBox = new QCheckBox(result.value(1).toString());
        ui->listWidget->addItem(listItem);
        //ui->listWidget->setItemWidget(listItem, checkBox);
    }
    //candidateWindow.show();
    //candidateInfoShow(nullptr);
    return ;
}

void CandidateListWindow::candidateInfoShow(QListWidgetItem* item)
{
    //qDebug() << item->text();
    //qDebug() << "I want a window";
    candidateWindow.show();
}

void CandidateListWindow::on_pushButtonConfirm_pressed()
{
    this->hide();
    int nowPos = ui->listWidget->currentRow();
    int size = ui->listWidget->count();
    std::vector<uint64_t> ans(size);
    ans[nowPos] = 1;
    VoterHelp::voteContent = ans;
    qDebug() << "vote result is " << VoterHelp::voteContent.size();
    qDebug() << "size : " << size;
    qDebug() << "nowPos : " << nowPos;
}

void CandidateListWindow::doubleclicked(QListWidgetItem *item)
{
    qDebug() << "Find me";
    qDebug() << item->text();
    qDebug() << "end find";
    Candidate canTemp = Dao::getCandidateByName(item -> text());
    candidateWindow.inserInfo(canTemp);
    candidateWindow.show();
}

//void CandidateListWindow::on_pushButtonConfirm_clicked()
//{

//}
