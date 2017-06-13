#ifndef NOTVALIDUERWINDOW_H
#define NOTVALIDUERWINDOW_H

#include <QWidget>

namespace Ui {
class NotValidUerWindow;
}

class NotValidUerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NotValidUerWindow(QWidget *parent = 0);
    ~NotValidUerWindow();

private:
    Ui::NotValidUerWindow *ui;
};

#endif // NOTVALIDUERWINDOW_H
