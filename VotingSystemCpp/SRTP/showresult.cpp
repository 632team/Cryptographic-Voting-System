#include "showresult.h"
#include "ui_showresult.h"
#include <QDebug>
#include "dao.h"
#include <QSqlQuery>
#include <vector>
#include <string>
#include "voterhelp.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>
#include <fstream>
#include <sstream>

ShowResult::ShowResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowResult)
{
    ui->setupUi(this);
}

ShowResult::~ShowResult()
{
    delete ui;
}

void ShowResult::on_pushButton_pressed()
{
    QString sql = "SELECT * FROM `voter_information`";
    QSqlQuery resultSet = Dao::findForResultSet(sql);
    std::vector<long> countResult(100, 0);
    std::vector<QString> toCalu;
    int cnt1 = 0;
    while (resultSet.next()){
        std::string fileName = resultSet.value(4).toString().toStdString() + "_Info";
        QFile tempFile(QString::fromStdString(fileName));
        if (tempFile.exists()){
            std::fstream file(fileName, fstream::in);
            std::stringstream ss;
            ss << file.rdbuf();
            file.close();
            std::string readFromFile(ss.str());
            QString nowFromFile = StdStringConvertQString(readFromFile);
            toCalu.push_back(nowFromFile);
            qDebug() << QString::fromStdString(fileName);
        }
    }
    countResult = VoterHelp::fhe_solve.calSum(toCalu);
    qDebug() << "wo zai zhe er";
    for (int i = 0; i < 3; ++i){
        qDebug() << countResult[i];
    }
    qDebug() << "show new graph";
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    QCPBars *fossil = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    fossil->setAntialiased(false);
    fossil->setStackingGap(1);
    fossil->setName("票数");

    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(255, 255, 255));

    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3;
    labels << "LiangXianFeng" << "ZhaoHuan" << "WangChenchen";

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    //gaodu
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);
    //ui->customPlot->xAxis->setAutoTickStep(false);
    //ui->customPlot->

    ui->customPlot->yAxis->setRange(0, 5);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("票数");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    //ui->customPlot->yAxis->setTickLength(1);

    QVector<double> fossilData;
    for (int i = 0; i < 3; ++i){
        fossilData << countResult[i];
    }
    fossil->setData(ticks, fossilData);


    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->customPlot->replot();
    //this -> hide();
    return ;
}
