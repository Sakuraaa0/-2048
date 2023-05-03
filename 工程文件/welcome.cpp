#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    //美化
    this->setWindowIcon(QIcon(":/image/windowicon.png"));

    //信号与槽的连接
    connect(ui->start,&QPushButton::clicked,[=](){
        this->close();
        t.show();
    });//开始游戏
    connect(ui->ranklist,&QPushButton::clicked,[=](){
        rw.ranklist();
        rw.show();
    });//排行榜显示
    connect(ui->about,&QPushButton::clicked,&w,&aboutWidget::show);//关于游戏界面
    connect(ui->quit,&QPushButton::clicked,[=](){
        qApp->quit();
    });//退出游戏
}
void Welcome::paintEvent(QPaintEvent *)//此函数是用来使此界面的背景图片显示出来
{
    QStyleOption opt;

         opt.init(this);

          QPainter p(this);

          style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
Welcome::~Welcome()
{
    delete ui;
}
