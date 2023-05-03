#ifndef LOSEWIDGET_H
#define LOSEWIDGET_H

#include <QWidget>

//美化用的stylesheet
#define LBLSTYLE "color: rgb(104,142,224);border: 5px solid rgb(104,142,224);border-radius: 10px"
#define BTSTYLE "QPushButton{background: #59BAFC;color:#FFFFFF;border-radius:3px;}QPushButton:hover{background: rgb(89, 200, 252);color:#FFFFFF;border-radius:3px;}QPushButton:pressed {padding-left:1px;  padding-top:1px;}"

namespace Ui {
class loseWidget;
}

class loseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit loseWidget(QWidget *parent = 0);
    ~loseWidget();
    void setlabel(int t);//分数输入
private:
    Ui::loseWidget *ui;
signals:
    void newgame();//重新开始
    void rank();//排行榜
    void quit();//退出游戏
};

#endif // LOSEWIDGET_H
