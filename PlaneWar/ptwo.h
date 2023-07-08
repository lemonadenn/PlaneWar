#ifndef PTWO_H
#define PTWO_H

#include <QWidget>
#include <QWidget>
#include<QTimer>
#include<QTime>
#include<QLabel>
#include<QString>
#include<QLayout>
#include<QLineEdit>
#include<QLayout>
#include "config.h"

namespace Ui {
class ptwo;
}

class ptwo : public QWidget
{
    Q_OBJECT

public:
    explicit ptwo(QWidget *parent = 0);
    ~ptwo();

private slots:
    void on_buttontwo_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ptwo *ui;
};

#endif // PTWO_H
