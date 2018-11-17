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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleCreature
{
public:
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *Layout_name_type;
    QLabel *name;
    QLabel *property;
    QLabel *type;
    QHBoxLayout *Layout_level_exp;
    QLabel *levelFixed;
    QLabel *level;
    QLabel *expFixed;
    QLabel *exp;
    QHBoxLayout *Layout_hp_strength;
    QLabel *hpFixed;
    QLabel *hp;
    QLabel *strengthFixed;
    QLabel *strength;
    QHBoxLayout *Layout_defense_speed;
    QLabel *defenseFixed;
    QLabel *defense;
    QLabel *speedFixed;
    QLabel *speed;

    void setupUi(QWidget *SingleCreature)
    {
        if (SingleCreature->objectName().isEmpty())
            SingleCreature->setObjectName(QStringLiteral("SingleCreature"));
        SingleCreature->resize(200, 120);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SingleCreature->sizePolicy().hasHeightForWidth());
        SingleCreature->setSizePolicy(sizePolicy);
        SingleCreature->setMinimumSize(QSize(200, 120));
        SingleCreature->setStyleSheet(QStringLiteral(""));
        verticalWidget = new QWidget(SingleCreature);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setGeometry(QRect(0, 0, 200, 120));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        Layout_name_type = new QHBoxLayout();
        Layout_name_type->setObjectName(QStringLiteral("Layout_name_type"));
        Layout_name_type->setSizeConstraint(QLayout::SetNoConstraint);
        name = new QLabel(verticalWidget);
        name->setObjectName(QStringLiteral("name"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy2);
        name->setMinimumSize(QSize(50, 30));

        Layout_name_type->addWidget(name);

        property = new QLabel(verticalWidget);
        property->setObjectName(QStringLiteral("property"));
        sizePolicy2.setHeightForWidth(property->sizePolicy().hasHeightForWidth());
        property->setSizePolicy(sizePolicy2);
        property->setMinimumSize(QSize(50, 30));
        property->setLayoutDirection(Qt::LeftToRight);
        property->setAlignment(Qt::AlignCenter);

        Layout_name_type->addWidget(property);

        type = new QLabel(verticalWidget);
        type->setObjectName(QStringLiteral("type"));
        sizePolicy2.setHeightForWidth(type->sizePolicy().hasHeightForWidth());
        type->setSizePolicy(sizePolicy2);
        type->setMinimumSize(QSize(50, 30));

        Layout_name_type->addWidget(type);


        verticalLayout->addLayout(Layout_name_type);

        Layout_level_exp = new QHBoxLayout();
        Layout_level_exp->setObjectName(QStringLiteral("Layout_level_exp"));
        Layout_level_exp->setSizeConstraint(QLayout::SetNoConstraint);
        levelFixed = new QLabel(verticalWidget);
        levelFixed->setObjectName(QStringLiteral("levelFixed"));
        sizePolicy2.setHeightForWidth(levelFixed->sizePolicy().hasHeightForWidth());
        levelFixed->setSizePolicy(sizePolicy2);
        levelFixed->setMinimumSize(QSize(0, 30));
        levelFixed->setMaximumSize(QSize(20, 16777215));

        Layout_level_exp->addWidget(levelFixed);

        level = new QLabel(verticalWidget);
        level->setObjectName(QStringLiteral("level"));
        sizePolicy2.setHeightForWidth(level->sizePolicy().hasHeightForWidth());
        level->setSizePolicy(sizePolicy2);
        level->setMinimumSize(QSize(50, 30));

        Layout_level_exp->addWidget(level);

        expFixed = new QLabel(verticalWidget);
        expFixed->setObjectName(QStringLiteral("expFixed"));
        expFixed->setEnabled(true);
        sizePolicy2.setHeightForWidth(expFixed->sizePolicy().hasHeightForWidth());
        expFixed->setSizePolicy(sizePolicy2);
        expFixed->setMinimumSize(QSize(0, 30));
        expFixed->setMaximumSize(QSize(20, 16777215));

        Layout_level_exp->addWidget(expFixed);

        exp = new QLabel(verticalWidget);
        exp->setObjectName(QStringLiteral("exp"));
        sizePolicy2.setHeightForWidth(exp->sizePolicy().hasHeightForWidth());
        exp->setSizePolicy(sizePolicy2);
        exp->setMinimumSize(QSize(50, 30));

        Layout_level_exp->addWidget(exp);


        verticalLayout->addLayout(Layout_level_exp);

        Layout_hp_strength = new QHBoxLayout();
        Layout_hp_strength->setObjectName(QStringLiteral("Layout_hp_strength"));
        Layout_hp_strength->setSizeConstraint(QLayout::SetNoConstraint);
        hpFixed = new QLabel(verticalWidget);
        hpFixed->setObjectName(QStringLiteral("hpFixed"));
        sizePolicy2.setHeightForWidth(hpFixed->sizePolicy().hasHeightForWidth());
        hpFixed->setSizePolicy(sizePolicy2);
        hpFixed->setMinimumSize(QSize(0, 30));
        hpFixed->setMaximumSize(QSize(20, 16777215));

        Layout_hp_strength->addWidget(hpFixed);

        hp = new QLabel(verticalWidget);
        hp->setObjectName(QStringLiteral("hp"));
        sizePolicy2.setHeightForWidth(hp->sizePolicy().hasHeightForWidth());
        hp->setSizePolicy(sizePolicy2);
        hp->setMinimumSize(QSize(50, 30));

        Layout_hp_strength->addWidget(hp);

        strengthFixed = new QLabel(verticalWidget);
        strengthFixed->setObjectName(QStringLiteral("strengthFixed"));
        sizePolicy2.setHeightForWidth(strengthFixed->sizePolicy().hasHeightForWidth());
        strengthFixed->setSizePolicy(sizePolicy2);
        strengthFixed->setMinimumSize(QSize(0, 30));
        strengthFixed->setMaximumSize(QSize(20, 16777215));

        Layout_hp_strength->addWidget(strengthFixed);

        strength = new QLabel(verticalWidget);
        strength->setObjectName(QStringLiteral("strength"));
        sizePolicy2.setHeightForWidth(strength->sizePolicy().hasHeightForWidth());
        strength->setSizePolicy(sizePolicy2);
        strength->setMinimumSize(QSize(50, 30));

        Layout_hp_strength->addWidget(strength);


        verticalLayout->addLayout(Layout_hp_strength);

        Layout_defense_speed = new QHBoxLayout();
        Layout_defense_speed->setObjectName(QStringLiteral("Layout_defense_speed"));
        Layout_defense_speed->setSizeConstraint(QLayout::SetNoConstraint);
        defenseFixed = new QLabel(verticalWidget);
        defenseFixed->setObjectName(QStringLiteral("defenseFixed"));
        sizePolicy2.setHeightForWidth(defenseFixed->sizePolicy().hasHeightForWidth());
        defenseFixed->setSizePolicy(sizePolicy2);
        defenseFixed->setMinimumSize(QSize(0, 30));
        defenseFixed->setMaximumSize(QSize(20, 16777215));

        Layout_defense_speed->addWidget(defenseFixed);

        defense = new QLabel(verticalWidget);
        defense->setObjectName(QStringLiteral("defense"));
        sizePolicy2.setHeightForWidth(defense->sizePolicy().hasHeightForWidth());
        defense->setSizePolicy(sizePolicy2);
        defense->setMinimumSize(QSize(50, 30));

        Layout_defense_speed->addWidget(defense);

        speedFixed = new QLabel(verticalWidget);
        speedFixed->setObjectName(QStringLiteral("speedFixed"));
        sizePolicy2.setHeightForWidth(speedFixed->sizePolicy().hasHeightForWidth());
        speedFixed->setSizePolicy(sizePolicy2);
        speedFixed->setMinimumSize(QSize(0, 30));
        speedFixed->setMaximumSize(QSize(20, 16777215));

        Layout_defense_speed->addWidget(speedFixed);

        speed = new QLabel(verticalWidget);
        speed->setObjectName(QStringLiteral("speed"));
        sizePolicy2.setHeightForWidth(speed->sizePolicy().hasHeightForWidth());
        speed->setSizePolicy(sizePolicy2);
        speed->setMinimumSize(QSize(50, 30));

        Layout_defense_speed->addWidget(speed);


        verticalLayout->addLayout(Layout_defense_speed);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        retranslateUi(SingleCreature);

        QMetaObject::connectSlotsByName(SingleCreature);
    } // setupUi

    void retranslateUi(QWidget *SingleCreature)
    {
        SingleCreature->setWindowTitle(QApplication::translate("SingleCreature", "SingleCreature", nullptr));
        name->setText(QApplication::translate("SingleCreature", "test", nullptr));
        property->setText(QApplication::translate("SingleCreature", "test", nullptr));
        type->setText(QApplication::translate("SingleCreature", "test", nullptr));
        levelFixed->setText(QApplication::translate("SingleCreature", "\347\272\247:", nullptr));
        level->setText(QApplication::translate("SingleCreature", "test", nullptr));
        expFixed->setText(QApplication::translate("SingleCreature", "ex:", nullptr));
        exp->setText(QApplication::translate("SingleCreature", "test", nullptr));
        hpFixed->setText(QApplication::translate("SingleCreature", "\344\275\223:", nullptr));
        hp->setText(QApplication::translate("SingleCreature", "test", nullptr));
        strengthFixed->setText(QApplication::translate("SingleCreature", "\345\212\233:", nullptr));
        strength->setText(QApplication::translate("SingleCreature", "test", nullptr));
        defenseFixed->setText(QApplication::translate("SingleCreature", "\351\230\262:", nullptr));
        defense->setText(QApplication::translate("SingleCreature", "test", nullptr));
        speedFixed->setText(QApplication::translate("SingleCreature", "\351\200\237:", nullptr));
        speed->setText(QApplication::translate("SingleCreature", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleCreature: public Ui_SingleCreature {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLECREATURE_H
