#include "load.h"
#include "ui_load.h"


load::load(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::load)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/windowicon.png"));
    connect(this,&load::start,[=](){
        gw.setname(ui->username->text());
        gw.timer->start(1000);
        gw.show();
    });

}

load::~load()
{
    delete ui;
}
void load::paintEvent(QPaintEvent *)//此函数是用来使此界面的背景图片显示出来
{
    QStyleOption opt;

         opt.init(this);

          QPainter p(this);

          style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}



void load::on_pushButton_2_clicked()//点击注册按钮
{
    QString name=ui->username->text();//获取用户名
    QString pwd=ui->password->text();//获取密码
    //如果用户名或密码为空则出现warning box
    if(name==""||pwd=="") QMessageBox::warning(NULL,"warning","the username or password cannot be null");

   else {
         QString nameandpwd=name+","+pwd;//得到用户名+密码的字符串，方便后续的存入文件操作
         QString displayString;
         QFile file("user.txt");//打开user文件夹,如果没有，则在此工程所在文件夹的build-XXXXX中生成一个user.txt
    if(!file.open(QFile::ReadOnly|QIODevice::Append|QIODevice::Text))
    {
        qDebug()<<"do not open";
    }
    else {
        QTextStream stream(&file);
     QString line_in;
     stream.seek(0);//将当前读取文件指针移动到文件开始
     while( !stream.atEnd())//此while循环用于判断输入的内容在user文件中是否已经存在，如果存在则出现warning box
     {
         line_in = stream.readLine();
         displayString.append(line_in);
         if(line_in.contains(name))
             {

             ui->username->clear();//清空lineedit控件，跳出循环，返回登录界面
             ui->password->clear();
             QMessageBox::warning(NULL,"warning","the username has been logonned");//warning box
             stream.seek(0);
             break;

         }

     }
     if(stream.atEnd())//执行到这一步说明输入的用户名还没有被注册
     {
         stream<<nameandpwd<<endl;//将用户名密码写入文件
         QMessageBox::information(NULL,"welcome","welcome to 2048");//欢迎新用户
         this->close();//关闭登录界面，打开主界面
         emit start();
     }



    }
    }

}

void load::on_pushButton_clicked()//点击登录按钮
{
    QString name=ui->username->text();//获取用户名
    QString pwd=ui->password->text();//获取密码
    //当用户名或密码为空则出现warning box
    if(name==""||pwd=="") QMessageBox::warning(NULL,"warning","the username or password cannot be null");
    else
    {
            QString nameandpwd=name+","+pwd;
            QString displayString;
            QFile file("user.txt");
            if(!file.open(QFile::ReadOnly|QIODevice::Append|QIODevice::Text))
            {
                qDebug()<<"do not open";
            }
            else {
                QTextStream stream(&file);
             QString line_in;
             stream.seek(0);//将当前读取文件指针移动到文件开始
             while( !stream.atEnd())//此循环用于判断输入的用户名和密码是否与user文件中的内容有匹配
             {
                 line_in = stream.readLine();
                 displayString.append(line_in);
                 if(nameandpwd==line_in)//如果有匹配
                 {
                     stream.seek(0);
                     QMessageBox::information(NULL,"welcome","welcome back to 2048");//欢迎回来界面
                     this->close();//关闭登录界面，打开主界面
                     emit start();
                     break;


                 }

             }
             if(stream.atEnd())//执行到这一步说明输入的用户名和密码与user文件中的内容没有匹配
             {
                 //可能的原因为：密码错误，或者用户名未注册
                 QMessageBox::warning(NULL,"warning","the password is wrong,or the username has not been logoned");

             }

         }
    }
}
