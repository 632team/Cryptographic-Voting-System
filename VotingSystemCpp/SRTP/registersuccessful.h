#ifndef REGISTERSUCCESSFUL_H
#define REGISTERSUCCESSFUL_H

#include <QDialog>

namespace Ui {
class RegisterSuccessful;
}

class RegisterSuccessful : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterSuccessful(QWidget *parent = 0);
    ~RegisterSuccessful();

private:
    Ui::RegisterSuccessful *ui;
};

#endif // REGISTERSUCCESSFUL_H
