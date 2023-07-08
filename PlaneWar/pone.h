#ifndef PONE_H
#define PONE_H
#include "config.h"
#include <QWidget>
#include<QTimer>
#include<QLabel>
#include<QString>
#include<QLayout>

namespace Ui {
class pone;
}

class pone : public QWidget
{
    Q_OBJECT

public:
    explicit pone(QWidget *parent = 0);
    ~pone();

private slots:
    void on_buttonone_clicked();

    void on_toolButton_clicked();

    void on_label_linkActivated(const QString &link);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::pone *ui;
};

#endif // PONE_H
