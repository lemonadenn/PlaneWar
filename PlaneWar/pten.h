#ifndef PTEN_H
#define PTEN_H

#include <QWidget>

namespace Ui {
class pten;
}

class pten : public QWidget
{
    Q_OBJECT

public:
    explicit pten(QWidget *parent = 0);
    ~pten();

private:
    Ui::pten *ui;
};

#endif // PTEN_H
