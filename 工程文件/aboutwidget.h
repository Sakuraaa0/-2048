#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QWidget>
#include<QIcon>
#define LABLESTYLE "QLabel {color: rgb(240,226,213);background: rgb(187,173,160);border-radius: 5px;}"

namespace Ui {
class aboutWidget;
}

class aboutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit aboutWidget(QWidget *parent = 0);
    ~aboutWidget();

private:
    Ui::aboutWidget *ui;
};

#endif // ABOUTWIDGET_H
