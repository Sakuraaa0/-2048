#include "gamewidget.h"
#include "ui_gamewidget.h"

gameWidget::gameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameWidget)
{
    ui->setupUi(this);
    //美化
    this->setStyleSheet("background-color: rgb(251,248,239)");
    setWindowIcon(QIcon(":/image/windowicon.png"));//修改窗口图标
    ui->restartbutton->setStyleSheet(QString(BTNSTYLE));
    ui->highscorelabel->setStyleSheet(QString(LABLESTYLE));
    ui->scorelabel->setStyleSheet(QString(LABLESTYLE));
    ui->steplabel->setStyleSheet(QString(LABLESTYLE));
    ui->timelabel->setStyleSheet(QString(LABLESTYLE));
    ui->highscorelabel->setText(QString("Best:\n%1").arg(ui->b2048->higeScore()));//最高分Label初始化
    ui->aihelp->setStyleSheet(QString(BTNSTYLE));
    ui->archive->setStyleSheet(QString(BTNSTYLE));
    //计时器
    static int tmin=0,tsec=1,thour=0;
    timer = new QTimer(this);
    ui->timelabel->setText("00 : 00 : 00");
    connect(timer,&QTimer::timeout,[=](){
        QString timex;
        timex=timex=QString("%1").arg(thour,2,10,QLatin1Char('0'))+" : "+QString("%1").arg(tmin,2,10,QLatin1Char('0'))+" : "+QString("%1").arg(tsec,2,10,QLatin1Char('0'));
        ui->timelabel->setText(timex);
        tsec++;
        if(tsec==60)
        {
            tsec=0;
            tmin++;
        }
        if(tmin==60)
        {
            tmin=0;
            thour++;
        }
    });

    //重新开始
    connect(ui->restartbutton,&QPushButton::clicked,[=](){
        ui->b2048->restart();
        timer->stop();
        tmin=0;//重置计时器
        tsec=1;
        thour=0;
        ui->timelabel->setText("00 : 00 : 00");
        timer->start(1000);
    });

    //AI帮助
    connect(ui->aihelp,&QPushButton::clicked,[=](){
        ui->b2048->aihelp();

    });

    //存档
    connect(ui->archive,&QPushButton::clicked,[=](){
        int tmpScore = ui->b2048->nowScore();
        int tmpStep = ui->b2048->countStep();
        int tmpBox[16];
        int x=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                tmpBox[x] = ui->b2048->nowbox(i, j);
                x++;
            }
        }
        QDateTime tmpDate1 = QDateTime::currentDateTime();
        QString tmpDate2 = tmpDate1.toString("yyyy.MM.dd hh:mm:ss ddd");
        int tmpTime[3] = {thour,tmin,tsec};
        int tmpCount = ui->b2048->nowCountNum();

        at.getNowGameInfo(tmpScore, tmpStep, tmpDate2, tmpTime, tmpBox, tmpCount);
        at.showArchiveList();
        timer->stop();
        this->setDisabled(true);
        //at.test1();
        at.show();

    });

    //信号与槽函数连接
    connect(ui->b2048,&Box::stepchange,this,&gameWidget::changeStep);
    connect(ui->b2048,&Box::scorechange,this,&gameWidget::changeScore);
    connect(ui->b2048,&Box::hscorechange,this,&gameWidget::changeHighscore);
    connect(ui->b2048,&Box::win,[=](){
        timer->stop();
        this->setDisabled(true);
        wt.setlabel(ui->b2048->nowScore());
        scorelist();
        wt.show();
    });//获胜界面
    connect(ui->b2048,&Box::lose,[=](){
        timer->stop();
        this->setDisabled(true);
        lt.setlabel(ui->b2048->nowScore());
        scorelist();
        lt.show();
    });//失败界面
    connect(&wt,&winWidget::newgame,[=](){
        wt.close();
        this->setDisabled(false);
        ui->b2048->restart();
        timer->stop();
        tmin=0;//重置计时器
        tsec=1;
        ui->timelabel->setText("00 : 00 : 00");
        timer->start(1000);
    });//获胜新游戏
    connect(&lt,&loseWidget::newgame,[=](){
        lt.close();
        this->setDisabled(false);
        ui->b2048->restart();
        timer->stop();
        tmin=0;//重置计时器
        tsec=1;
        ui->timelabel->setText("00 : 00 : 00");
        timer->start(1000);
    });//失败新游戏
    connect(&wt,&winWidget::quit,[=](){
        qApp->quit();
    });
    connect(&lt,&loseWidget::quit,[=](){
        qApp->quit();
    });//退出
    connect(&wt,&winWidget::rank,[=](){
        rankw.ranklist();
        rankw.show();//排行榜界面
    });
    connect(&lt,&loseWidget::rank,[=](){
        rankw.ranklist();
        rankw.show();//排行榜界面
    });
    connect(&at,&archivewidget::returngame,[=](){
        at.close();
        this->setDisabled(false);
        ui->b2048->restart(at.tmpArch.score, at.tmpArch.step, at.tmpArch.countNumber, at.tmpArch.box);
        timer->stop();
        tsec=at.tmpArch.time[2] - 1;//重置计时器
        tmin=at.tmpArch.time[1];
        thour = at.tmpArch.time[0];
        timer->start(1000);
    });//由存档界面返回游戏界面
    connect(&at,&archivewidget::readgame,[=](){
        at.close();
        this->setDisabled(false);
        ui->b2048->restart(at.currentArch.score, at.currentArch.step, at.currentArch.countNumber, at.currentArch.box);
        timer->stop();
        tsec=at.currentArch.time[2] - 1;//重置计时器
        tmin=at.currentArch.time[1];
        thour = at.currentArch.time[0];
        timer->start(1000);
    });//读取存档
    connect(&at,&archivewidget::dClicked,[=](){
        at.close();
        this->setDisabled(false);
        ui->b2048->restart(at.currentArch.score, at.currentArch.step, at.currentArch.countNumber, at.currentArch.box);
        timer->stop();
        tsec=at.currentArch.time[2] - 1;//重置计时器
        tmin=at.currentArch.time[1];
        thour = at.currentArch.time[0];
        timer->start(1000);
    });//读取存档
    connect(&at,&archivewidget::savegame,[=](){
        at.archiveList.append(at.tmpArch);
        at.saveArchiveToFile();
        at.showArchiveList();
    });//保存存档
    connect(&at,&archivewidget::deletegame,[=](){
        int i;
        for(i = 0; i<at.archiveList.size(); i++)
        {
            if(at.archiveList[i].date == at.currentArch.date)
                break;
        }
        struct archiveInfo tmpa = at.archiveList.takeAt(i);
        at.saveArchiveToFile();
        at.showArchiveList();
    });//删除存档

}

void gameWidget::scorelist()
{
    int s = ui->b2048->nowScore();
    QString temp = name + "\r\n" + QString::number(s) + "\r\n";
    QFile file("scorelist.txt");
    if(file.open(QIODevice::Append | QIODevice::Text))
    {
        file.write(temp.toUtf8());
        file.close();
    }
}

void gameWidget::changeStep()
{
    ui->steplabel->setText(QString("Step:\n%1").arg(ui->b2048->countStep()));
}
void gameWidget::changeScore()
{
    ui->scorelabel->setText(QString("Score:\n%1").arg(ui->b2048->nowScore()));
}
void gameWidget::changeHighscore()
{
    ui->highscorelabel->setText(QString("Best:\n%1").arg(ui->b2048->higeScore()));
}
void gameWidget::keyPressEvent(QKeyEvent * event)
{



     if(event->key()==Qt::Key_D || event->key()==Qt::Key_Right)
        ui->b2048->change(RIGHT);

    else if(event->key()==Qt::Key_A || event->key()==Qt::Key_Left)
        ui->b2048->change(LEFT);

    else if(event->key()==Qt::Key_W || event->key()==Qt::Key_Up)
        ui->b2048->change(UP);

   else if(event->key()==Qt::Key_S || event->key()==Qt::Key_Down)
        ui->b2048->change(DOWN);
}
void gameWidget::setname(QString n)
{
    name = n;
}

gameWidget::~gameWidget()
{
    delete ui;
}
