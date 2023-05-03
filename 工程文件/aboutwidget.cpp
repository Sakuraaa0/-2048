#include "aboutwidget.h"
#include "ui_aboutwidget.h"

aboutWidget::aboutWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutWidget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/windowicon.png"));
   // this->setStyleSheet("background-color:rgb(89, 105, 121)");
   // ui->label->setStyleSheet(LABLESTYLE);
}

aboutWidget::~aboutWidget()
{
    delete ui;
}
