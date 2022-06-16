/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Pin25;
    QPushButton *Pin26;
    QPushButton *Pin27;
    QPushButton *Pin28;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 80, 384, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Pin25 = new QPushButton(widget);
        Pin25->setObjectName(QString::fromUtf8("Pin25"));
        Pin25->setCheckable(true);

        horizontalLayout->addWidget(Pin25);

        Pin26 = new QPushButton(widget);
        Pin26->setObjectName(QString::fromUtf8("Pin26"));
        Pin26->setCheckable(true);

        horizontalLayout->addWidget(Pin26);

        Pin27 = new QPushButton(widget);
        Pin27->setObjectName(QString::fromUtf8("Pin27"));
        Pin27->setCheckable(true);

        horizontalLayout->addWidget(Pin27);

        Pin28 = new QPushButton(widget);
        Pin28->setObjectName(QString::fromUtf8("Pin28"));
        Pin28->setCheckable(true);

        horizontalLayout->addWidget(Pin28);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        Pin25->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        Pin26->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        Pin27->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        Pin28->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
