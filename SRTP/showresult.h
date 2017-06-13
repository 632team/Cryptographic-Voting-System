#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QWidget>

namespace Ui {
class ShowResult;
}

class ShowResult : public QWidget
{
    Q_OBJECT

public:
    explicit ShowResult(QWidget *parent = 0);
    ~ShowResult();
private slots:
    void on_pushButton_pressed();

private:
    Ui::ShowResult *ui;
};

#endif // SHOWRESULT_H
