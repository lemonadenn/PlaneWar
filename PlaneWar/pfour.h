#ifndef PFOUR_H
#define PFOUR_H

#include <QWidget>
#include "config.h"

namespace Ui {
class pfour;
}

class pfour : public QWidget
{
    Q_OBJECT

public:
    explicit pfour(QWidget *parent = 0);
    ~pfour();

private slots:
    void on_pushButton_4_clicked();

private slots:
    void on_pushButton_3_clicked();
    
    void on_pushButton_5_clicked();

private:
    Ui::pfour *ui;
};

#endif // PFOUR_H
