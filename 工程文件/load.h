#ifndef LOAD_H
#define LOAD_H
#include <QPainter>
#include <QWidget>
#include<QStyleOption>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include "gamewidget.h"


namespace Ui {
class load;
}

class load : public QWidget
{
    Q_OBJECT

public:
    QString getname();
    explicit load(QWidget *parent = 0);
    ~load();
protected:
    void paintEvent(QPaintEvent *event);
private:
    gameWidget gw;
signals:
    void start();
private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::load *ui;
};

#endif // LOAD_H
