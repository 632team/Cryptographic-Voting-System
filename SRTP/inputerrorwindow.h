#ifndef INPUTERRORWINDOW_H
#define INPUTERRORWINDOW_H

#include <QDialog>

namespace Ui {
class InputErrorWindow;
}

class InputErrorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InputErrorWindow(QWidget *parent = 0);
    ~InputErrorWindow();

private:
    Ui::InputErrorWindow *ui;
};

#endif // INPUTERRORWINDOW_H
