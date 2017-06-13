#include "loginfailure.h"
#include "ui_loginfailure.h"

LoginFailure::LoginFailure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginFailure)
{
    ui->setupUi(this);
}

LoginFailure::~LoginFailure()
{
    delete ui;
}

void LoginFailure::on_pushButtonClose_pressed()
{
    this->hide();
}
