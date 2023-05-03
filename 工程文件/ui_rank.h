/********************************************************************************
** Form generated from reading UI file 'rank.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANK_H
#define UI_RANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rank
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Rank)
    {
        if (Rank->objectName().isEmpty())
            Rank->setObjectName(QString::fromUtf8("Rank"));
        Rank->resize(400, 600);
        label = new QLabel(Rank);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 360, 550));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(15);
        label->setFont(font);
        label->setFocusPolicy(Qt::NoFocus);
        label->setStyleSheet(QString::fromUtf8("color: black;background:rgb(241, 240, 246);border-radius: 5px;"));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_2 = new QLabel(Rank);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 0, 111, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        retranslateUi(Rank);

        QMetaObject::connectSlotsByName(Rank);
    } // setupUi

    void retranslateUi(QWidget *Rank)
    {
        Rank->setWindowTitle(QCoreApplication::translate("Rank", "Rank List of 2048 player", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("Rank", "  rank", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rank: public Ui_Rank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANK_H
