#include "archivewidget.h"
#include "ui_archivewidget.h"

archivewidget::archivewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::archivewidget)
{
    ui->setupUi(this);
    //美化
    this->setStyleSheet("background-color: rgb(251,248,239)");
    setWindowIcon(QIcon(":/image/windowicon.png"));//修改窗口图标
    ui->returngame->setStyleSheet(QString(BTNSTYLE));
    ui->deletegame->setStyleSheet(QString(BTNSTYLE));
    ui->savegame->setStyleSheet(QString(BTNSTYLE));
    ui->readgame->setStyleSheet(QString(BTNSTYLE));
    ui->infoList->setStyleSheet(QString(LISTSTTLE));
    //连接信号
    connect(ui->returngame,&QPushButton::clicked,this,returngame);
    connect(ui->deletegame,&QPushButton::clicked,this,deletegame);
    connect(ui->savegame,&QPushButton::clicked,this,savegame);
    connect(ui->readgame,&QPushButton::clicked,this,readgame);
    connect(ui->infoList,&QListWidget::itemDoubleClicked,this,dClicked);
    //读取文件
    readArchiveFromFile();
    //展示存档信息
    showArchiveList();
    //连接信号
    connect(ui->infoList,&QListWidget::itemClicked,[=](){
        QString tmpItem = ui->infoList->currentItem()->text();
        int i = 0;
        while(archiveList[i].date != tmpItem)
            i++;
        currentArch = archiveList[i];
    });
    connect(ui->infoList,&QListWidget::itemDoubleClicked,[=](){
        QString tmpItem = ui->infoList->currentItem()->text();
        int i = 0;
        while(archiveList[i].date != tmpItem)
            i++;
        currentArch = archiveList[i];

    });
}

archivewidget::~archivewidget()
{
    delete ui;
}

void archivewidget::getNowGameInfo(int nowScore, int nowStep, QString nowDate, int *nowTime, int *nowBox, int nowCount)
{
    tmpArch.score = nowScore;
    tmpArch.step = nowStep;
    tmpArch.date = nowDate;
    tmpArch.time[0] = nowTime[0]; tmpArch.time[1] = nowTime[1]; tmpArch.time[2] = nowTime[2];
    tmpArch.countNumber = nowCount;
    for(int i = 0; i < 16; i++)
    {
        tmpArch.box[i] = nowBox[i];
    }
}

void archivewidget::readArchiveFromFile()
{
    struct archiveInfo temp;
    QFile file("archivelist.txt");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        while(!file.atEnd())
        {
            //读取分数
            QByteArray line = file.readLine();
            QString m0(line);
            temp.score = m0.toInt();
            //读取步数
            line = file.readLine();
            QString m1(line);
            temp.step = m1.toInt();
            //读取日期
            line = file.readLine();
            QString m2(line);
            temp.date = m2.replace(QString("\n"), QString(""));
            //读取时间
            QString line2 = file.readLine();
            int i = 0;
            int j = 0;
            QString m3;
            while(line2[i] != '\0')
            {
                if(line2[i] == ',')
                {
                    //qDebug() << m3;
                    temp.time[j] = m3.toInt();
                    m3.clear();
                    j++;
                }
                else
                {   QString tmp(line2[i]);
                    m3.append(tmp);
                }
                i++;
            }
            //读取游戏矩阵
            line2 = file.readLine();
            i = 0;
            j = 0;
            QString m4;
            while(line2[i] != '\0')
            {
                if(line2[i] == ',')
                {
                    temp.box[j] = m4.toInt();
                    m4.clear();
                    j++;
                }
                else
                {
                    QString tmp(line2[i]);
                    m4 += line2[i];
                }
                i++;
            }
            //读取非零方块个数
            line = file.readLine();
            QString m5(line);
            temp.countNumber = m5.toInt();

            archiveList.append(temp);
        }
        file.close();
    }
}

void archivewidget::saveArchiveToFile()
{
    QFile file("archivelist.txt");
    if(file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        for(int i=0; i<archiveList.size(); i++)
        {
            //写分数
            QString tmpS; tmpS.setNum(archiveList[i].score);
            QByteArray line = tmpS.toUtf8();
            file.write(line);
            file.write("\n");
            tmpS.clear();
            line.clear();
            //写步数
            tmpS.setNum(archiveList[i].step);
            line = tmpS.toUtf8();
            file.write(line);
            file.write("\n");
            tmpS.clear();
            line.clear();
            //写日期
            tmpS = archiveList[i].date;
            line = tmpS.toUtf8();
            file.write(line);
            file.write("\n");
            tmpS.clear();
            line.clear();
            //写时间
            for(int j=0; j<3; j++)
            {
                tmpS.setNum(archiveList[i].time[j]);
                tmpS += ",";
                line = tmpS.toUtf8();
                file.write(line);
            }
            file.write("\n");
            tmpS.clear();
            line.clear();
            //写游戏矩阵
            for(int j=0; j<16; j++)
            {
                tmpS.setNum(archiveList[i].box[j]);
                tmpS += ",";
                line = tmpS.toUtf8();
                file.write(line);
            }
            file.write("\n");
            tmpS.clear();
            line.clear();
            //写非零方块个数
            tmpS.setNum(archiveList[i].countNumber);
            line = tmpS.toUtf8();
            file.write(line);
            file.write("\n");
            tmpS.clear();
            line.clear();
        }
        file.close();
    }
}

void archivewidget::showArchiveList()
{
    ui->infoList->clear();
    for(int i=0; i<archiveList.size(); i++)
    {
        QListWidgetItem* tmpItem = new QListWidgetItem(ui->infoList);
        tmpItem->setText(archiveList[i].date);
        QString tmpString = "Score: " + QString::number(archiveList[i].score, 10) + "\n" +
                            "Step: " + QString::number(archiveList[i].step, 10) + "\n" +
                            "Time: " + QString::number(archiveList[i].time[0], 10) + ":" + QString::number(archiveList[i].time[1], 10) + ":" + QString::number(archiveList[i].time[2], 10);
        tmpItem->setToolTip(tmpString);
        ui->infoList->addItem(tmpItem);
    }
}

void archivewidget::test1() //测试
{
    for( int i=0; i< archiveList.size(); ++i)
    {
        qDebug()
                 << archiveList[i].score << endl
                 << archiveList[i].step << endl
                 << archiveList[i].date << endl
                 << archiveList[i].time[0] << "," << archiveList[i].time[1] << "," << archiveList[i].time[2] << endl
                 << archiveList[i].countNumber;
        for(int x=0; x< 16; x++)
        {
            qDebug() << archiveList[i].box[x];
        }
    }
}
