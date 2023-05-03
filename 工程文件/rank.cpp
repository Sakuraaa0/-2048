#include "rank.h"
#include "ui_rank.h"

Rank::Rank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rank)
{
    //美化
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/windowicon.png"));
   // ui->label->setStyleSheet("color: black;background: rgb(187,173,160);border-radius: 5px;");

}

void Rank::ranklist()
{
    //文件读取，并保存入链表
    node temp;
    QFile file("scorelist.txt");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString m(line);
            temp.name = m.replace(QString("\n"), QString(""));
            line = file.readLine();
            QString mt(line);
            temp.score = mt.toInt();
            t.append(temp);
        }
        file.close();
    }
    //排序
    qSort(t.begin(),t.end(),[](const node &nodeA,const node &nodeB){
                  return nodeA.score > nodeB.score;});
    //输出
    QString rank = "\n  ";
    QList<node>::iterator tw;
    int i = 1;
    for(tw = t.begin();tw != t.end();tw++,i++)
    {
        node k = *tw;
        rank += "No."+QString::number(i)+"  "+k.name+"      "+QString::number(k.score)+"\n  ";
    }
    ui->label->setText(rank);
    t.clear();
}

Rank::~Rank()
{
    delete ui;
}
