/********************************************************************************
** Form generated from reading UI file 'load.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOAD_H
#define UI_LOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_load
{
public:
    QPushButton *pushButton;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *load)
    {
        if (load->objectName().isEmpty())
            load->setObjectName(QString::fromUtf8("load"));
        load->resize(600, 400);
        load->setMinimumSize(QSize(600, 400));
        load->setMaximumSize(QSize(600, 400));
        QPalette palette;
        QBrush brush(QColor(248, 248, 248, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        load->setPalette(palette);
        load->setStyleSheet(QString::fromUtf8("#load{\n"
"border-image: url(:/image/load.png);\n"
"}"));
        pushButton = new QPushButton(load);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(380, 260, 141, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background:rgb(29, 48, 90);\n"
"color:#FFFFFF;border-radius:3px;}\n"
"QPushButton:hover{background: rgb(29, 48, 120);color:#FFFFFF;border-radius:3px;}QPushButton:pressed {padding-left:1px;  padding-top:1px;"));
        username = new QLineEdit(load);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(390, 80, 140, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(16);
        username->setFont(font1);
        username->setStyleSheet(QString::fromUtf8("border-image:rgb(255, 255, 255)\n"
""));
        password = new QLineEdit(load);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(390, 160, 140, 40));
        QFont font2;
        font2.setPointSize(7);
        password->setFont(font2);
        password->setStyleSheet(QString::fromUtf8("border-image:rgb(85, 85, 255)"));
        password->setEchoMode(QLineEdit::Password);
        pushButton_2 = new QPushButton(load);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 260, 131, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Comic Sans MS"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        pushButton_2->setFont(font3);
        pushButton_2->setStyleSheet(QString::fromUtf8("background:rgb(29, 48, 90);\n"
"color:#FFFFFF;border-radius:3px;}\n"
"QPushButton:hover{background: rgb(29, 48, 120);color:#FFFFFF;border-radius:3px;}QPushButton:pressed {padding-left:1px;  padding-top:1px;"));
        label = new QLabel(load);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 80, 101, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Comic Sans MS"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("border-image:rgb(85, 85, 255)"));
        label_2 = new QLabel(load);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(120, 150, 141, 41));
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("border-image:rgb(85, 85, 255)"));

        retranslateUi(load);

        QMetaObject::connectSlotsByName(load);
    } // setupUi

    void retranslateUi(QWidget *load)
    {
        load->setWindowTitle(QCoreApplication::translate("load", "Welcome to 2048", nullptr));
        pushButton->setText(QCoreApplication::translate("load", "Sign in", nullptr));
        pushButton_2->setText(QCoreApplication::translate("load", "Sign up", nullptr));
        label->setText(QCoreApplication::translate("load", "username:", nullptr));
        label_2->setText(QCoreApplication::translate("load", " password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class load: public Ui_load {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOAD_H
