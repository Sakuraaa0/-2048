/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <box.h>

QT_BEGIN_NAMESPACE

class Ui_gameWidget
{
public:
    Box *b2048;
    QLabel *timelabel;
    QLabel *scorelabel;
    QLabel *highscorelabel;
    QLabel *steplabel;
    QPushButton *restartbutton;
    QPushButton *aihelp;
    QPushButton *archive;

    void setupUi(QWidget *gameWidget)
    {
        if (gameWidget->objectName().isEmpty())
            gameWidget->setObjectName(QString::fromUtf8("gameWidget"));
        gameWidget->resize(404, 604);
        gameWidget->setMinimumSize(QSize(404, 604));
        gameWidget->setMaximumSize(QSize(404, 604));
        b2048 = new Box(gameWidget);
        b2048->setObjectName(QString::fromUtf8("b2048"));
        b2048->setGeometry(QRect(4, 202, 396, 396));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(b2048->sizePolicy().hasHeightForWidth());
        b2048->setSizePolicy(sizePolicy);
        b2048->setMinimumSize(QSize(396, 396));
        b2048->setMaximumSize(QSize(396, 396));
        b2048->setBaseSize(QSize(0, 0));
        timelabel = new QLabel(gameWidget);
        timelabel->setObjectName(QString::fromUtf8("timelabel"));
        timelabel->setGeometry(QRect(10, 10, 381, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        timelabel->setFont(font);
        timelabel->setFrameShape(QFrame::NoFrame);
        timelabel->setFrameShadow(QFrame::Raised);
        timelabel->setAlignment(Qt::AlignCenter);
        scorelabel = new QLabel(gameWidget);
        scorelabel->setObjectName(QString::fromUtf8("scorelabel"));
        scorelabel->setGeometry(QRect(10, 60, 121, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        scorelabel->setFont(font1);
        scorelabel->setFrameShape(QFrame::NoFrame);
        scorelabel->setLineWidth(1);
        scorelabel->setAlignment(Qt::AlignCenter);
        highscorelabel = new QLabel(gameWidget);
        highscorelabel->setObjectName(QString::fromUtf8("highscorelabel"));
        highscorelabel->setGeometry(QRect(270, 60, 121, 61));
        highscorelabel->setFont(font1);
        highscorelabel->setFrameShape(QFrame::NoFrame);
        highscorelabel->setAlignment(Qt::AlignCenter);
        steplabel = new QLabel(gameWidget);
        steplabel->setObjectName(QString::fromUtf8("steplabel"));
        steplabel->setGeometry(QRect(140, 60, 121, 61));
        steplabel->setFont(font1);
        steplabel->setFrameShape(QFrame::NoFrame);
        steplabel->setAlignment(Qt::AlignCenter);
        restartbutton = new QPushButton(gameWidget);
        restartbutton->setObjectName(QString::fromUtf8("restartbutton"));
        restartbutton->setGeometry(QRect(300, 140, 91, 41));
        restartbutton->setFont(font1);
        aihelp = new QPushButton(gameWidget);
        aihelp->setObjectName(QString::fromUtf8("aihelp"));
        aihelp->setGeometry(QRect(200, 140, 93, 41));
        aihelp->setFont(font1);
        archive = new QPushButton(gameWidget);
        archive->setObjectName(QString::fromUtf8("archive"));
        archive->setGeometry(QRect(10, 140, 93, 41));
        archive->setFont(font1);
        timelabel->raise();
        scorelabel->raise();
        highscorelabel->raise();
        steplabel->raise();
        restartbutton->raise();
        b2048->raise();
        aihelp->raise();
        archive->raise();

        retranslateUi(gameWidget);

        QMetaObject::connectSlotsByName(gameWidget);
    } // setupUi

    void retranslateUi(QWidget *gameWidget)
    {
        gameWidget->setWindowTitle(QCoreApplication::translate("gameWidget", "2048", nullptr));
        timelabel->setText(QString());
        scorelabel->setText(QCoreApplication::translate("gameWidget", "Score:\n"
"0", nullptr));
        highscorelabel->setText(QCoreApplication::translate("gameWidget", "Best:\n"
"0", nullptr));
        steplabel->setText(QCoreApplication::translate("gameWidget", "Step:\n"
"0", nullptr));
        restartbutton->setText(QCoreApplication::translate("gameWidget", "Restart", nullptr));
        aihelp->setText(QCoreApplication::translate("gameWidget", "AI help", nullptr));
        archive->setText(QCoreApplication::translate("gameWidget", "Archive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameWidget: public Ui_gameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
