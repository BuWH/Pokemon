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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleCreature {
public:
    QLabel *levelFixed;
    QLabel *expFixed;
    QLabel *hpFixed;
    QLabel *strengthFixed;
    QLabel *defenseFixed;
    QLabel *speedFixed;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *nameFixed;
    QLabel *name;
    QLabel *typeFixed;

    void setupUi(QWidget *SingleCreature) {
        if (SingleCreature->objectName().isEmpty())
            SingleCreature->setObjectName(QStringLiteral("SingleCreature"));
        SingleCreature->resize(216, 372);
        SingleCreature->setStyleSheet(QLatin1String("QWidget{\n"
                                                    "                background-color: yellow;\n"
                                                    "                }\n"
                                                    "            "));
        levelFixed = new QLabel(SingleCreature);
        levelFixed->setObjectName(QStringLiteral("levelFixed"));
        levelFixed->setGeometry(QRect(10, 30, 16, 16));
        expFixed = new QLabel(SingleCreature);
        expFixed->setObjectName(QStringLiteral("expFixed"));
        expFixed->setGeometry(QRect(90, 30, 21, 16));
        hpFixed = new QLabel(SingleCreature);
        hpFixed->setObjectName(QStringLiteral("hpFixed"));
        hpFixed->setGeometry(QRect(10, 50, 16, 16));
        strengthFixed = new QLabel(SingleCreature);
        strengthFixed->setObjectName(QStringLiteral("strengthFixed"));
        strengthFixed->setGeometry(QRect(90, 50, 16, 16));
        defenseFixed = new QLabel(SingleCreature);
        defenseFixed->setObjectName(QStringLiteral("defenseFixed"));
        defenseFixed->setGeometry(QRect(10, 70, 16, 16));
        speedFixed = new QLabel(SingleCreature);
        speedFixed->setObjectName(QStringLiteral("speedFixed"));
        speedFixed->setGeometry(QRect(90, 70, 16, 16));
        horizontalLayoutWidget = new QWidget(SingleCreature);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 130, 151, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        nameFixed = new QLabel(horizontalLayoutWidget);
        nameFixed->setObjectName(QStringLiteral("nameFixed"));

        horizontalLayout->addWidget(nameFixed);

        name = new QLabel(horizontalLayoutWidget);
        name->setObjectName(QStringLiteral("name"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(name);

        typeFixed = new QLabel(SingleCreature);
        typeFixed->setObjectName(QStringLiteral("typeFixed"));
        typeFixed->setGeometry(QRect(90, 0, 90, 29));

        retranslateUi(SingleCreature);

        QMetaObject::connectSlotsByName(SingleCreature);
    } // setupUi

    void retranslateUi(QWidget *SingleCreature) {
        SingleCreature->setWindowTitle(QApplication::translate("SingleCreature", "SingleCreature", nullptr));
        levelFixed->setText(QApplication::translate("SingleCreature", "\347\272\247:", nullptr));
        expFixed->setText(QApplication::translate("SingleCreature", "Ex:", nullptr));
        hpFixed->setText(QApplication::translate("SingleCreature", "\344\275\223:", nullptr));
        strengthFixed->setText(QApplication::translate("SingleCreature", "\345\212\233:", nullptr));
        defenseFixed->setText(QApplication::translate("SingleCreature", "\351\230\262:", nullptr));
        speedFixed->setText(QApplication::translate("SingleCreature", "\351\200\237:", nullptr));
        nameFixed->setText(QApplication::translate("SingleCreature", "\345\220\215:", nullptr));
        name->setText(QApplication::translate("SingleCreature", "test", nullptr));
        typeFixed->setText(QApplication::translate("SingleCreature", "\347\261\273:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleCreature : public Ui_SingleCreature {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLECREATURE_H
