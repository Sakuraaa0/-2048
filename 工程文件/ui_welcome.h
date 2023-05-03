/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QPushButton *start;
    QPushButton *about;
    QPushButton *ranklist;
    QLabel *label;
    QLabel *label_2;
    QPushButton *quit;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QString::fromUtf8("Welcome"));
        Welcome->resize(400, 600);
        Welcome->setMinimumSize(QSize(400, 600));
        Welcome->setMaximumSize(QSize(400, 600));
        Welcome->setStyleSheet(QString::fromUtf8("#Welcome{\n"
"	border-image: url(:/image/welcome.jpg);\n"
"	background-image: url(:/image/welcome.jpg);\n"
"}"));
        start = new QPushButton(Welcome);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(100, 240, 200, 70));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setBold(true);
        font.setWeight(75);
        start->setFont(font);
        start->setStyleSheet(QString::fromUtf8("background:rgb(9, 12, 17);color:#FFFFFF;border-radius:3px;}QPushButton:hover{background: rgb(64, 73, 82);color:#FFFFFF;border-radius:3px;}QPushButton:pressed {padding-left:1px;  padding-top:1px;"));
        about = new QPushButton(Welcome);
        about->setObjectName(QString::fromUtf8("about"));
        about->setGeometry(QRect(100, 340, 200, 70));
        about->setFont(font);
        about->setStyleSheet(QString::fromUtf8("background:rgb(9, 12, 17);color:#FFFFFF;border-radius:3px;}QPushButton:hover{background: rgb(64, 73, 82);color:#FFFFFF;border-radius:3px;}QPushButton:pressed {padding-left:1px;  padding-top:1px;"));
        ranklist = new QPushButton(Welcome);
        ranklist->setObjectName(QString::fromUtf8("ranklist"));
        ranklist->setGeometry(QRect(100, 440, 200, 70));
        ranklist->setFont(font);
        ranklist->setStyleSheet(QString::fromUtf8("background:rgb(9, 12, 17);color:#FFFFFF;border-radius:3px;}QPushButton:hover{background: rgb(64, 73, 82);color:#FFFFFF;border-radius:3px;}QPushButton:pressed {padding-left:1px;  padding-top:1px;"));
        label = new QLabel(Welcome);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 100, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(27);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(116, 116, 124);background:rgb(237, 236, 241);border-radius:15px;"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Welcome);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(60, 160, 231, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Comic Sans MS"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: ;border: 5px; solid ;border-radius: 10px"));
        quit = new QPushButton(Welcome);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(300, 540, 93, 28));
        quit->setFont(font);
        quit->setStyleSheet(QString::fromUtf8("background:rgb(9, 12, 17);color:#FFFFFF;border-radius:3px;}QPushButton:hover{background: rgb(64, 73, 82);color:#FFFFFF;border-radius:3px;}QPushButton:pressed {padding-left:1px;  padding-top:1px;"));

        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QCoreApplication::translate("Welcome", "Welcom to 2048", nullptr));
        start->setText(QCoreApplication::translate("Welcome", "Sign in/Start Play", nullptr));
        about->setText(QCoreApplication::translate("Welcome", "About 2048", nullptr));
        ranklist->setText(QCoreApplication::translate("Welcome", "View RankList", nullptr));
        label->setText(QCoreApplication::translate("Welcome", "2048", nullptr));
        label_2->setText(QCoreApplication::translate("Welcome", "Wlecome to the 2048!", nullptr));
        quit->setText(QCoreApplication::translate("Welcome", "Quit Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
