#include "registersuccessful.h"
#include "ui_registersuccessful.h"

RegisterSuccessful::RegisterSuccessful(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterSuccessful)
{
    ui->setupUi(this);
}

RegisterSuccessful::~RegisterSuccessful()
{
    delete ui;
}
