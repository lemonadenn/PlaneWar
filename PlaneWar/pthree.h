#ifndef PTHREE_H
#define PTHREE_H

#include <QWidget>
#include "config.h"

namespace Ui {
class pthree;
}

class pthree : public QWidget
{
    Q_OBJECT

public:
    explicit pthree(QWidget *parent = 0);
    ~pthree();

private slots:
    void on_pushButton_4_clicked();

private slots:
    void on_pushButton_3_clicked();
    
    void on_pushButton_5_clicked();

private:
    Ui::pthree *ui;
};

#endif // PTHREE_H
