#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QDebug>
#include <QWidget>
#include "box.h"
#include <QTimer>
#include <QPushButton>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDateTime>
#include "winwidget.h"
#include "losewidget.h"
#include "archivewidget.h"
#include "rank.h"
#include"ai.h"

//美化用的stylesheet类
#define LABLESTYLE "QLabel {color: rgb(240,226,213);background: rgb(187,173,160);border-radius: 5px;}"
#define BTNSTYLE "QPushButton {color: rgb(240,226,213);background: rgb(187,173,160);border-radius: 5px;} QPushButton:pressed{color: white;background: orange;border-radius: 5px;}"

namespace Ui {
class gameWidget;
}

class gameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit gameWidget(QWidget *parent = 0);
    ~gameWidget();

    void keyPressEvent(QKeyEvent *);//键盘事件
    void setname(QString n);//设置玩家名
    void scorelist();//存储玩家名与最高分数
    QTimer * timer;//计时器

private:
    Ui::gameWidget *ui;
    QString name;//玩家名
    winWidget wt;//获胜界面
    loseWidget lt;//失败界面
    Rank rankw;//排行榜界面
    archivewidget at;//存档界面
    AI newai;
signals:

public slots:
    void changeStep();//步数改变槽函数
    void changeScore();//分数改变槽函数
    void changeHighscore();//最高分改变槽函数
};

#endif // GAMEWIDGET_H
