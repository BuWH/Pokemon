/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget {
public:
    QLabel *name;
    QLabel *type;
    QPushButton *generate;
    QPushButton *upgrade;
    QLabel *level;
    QLabel *hp;
    QLabel *strength;
    QLabel *exp;
    QLabel *speed;
    QLabel *defense;
    QLabel *id;
    QLabel *user_name;
    QPushButton *clear;
    QLabel *creature_num;

    void setupUi(QWidget *Widget) {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setEnabled(true);
        Widget->resize(300, 600);
        name = new QLabel(Widget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(50, 170, 200, 30));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        type = new QLabel(Widget);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(50, 230, 200, 30));
        sizePolicy.setHeightForWidth(type->sizePolicy().hasHeightForWidth());
        type->setSizePolicy(sizePolicy);
        generate = new QPushButton(Widget);
        generate->setObjectName(QStringLiteral("generate"));
        generate->setGeometry(QRect(40, 450, 220, 40));
        upgrade = new QPushButton(Widget);
        upgrade->setObjectName(QStringLiteral("upgrade"));
        upgrade->setGeometry(QRect(40, 490, 220, 40));
        level = new QLabel(Widget);
        level->setObjectName(QStringLiteral("level"));
        level->setGeometry(QRect(50, 260, 200, 30));
        sizePolicy.setHeightForWidth(level->sizePolicy().hasHeightForWidth());
        level->setSizePolicy(sizePolicy);
        hp = new QLabel(Widget);
        hp->setObjectName(QStringLiteral("hp"));
        hp->setGeometry(QRect(50, 320, 200, 30));
        sizePolicy.setHeightForWidth(hp->sizePolicy().hasHeightForWidth());
        hp->setSizePolicy(sizePolicy);
        strength = new QLabel(Widget);
        strength->setObjectName(QStringLiteral("strength"));
        strength->setGeometry(QRect(50, 350, 200, 30));
        sizePolicy.setHeightForWidth(strength->sizePolicy().hasHeightForWidth());
        strength->setSizePolicy(sizePolicy);
        exp = new QLabel(Widget);
        exp->setObjectName(QStringLiteral("exp"));
        exp->setGeometry(QRect(50, 290, 200, 30));
        sizePolicy.setHeightForWidth(exp->sizePolicy().hasHeightForWidth());
        exp->setSizePolicy(sizePolicy);
        speed = new QLabel(Widget);
        speed->setObjectName(QStringLiteral("speed"));
        speed->setGeometry(QRect(50, 410, 200, 30));
        sizePolicy.setHeightForWidth(speed->sizePolicy().hasHeightForWidth());
        speed->setSizePolicy(sizePolicy);
        defense = new QLabel(Widget);
        defense->setObjectName(QStringLiteral("defense"));
        defense->setGeometry(QRect(50, 380, 200, 30));
        sizePolicy.setHeightForWidth(defense->sizePolicy().hasHeightForWidth());
        defense->setSizePolicy(sizePolicy);
        id = new QLabel(Widget);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(50, 200, 200, 30));
        sizePolicy.setHeightForWidth(id->sizePolicy().hasHeightForWidth());
        id->setSizePolicy(sizePolicy);
        user_name = new QLabel(Widget);
        user_name->setObjectName(QStringLiteral("user_name"));
        user_name->setGeometry(QRect(50, 70, 200, 30));
        sizePolicy.setHeightForWidth(user_name->sizePolicy().hasHeightForWidth());
        user_name->setSizePolicy(sizePolicy);
        clear = new QPushButton(Widget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(40, 530, 220, 40));
        creature_num = new QLabel(Widget);
        creature_num->setObjectName(QStringLiteral("creature_num"));
        creature_num->setGeometry(QRect(50, 100, 200, 30));
        sizePolicy.setHeightForWidth(creature_num->sizePolicy().hasHeightForWidth());
        creature_num->setSizePolicy(sizePolicy);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget) {
        Widget->setWindowTitle(QApplication::translate("Widget", "Pokemon Test", nullptr));
        name->setText(QApplication::translate("Widget", "\345\220\215:", nullptr));
        type->setText(QApplication::translate("Widget", "\347\261\273:", nullptr));
        generate->setText(QApplication::translate("Widget", "\345\257\273\346\211\276", nullptr));
        upgrade->setText(QApplication::translate("Widget", "\345\215\207\347\272\247", nullptr));
        level->setText(QApplication::translate("Widget", "\347\272\247:", nullptr));
        hp->setText(QApplication::translate("Widget", "\344\275\223:", nullptr));
        strength->setText(QApplication::translate("Widget", "\345\212\233:", nullptr));
        exp->setText(QApplication::translate("Widget", "Ex:", nullptr));
        speed->setText(QApplication::translate("Widget", "\351\200\237:", nullptr));
        defense->setText(QApplication::translate("Widget", "\351\230\262:", nullptr));
        id->setText(QApplication::translate("Widget", "\344\275\215:", nullptr));
        user_name->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215:", nullptr));
        clear->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        creature_num->setText(
                QApplication::translate("Widget", "\347\262\276\347\201\265\346\225\260\351\207\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget : public Ui_Widget {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
