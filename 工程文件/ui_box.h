/********************************************************************************
** Form generated from reading UI file 'box.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOX_H
#define UI_BOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Box
{
public:

    void setupUi(QWidget *Box)
    {
        if (Box->objectName().isEmpty())
            Box->setObjectName(QString::fromUtf8("Box"));
        Box->resize(396, 396);
        Box->setMinimumSize(QSize(396, 396));
        Box->setMaximumSize(QSize(396, 396));

        retranslateUi(Box);

        QMetaObject::connectSlotsByName(Box);
    } // setupUi

    void retranslateUi(QWidget *Box)
    {
        Box->setWindowTitle(QCoreApplication::translate("Box", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Box: public Ui_Box {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOX_H
