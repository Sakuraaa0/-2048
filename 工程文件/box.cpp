#include "box.h"
#include "ui_box.h"
#include "ai.h"
Box::Box(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Box)
{
    ui->setupUi(this);
    connect(&time,&QTimer::timeout,[=](){
        update();
    });//连接计时器和绘画
    step = 0;//当前步数位0
    Score = 0;//当前分数位0
    countNumber = 2;//初始有数字的方块数位2
    gethighScore();//初始化最高分
    memset(box, 0, sizeof(box));//初始全部方块为0
    rand2box();
}

//不同数字背景颜色
QColor no_color[12] = {  QColor(204,192,178),//0
                                        QColor(240,226,213),//2
                                        QColor(230,220,200),//4
                                        QColor(240,180,120),//8
                                        QColor(244,150,95),//16
                                        QColor(248,120,70),//32
                                        QColor(252,90,45),//64
                                        QColor(237,210,115),//128
                                        QColor(237,190,90),//256
                                        QColor(237,170,65),//512
                                        QColor(237,150,40),//1024
                                        QColor(237,130,15)//2048
                                     };
//输入2048游戏中数字 返回对应颜色在no_color中的下标
int getno(int temp)
{
    int k=0;
    while(1)
    {
        temp/=2;
        k++;
        if(temp==1)
            break;
    }
    return k;
}

//初始化两个方块
void Box::rand2box()
{
    box[rand() % 4][rand() % 4] = 2;//随机一个方块为2
    int i = rand() % 4;
    int j = rand() % 4;//随机另一个方块
    while (box[i][j] != 0)
    {
        i = rand() % 4;
        j = rand() % 4;//使随机的第二个方块不和第一个方块相同
    }
    box[i][j] = 2;//初始为2
}
//重新开始
void Box::restart()
{

    step = 0;
    Score = 0;
    countNumber = 2;
    gethighScore();
    memset(box, 0, sizeof(box));
    rand2box();
    emit scorechange();//分数改变信号
    emit stepchange();//步数改变信号
    update();


}

//重新开始重载
void Box::restart(int tmpScore, int tmpStep, int tmpCount, int *tmpBox)
{
    step = tmpStep;
    Score = tmpScore;
    countNumber = tmpCount;
    gethighScore();
    int x=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            box[i][j] = tmpBox[x];
            x++;
        }
    }
    emit scorechange();//分数改变信号
    emit stepchange();//步数改变信号
    update();
}
void Box::aihelp()
{

    AI newai(this);

int t=newai.getBestMove();
    if(t==3)
        this->change(RIGHT);
    if(t==2)
       this->change(LEFT);
   if(t==0)
        this->change(UP);
   if(t==1)
        this->change(DOWN);
   emit scorechange();//分数改变信号
   emit stepchange();//步数改变信号
   update();
}
//输出（i，j）的数 （1，1）—（4，4）
int Box::output(int i, int j)
{
    return box[i-1][j-1];
}
//返回当前得分
int Box::nowScore()
{
    return Score;
}
//返回步数
int Box::countStep()
{
    return step;
}
//交换函数
bool Box::Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
    return true;
}
//读取最高分文件，存入hScore
void Box::gethighScore()
{
    hScore=0;
    QFile file("hscore.cr");
    if (file.open(QIODevice::ReadOnly))//无最高分文件是不读取
    {
        file.read((char *)&hScore, sizeof(hScore));
        file.close();
        emit hscorechange();//最高分改变信号
    }
}
//修改最高分
void Box::sethighScore()
{
    if (Score > hScore)//仅当当前分数大于最高分数修改
    {
        hScore = Score;
        // 将新的最高分存入文件
        QFile file("hscore.cr");
        file.open(QIODevice::WriteOnly);
        file.write((char *)&hScore, sizeof(hScore));
        file.close();
        emit hscorechange();//最高分改变信号
    }
}
//返回最高分
int Box::higeScore()
{
    return hScore;
}

//游戏实现
void Box::change(MOVE t)
{
    if(!cr.isEmpty())
        return;//防止动画绘制完成之前再次输入
    update();
    Cartoon tempcr;//储存临时动画信息
    bool flag1 = false;//记录是否有移动
    bool flag2 = false;//记录是否有方块相加
    bool flag[4][4];//记录格子是否参加过合并
    memset(flag, false, sizeof(flag));//初始化
    int i, j, k;
    switch (t)
    {
    case UP:
        for (i = 0; i < 4; i++)//逐列计算
        {
            k = 0;
            for(j=0;j<4;j++)
            {
                if(box[j][i] == 0)//跳到第一个不为零的方块
                    continue;
                if(j != k)
                    flag1 = Swap(box[j][i], box[k][i]);//交换（j,i）(k,i) 并记录存在方块移动
                tempcr.KIND = true;
                tempcr.start = QPointF(5+97.75*i,5+97.75*j);
                tempcr.end = QPointF(5+97.75*i,5+97.75*k);
                tempcr.d = t;
                tempcr.number = box[k][i];//记录动画信息
                if (k > 0 && box[k][i] == box[k - 1][i] && !flag[k - 1][i])//相邻两数相同相加，记录加过的位值防止连加
                {
                    box[k - 1][i] <<= 1;//被加位乘2
                    box[k][i] = 0;//加位置0
                    Score += box[k - 1][i];//分数增加为合并获得的数
                    countNumber--;//非零数字位数-1
                    flag[k - 1][i] = true;//该格子已参加过合并
                    flag2 = true;//存在方块相加
                    tempcr.end = QPointF(5+97.75*i,5+97.75*(k-1));//记录动画信息
                    emit scorechange();//发出分数改变信后
                }
                else//相邻两数不同，k进位
                    k++;
                cr.append(tempcr);//将动画信息加入链表
            }
        }
        break;
        //下面三种运算原理相同，不再注释
    case DOWN:
        for (i = 0; i < 4; i++)
        {
            k = 3;
            for(j=3;j>=0;j--)
            {
                 if(box[j][i] == 0)
                    continue;
                if(j != k)
                    flag1 = Swap(box[j][i], box[k][i]);
                tempcr.KIND = true;
                tempcr.start = QPointF(5+97.75*i,5+97.75*j);
                tempcr.end = QPointF(5+97.75*i,5+97.75*k);
                tempcr.d = t;
                tempcr.number = box[k][i];
                if (k < 3 && box[k][i] == box[k + 1][i] && !flag[k + 1][i])
                {
                    box[k + 1][i] <<= 1;
                    flag[k + 1][i] = true;
                    box[k][i] = 0;
                    Score += box[k + 1][i];
                    countNumber--;
                    flag2 = true;
                    tempcr.end = QPointF(5+97.75*i,5+97.75*(k+1));
                    emit scorechange();
                }
                else
                    k--;
                cr.append(tempcr);
            }
        }
        break;
    case LEFT:
        for (i = 0; i < 4; i++)
        {
            k = 0;
            for(j=0;j<4;j++)
            {
                if(box[i][j] == 0)
                    continue;
                if(j != k)
                    flag1 = Swap(box[i][j], box[i][k]);
                tempcr.KIND = true;
                tempcr.start = QPointF(5+97.75*j,5+97.75*i);
                tempcr.end = QPointF(5+97.75*k,5+97.75*i);
                tempcr.d = t;
                tempcr.number = box[i][k];
                if (k > 0 && box[i][k] == box[i][k - 1] && !flag[i][k - 1])
                {
                    box[i][k - 1] <<= 1;
                    box[i][k] = 0;
                    flag[i][k - 1] = true;
                    Score += box[i][k - 1];
                    countNumber--;
                    flag2 = true;
                    tempcr.end = QPointF(5+97.75*(k-1),5+97.75*i);
                    emit scorechange();
                }
                else
                    k++;
                cr.append(tempcr);
            }
        }
        break;
    case RIGHT:
        for (i = 0; i < 4; i++)
        {
            k = 3;
            for(j=3;j>=0;j--)
            {
                if (box[i][j] == 0)
                    continue;
                if(j !=k)
                    flag1 = Swap(box[i][j], box[i][k]);
                tempcr.KIND = true;
                tempcr.start = QPointF(5+97.75*j,5+97.75*i);
                tempcr.end = QPointF(5+97.75*k,5+97.75*i);
                tempcr.d = t;
                tempcr.number = box[i][k];
                if (k < 3 && box[i][k] == box[i][k + 1] && !flag[i][k + 1])
                {
                    box[i][k + 1] <<= 1;
                    box[i][k] = 0;
                    flag[i][k + 1] = true;
                    Score += box[i][k + 1];
                    countNumber--;
                    flag2 = true;
                    tempcr.end = QPointF(5+97.75*(k+1),5+97.75*i);
                    emit scorechange();
                }
                else
                    k--;
                cr.append(tempcr);
            }
        }
        break;
    }
    if (flag1 || flag2)//存在有效移动或方块相加
    {
        step++;//步数加一
        emit stepchange();
        sethighScore();//修改最高分
        int m = rand() % 4, n = rand() % 4;
        while (box[m][n] != 0)
        {
            m = rand() % 4;
            n = rand() % 4;
        }
            box[m][n]=2;
        countNumber++;//非零方块个数+1
        tempcr.KIND = false;
        tempcr.number = box[m][n];
        tempcr.end = QPointF(5+97.75*n,5+97.75*m);
        tempcr.start = QPointF(5+97.75*n+41.7375,5+97.75*m+41.7375);
        cr.append(tempcr);
    }
    time.start(1);//启动计时器，开始绘制动画

    //检测游戏输赢
    if(countNumber == 16)
    {
        checkLose();
    }
    checkWin();
}

Box::~Box()
{
    //delete ui;
}

//检测是否输了
bool Box::checkLose()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j != 3 && box[i][j] == box[i][j+1])//存在相邻相等方块则没输
                return true;
            if (i != 3 && box[i][j] == box[i+1][j])
                return true;
        }
    }
    emit lose();
    return false;
}
//检测是否获胜
bool Box::checkWin()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (box[i][j] == 2048)
            {
                emit win();
                return true;
            }
    return false;
}

//重载绘图事件
//小方格边长92.75 间距5
//(i,j)小方格left-top计算公式(5+97.75*j,5+97.75*i)
void Box::paintEvent(QPaintEvent *)
{
    //绘制游戏区域背景色
    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);// 反锯齿
    QBrush brush(QColor(187,173,160));
    painter.setBrush(brush);//使用画刷
    painter.setPen(Qt::NoPen);//设置无画笔
    painter.drawRoundedRect(QRectF(0 , 0, 396, 396), 5, 5);// 绘制一个矩形

    // 创建数字用的字体
    QFont font;
    font.setFamily("arial");
    font.setBold(true);
    font.setPixelSize(40);
    painter.setFont(font);

    if(!cr.isEmpty())//如果动画链表不为空
    {
        QList<Cartoon>::iterator ccr;
        bool t = true;
        brush.setColor(no_color[0]);
        painter.setBrush(brush);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                painter.drawRoundedRect(QRectF(5+97.75*j,5+97.75*i,92.75,92.75),5,5);//依次绘制每一个小方格为初始颜色
        for(ccr=cr.begin();ccr!=cr.end();ccr++)//绘制动画
            if(!play(painter,*ccr))
                t = false;//动画没有画完
        if(t == false)
            return;
        else
            cr.clear(),time.stop();//动画画完，清空寄存器，停止计时器
    }

    //绘制游戏面板
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(box[i][j]!=0)
            {
                QColor t = no_color[getno(box[i][j])];
                brush.setColor(t);
                painter.setBrush(brush);//设置绘制小方块的画刷
                painter.drawRoundedRect(QRectF(5+97.75*j,5+97.75*i,92.75,92.75),5,5);//绘制小方块
                if(box[i][j]==2||box[i][j]==4)
                    painter.setPen(QColor(123,113,104));//设置画笔颜色
                else
                    painter.setPen(QColor(255,250,250));//设置画笔颜色
                //画上对应数字
                painter.drawText(QRectF(5+97.75*j,5+97.75*i,92.75,92.75),Qt::AlignCenter,QString::number(box[i][j]));
                painter.setPen(Qt::NoPen);
            }
            else
            {
                brush.setColor(no_color[0]);
                painter.setBrush(brush);//设置绘制小方块的画刷
                painter.drawRoundedRect(QRectF(5+97.75*j,5+97.75*i,92.75,92.75),5,5);//绘制小方块
            }
        }
    }
}

bool Box::play(QPainter& painter,Cartoon& t)
{
    bool flag = false;
    QBrush brush(Qt::SolidPattern);
    if(!t.KIND)//出现动画
    {
        if(t.start.x()>t.end.x())
            t.start += QPointF(-0.8,-0.8);
        else
        {
            t.start=t.end;
            flag = true;
        }
        brush.setColor(no_color[1]);
        painter.setBrush(brush);
        painter.drawRoundedRect(QRectF(t.start.x(), t.start.y(), 92.75-2*(t.start.x()-t.end.x()), 92.75-2*(t.start.x()-t.end.x())),5,5);
        painter.setPen(QColor(123,113,104));
        painter.drawText(QRectF(t.end.x(),t.end.y(),92.75,92.75),Qt::AlignCenter,"2");
        painter.setPen(Qt::NoPen);
    }
    else if(t.KIND)//移动动画
    {
        if(t.d == LEFT)//左
        {
            if(t.start.x()>t.end.x())
                t.start += QPointF(-2.5,0);
            else
            {
                t.start = t.end;
                flag = true;
            }
        }
        else if(t.d == RIGHT)//右
        {
            if(t.start.x()<t.end.x())
                t.start += QPointF(2.5,0);
            else
            {
                t.start = t.end;
                flag = true;
            }
        }
        else if(t.d == UP)//上
        {
            if(t.start.y()>t.end.y())
                t.start += QPointF(0,-2.5);
            else
            {
                t.start = t.end;
                flag = true;
            }
        }
        else if(t.d == DOWN)//下
        {
            if(t.start.y()<t.end.y())
                t.start += QPointF(0,2.5);
            else
            {
                t.start = t.end;
                flag = true;
            }
        }
        brush.setColor(no_color[getno(t.number)]);
        painter.setBrush(brush);
        painter.drawRoundedRect(QRectF(t.start,QSizeF(92.75,92.75)),5,5);
        if(t.number == 2 || t.number == 4)
            painter.setPen(QColor(123,113,104));//设置画笔颜色
        else
            painter.setPen(QColor(255,250,250));//设置画笔颜色
        //画上对应数字
        painter.drawText(QRectF(t.start,QSizeF(92.75,92.75)),Qt::AlignCenter,QString::number(t.number));
        painter.setPen(Qt::NoPen);
    }
    return flag;
}

//返回当前游戏矩阵，用作存档用
int Box::nowbox(int i, int j)
{
    return box[i][j];
}

//返回当前游戏非零格子数
int Box::nowCountNum()
{
    return countNumber;
}


