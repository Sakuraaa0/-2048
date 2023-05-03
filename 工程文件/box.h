#ifndef BOX_H
#define BOX_H

#include <QWidget>
#include <QFile>
#include <QPainter>
#include <QFont>
#include <QPushButton>
#include <QList>
#include <QTimer>
#include<cmath>

struct SearchResult {
     int move;
     double score;
     int positions;
     int cutoffs;
};
enum MOVE
{
    UP, DOWN, LEFT, RIGHT
};//游戏操作枚举

struct Cartoon
{
    MOVE d;//记录方向
    bool KIND;//动画类型，true是移动，false是出现
    QPointF start;//起始坐标点
    QPointF end;//结束坐标点
    int number;//对应数字
};//动画信息结构体

namespace Ui {
class Box;
}

class Box : public QWidget
{
    Q_OBJECT

public:
    explicit Box(QWidget *parent = 0);
    ~Box();
     Box(Box& a)
     {
         for(int i=0;i<4;i++)
             for(int j=0;j<4;j++)
             {
                 this->box[i][j]=a.box[i][j];
             }
     }
    void restart();//重新开始
    void restart(int tmpScore, int tmpStep, int tmpCount, int *tmpBox); //重载重新开始
    void aihelp();//ai帮助
    int output(int i,int j);//返回（i，j）的数
    void rand2box();//2的随机出现位置
    int nowScore();//返回现在的分数
    void change(MOVE t);//游戏实现函数
    int higeScore();//返回最高分
    void sethighScore();//修改最高分
    void gethighScore();//获得最高分
    int countStep();//返回步数
    int nowbox(int i, int j); //返回当前游戏矩阵
    int nowCountNum(); //返回当前游戏非0格子数
    bool checkLose();//检测游戏是否结束
    bool checkWin();//检测游戏是否获胜
    bool Swap(int& a, int& b);//交换函数
    void paintEvent(QPaintEvent *);//绘图事件重载
    bool play(QPainter& painter,Cartoon& t);//动画
     void box_get(int i,int j,int a)
     {
         this->box[i][j]=a;
     }
    int givebox(int m,int n)
    {

        int a=this->box[m][n];
        return a;
    }

    protected:
    Ui::Box *ui;

    QList<Cartoon> cr;//动画信息链表
    QTimer time;
    int box[4][4];//储存每个格子的值
    int step;//步数
    int Score;//当前积分
    int countNumber;//统计非零数字个数
    int hScore;//最高分
signals:
    void win();//获胜信号
    void lose();//失败信号
    void stepchange();//步数改变信号
    void scorechange();//分数改变信号
    void hscorechange();//最高分变化信号
};



#endif // BOX_H
