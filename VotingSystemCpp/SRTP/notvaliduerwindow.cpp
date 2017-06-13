#include "notvaliduerwindow.h"
#include "ui_notvaliduerwindow.h"

NotValidUerWindow::NotValidUerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotValidUerWindow)
{
    ui->setupUi(this);
}

NotValidUerWindow::~NotValidUerWindow()
{
    delete ui;
}
