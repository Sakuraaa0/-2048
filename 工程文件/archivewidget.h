#ifndef ARCHIVEWIDGET_H
#define ARCHIVEWIDGET_H

#include <QWidget>
#include <QString>
#include <QListWidget>
#include <QFile>
#include <QIcon>
#include <QFont>
#include <QPushButton>
#include <QDateTime>
#include <QDebug>
#include <iostream>
#include <QLabel>

#define LABLESTYLE "QLabel {color: rgb(240,226,213);background: rgb(187,173,160);border-radius: 5px;}"
#define BTNSTYLE "QPushButton {color: rgb(240,226,213);background: rgb(187,173,160);border-radius: 5px;} QPushButton:pressed{color: white;background: orange;border-radius: 5px;}"
#define LISTSTTLE "QListWidget {color: rgb(240,226,213);background: rgb(187,173,160);border-radius: 5px;}"
//存档信息结构体
struct archiveInfo
{
    int score; //存档分数
    int step; //存档步数
    QString date; //保存的时间
    int time[3]; //游戏用时
    int box[16]; //存档矩阵信息
    int countNumber; //存档非0格子数
};
namespace Ui {
class archivewidget;
}

class archivewidget : public QWidget
{
    Q_OBJECT

public:
    explicit archivewidget(QWidget *parent = nullptr);
    ~archivewidget();
    void getNowGameInfo(int nowScore, int nowStep, QString nowDate, int *nowTime, int *nowBox, int nowCount); //临时保存当前游戏信息
    void test1();
    void saveArchiveToFile(); //保存存档信息，未实现
    void readArchiveFromFile(); //读取存档信息
    void showArchiveList(); //展示存档信息
    void DeleteArchive(); //删除信息
    struct archiveInfo tmpArch;
    struct archiveInfo currentArch;
    QList <struct archiveInfo>archiveList;
private:
    Ui::archivewidget *ui;
signals:
    void returngame();
    void savegame();
    void readgame();
    void deletegame();
    void dClicked();
};

#endif // ARCHIVEWIDGET_H
