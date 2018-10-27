/********************************************************************************
** Form generated from reading UI file 'singlecreature.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLECREATURE_H
#define UI_SINGLECREATURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleCreature {
public:
    QLabel *label;

    void setupUi(QWidget *SingleCreature) {
        if (SingleCreature->objectName().isEmpty())
            SingleCreature->setObjectName(QStringLiteral("SingleCreature"));
        SingleCreature->resize(200, 200);
        SingleCreature->setStyleSheet(QLatin1String("QWidget{\n"
                                                    "	background-color: yellow;\n"
                                                    "}"));
        label = new QLabel(SingleCreature);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 59, 16));

        retranslateUi(SingleCreature);

        QMetaObject::connectSlotsByName(SingleCreature);
    } // setupUi

    void retranslateUi(QWidget *SingleCreature) {
        SingleCreature->setWindowTitle(QApplication::translate("SingleCreature", "SingleCreature", nullptr));
        label->setText(QApplication::translate("SingleCreature", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleCreature : public Ui_SingleCreature {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLECREATURE_H
