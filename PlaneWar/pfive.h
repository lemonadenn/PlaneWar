#ifndef PFIVE_H
#define PFIVE_H

#include <QWidget>
#include "config.h"

namespace Ui {
class pfive;
}

class pfive : public QWidget
{
    Q_OBJECT

public:
    explicit pfive(QWidget *parent = 0);
    ~pfive();

private slots:
    void on_pushButton_4_clicked();

private slots:
    void on_pushButton_3_clicked();
    
    void on_pushButton_5_clicked();

private:
    Ui::pfive *ui;
};

#endif // PFIVE_H
