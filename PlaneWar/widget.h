#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include<QTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_Widget_destroyed();

    void on_buttonzero_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
