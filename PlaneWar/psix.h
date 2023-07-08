#ifndef PSIX_H
#define PSIX_H

#include <QWidget>

namespace Ui {
class psix;
}

class psix : public QWidget
{
    Q_OBJECT

public:
    explicit psix(QWidget *parent = 0);
    ~psix();

private slots:
    void on_pushButton_5_clicked();

private slots:
    void on_pushButton_3_clicked();
    
    void on_pushButton_4_clicked();

private:
    Ui::psix *ui;
};

#endif // PSIX_H
