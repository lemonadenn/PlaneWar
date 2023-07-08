#ifndef PNINE_H
#define PNINE_H

#include <QWidget>

namespace Ui {
class pnine;
}

class pnine : public QWidget
{
    Q_OBJECT

public:
    explicit pnine(QWidget *parent = 0);
    ~pnine();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::pnine *ui;
};

#endif // PNINE_H
