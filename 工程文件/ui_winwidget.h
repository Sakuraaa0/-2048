/********************************************************************************
** Form generated from reading UI file 'winwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINWIDGET_H
#define UI_WINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *score;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *newgame;
    QPushButton *rank;
    QPushButton *quit;

    void setupUi(QWidget *winWidget)
    {
        if (winWidget->objectName().isEmpty())
            winWidget->setObjectName(QString::fromUtf8("winWidget"));
        winWidget->resize(418, 274);
        verticalLayout = new QVBoxLayout(winWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(winWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(378, 136));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        score = new QLabel(winWidget);
        score->setObjectName(QString::fromUtf8("score"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        score->setFont(font1);
        score->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(score);

        widget = new QWidget(winWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newgame = new QPushButton(widget);
        newgame->setObjectName(QString::fromUtf8("newgame"));
        newgame->setMinimumSize(QSize(120, 60));
        newgame->setMaximumSize(QSize(120, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Comic Sans MS"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        newgame->setFont(font2);

        horizontalLayout->addWidget(newgame);

        rank = new QPushButton(widget);
        rank->setObjectName(QString::fromUtf8("rank"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rank->sizePolicy().hasHeightForWidth());
        rank->setSizePolicy(sizePolicy1);
        rank->setMinimumSize(QSize(120, 60));
        rank->setMaximumSize(QSize(120, 60));
        rank->setFont(font2);

        horizontalLayout->addWidget(rank);

        quit = new QPushButton(widget);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setMinimumSize(QSize(120, 60));
        quit->setMaximumSize(QSize(120, 60));
        quit->setFont(font2);

        horizontalLayout->addWidget(quit);


        verticalLayout->addWidget(widget);


        retranslateUi(winWidget);

        QMetaObject::connectSlotsByName(winWidget);
    } // setupUi

    void retranslateUi(QWidget *winWidget)
    {
        winWidget->setWindowTitle(QCoreApplication::translate("winWidget", "2048-WIN!", nullptr));
        label->setText(QCoreApplication::translate("winWidget", "CONGRATULATIONS!\n"
"YOU WIN!", nullptr));
        score->setText(QCoreApplication::translate("winWidget", "final score:", nullptr));
        newgame->setText(QCoreApplication::translate("winWidget", "AGAIN", nullptr));
        rank->setText(QCoreApplication::translate("winWidget", "RANK", nullptr));
        quit->setText(QCoreApplication::translate("winWidget", "QUIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class winWidget: public Ui_winWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINWIDGET_H
