#ifndef PEIGHT_H
#define PEIGHT_H

#include <QWidget>

namespace Ui {
class peight;
}

class peight : public QWidget
{
    Q_OBJECT

public:
    explicit peight(QWidget *parent = 0);
    ~peight();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::peight *ui;
};

#endif // PEIGHT_H
