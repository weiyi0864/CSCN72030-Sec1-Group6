/********************************************************************************
** Form generated from reading UI file 'Dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogClass
{
public:

    void setupUi(QWidget *DialogClass)
    {
        if (DialogClass->objectName().isEmpty())
            DialogClass->setObjectName("DialogClass");
        DialogClass->resize(600, 400);

        retranslateUi(DialogClass);

        QMetaObject::connectSlotsByName(DialogClass);
    } // setupUi

    void retranslateUi(QWidget *DialogClass)
    {
        DialogClass->setWindowTitle(QCoreApplication::translate("DialogClass", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogClass: public Ui_DialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
