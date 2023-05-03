#ifndef RANK_H
#define RANK_H

#include <QWidget>
#include <QList>
#include <QFile>
#include <QString>
#include<QIcon>

namespace Ui {
class Rank;
}

struct node
{
    QString name;
    int score;
};

class Rank : public QWidget
{
    Q_OBJECT

public:
    explicit Rank(QWidget *parent = 0);
    void ranklist();
    ~Rank();

private:
    Ui::Rank *ui;
    QList<node> t;//玩家分数结构体链表
};

#endif // RANK_H
