/********************************************************************************
** Form generated from reading UI file 'aboutwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWIDGET_H
#define UI_ABOUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *aboutWidget)
    {
        if (aboutWidget->objectName().isEmpty())
            aboutWidget->setObjectName(QString::fromUtf8("aboutWidget"));
        aboutWidget->resize(400, 600);
        aboutWidget->setMinimumSize(QSize(400, 600));
        aboutWidget->setMaximumSize(QSize(400, 600));
        label = new QLabel(aboutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 380, 580));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(12);
        font.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(200, 200, 200);background: rgb(116, 116, 116);border-radius: 5px;"));

        retranslateUi(aboutWidget);

        QMetaObject::connectSlotsByName(aboutWidget);
    } // setupUi

    void retranslateUi(QWidget *aboutWidget)
    {
        aboutWidget->setWindowTitle(QCoreApplication::translate("aboutWidget", "Introduction", nullptr));
        label->setText(QCoreApplication::translate("aboutWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Welcome to 2048 game!</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">(\357\275\241\357\275\245\342\210\200\357\275\245)\357\276\211\357\276\236</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">Created by: </span></p><p align=\"justify\"><span style=\" font-size:14pt;\">\346\235\216\346\226\207\346\230\212 \351\237\251\347\207\232 \346\235\216\344\274\257\345\220\233 \346\235\216\344\275\263\345\275\244 \346\270\270\344\275\263\347\243\212 \345\255\231\344\270\200\351\223\255</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">Introduction:</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">Join the numbers and get to</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">the 2048 tile!</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">Key Tips:</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">Us"
                        "e W(up),A(left),S(down) and</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">D(right) to move the number-</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">box and join them\357\274\201</span></p><p align=\"right\"><span style=\" font-size:14pt; font-weight:600;\">\\(\357\277\243\357\270\266\357\277\243*))\\</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutWidget: public Ui_aboutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWIDGET_H
