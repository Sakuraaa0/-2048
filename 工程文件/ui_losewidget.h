/********************************************************************************
** Form generated from reading UI file 'losewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSEWIDGET_H
#define UI_LOSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loseWidget
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

    void setupUi(QWidget *loseWidget)
    {
        if (loseWidget->objectName().isEmpty())
            loseWidget->setObjectName(QString::fromUtf8("loseWidget"));
        loseWidget->resize(418, 274);
        verticalLayout = new QVBoxLayout(loseWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(loseWidget);
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

        score = new QLabel(loseWidget);
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

        widget = new QWidget(loseWidget);
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


        retranslateUi(loseWidget);

        QMetaObject::connectSlotsByName(loseWidget);
    } // setupUi

    void retranslateUi(QWidget *loseWidget)
    {
        loseWidget->setWindowTitle(QCoreApplication::translate("loseWidget", "2048-LOSE", nullptr));
        label->setText(QCoreApplication::translate("loseWidget", "YOU LOSE!\n"
"Cheer Up!", nullptr));
        score->setText(QCoreApplication::translate("loseWidget", "final score:", nullptr));
        newgame->setText(QCoreApplication::translate("loseWidget", "AGAIN", nullptr));
        rank->setText(QCoreApplication::translate("loseWidget", "RANK", nullptr));
        quit->setText(QCoreApplication::translate("loseWidget", "QUIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loseWidget: public Ui_loseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSEWIDGET_H
