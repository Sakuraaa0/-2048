/********************************************************************************
** Form generated from reading UI file 'archivewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCHIVEWIDGET_H
#define UI_ARCHIVEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_archivewidget
{
public:
    QListWidget *infoList;
    QPushButton *savegame;
    QPushButton *readgame;
    QPushButton *deletegame;
    QPushButton *returngame;

    void setupUi(QWidget *archivewidget)
    {
        if (archivewidget->objectName().isEmpty())
            archivewidget->setObjectName(QString::fromUtf8("archivewidget"));
        archivewidget->resize(404, 604);
        archivewidget->setMinimumSize(QSize(404, 604));
        archivewidget->setMaximumSize(QSize(404, 604));
        infoList = new QListWidget(archivewidget);
        infoList->setObjectName(QString::fromUtf8("infoList"));
        infoList->setGeometry(QRect(52, 80, 300, 400));
        infoList->setMinimumSize(QSize(300, 400));
        infoList->setMaximumSize(QSize(300, 400));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        infoList->setFont(font);
        savegame = new QPushButton(archivewidget);
        savegame->setObjectName(QString::fromUtf8("savegame"));
        savegame->setGeometry(QRect(30, 520, 91, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        savegame->setFont(font1);
        readgame = new QPushButton(archivewidget);
        readgame->setObjectName(QString::fromUtf8("readgame"));
        readgame->setGeometry(QRect(160, 520, 91, 51));
        readgame->setFont(font1);
        deletegame = new QPushButton(archivewidget);
        deletegame->setObjectName(QString::fromUtf8("deletegame"));
        deletegame->setGeometry(QRect(280, 520, 91, 51));
        deletegame->setFont(font1);
        returngame = new QPushButton(archivewidget);
        returngame->setObjectName(QString::fromUtf8("returngame"));
        returngame->setGeometry(QRect(20, 20, 91, 41));
        returngame->setFont(font1);

        retranslateUi(archivewidget);

        QMetaObject::connectSlotsByName(archivewidget);
    } // setupUi

    void retranslateUi(QWidget *archivewidget)
    {
        archivewidget->setWindowTitle(QCoreApplication::translate("archivewidget", "2048", nullptr));
        savegame->setText(QCoreApplication::translate("archivewidget", "save", nullptr));
        readgame->setText(QCoreApplication::translate("archivewidget", "read", nullptr));
        deletegame->setText(QCoreApplication::translate("archivewidget", "delete", nullptr));
        returngame->setText(QCoreApplication::translate("archivewidget", "return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class archivewidget: public Ui_archivewidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCHIVEWIDGET_H
