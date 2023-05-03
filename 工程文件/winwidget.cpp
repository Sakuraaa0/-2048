#include "winwidget.h"
#include "ui_winwidget.h"

winWidget::winWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winWidget)
{
    ui->setupUi(this);

    //美化
    this->setWindowFlag(Qt::SubWindow);
    this->setWindowIcon(QIcon(":/image/windowicon.png"));
    this->setStyleSheet("background-color: rgb(251,248,239)");
    ui->newgame->setStyleSheet(QString(BTSTYLE));
    ui->rank->setStyleSheet(QString(BTSTYLE));
    ui->quit->setStyleSheet(QString(BTSTYLE));
    ui->label->setStyleSheet(QString(LBLSTYLE));
    //连接信号
    connect(ui->newgame,&QPushButton::clicked,this,newgame);
    connect(ui->rank,&QPushButton::clicked,this,rank);
    connect(ui->quit,&QPushButton::clicked,this,quit);
}

void winWidget::setlabel(int t)
{
    ui->score->setText(QString("final score: %1").arg(t));
}

winWidget::~winWidget()
{
    delete ui;
}
