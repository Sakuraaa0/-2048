#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include "load.h"
#include "aboutwidget.h"

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::Welcome *ui;
    load t;
    aboutWidget w;
    Rank rw;
};

#endif // WELCOME_H
