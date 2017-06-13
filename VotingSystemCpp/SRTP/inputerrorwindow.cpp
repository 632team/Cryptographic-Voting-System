#include "inputerrorwindow.h"
#include "ui_inputerrorwindow.h"

InputErrorWindow::InputErrorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputErrorWindow)
{
    ui->setupUi(this);
}

InputErrorWindow::~InputErrorWindow()
{
    delete ui;
}
