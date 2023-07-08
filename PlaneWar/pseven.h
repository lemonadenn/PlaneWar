#ifndef PSEVEN_H
#define PSEVEN_H

#include <QWidget>

namespace Ui {
class pseven;
}
class QLabel;
class QListWidget;


class pseven : public QWidget
{
    Q_OBJECT

public:
    explicit pseven(QWidget *parent = 0);
    ~pseven();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();
    /*void slotBtnEnter(); //点击“Enter”按钮，新增一条子窗口

    void slotLeave();

    void InitWidget();

    void on_pBtnEnter_clicked();*/

private:
    Ui::pseven *ui;

    /*QLabel* m_pLbTest1; //初始化用

    QListWidget* m_pListWidget;*/
};

#endif // PSEVEN_H
