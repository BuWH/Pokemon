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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget {
public:
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QLabel *creature_num;
    QPushButton *generate;
    QLabel *name;
    QLabel *speed;
    QPushButton *clear;
    QLabel *defense;
    QLabel *hp;
    QLabel *user_name;
    QPushButton *upgrade;
    QLabel *type;
    QLabel *id;
    QLabel *level;
    QLabel *strength;
    QLabel *exp;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *creatures_Layout;

    void setupUi(QWidget *Widget) {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setEnabled(true);
        Widget->resize(300, 600);
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 281, 571));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        tab_1->setAutoFillBackground(false);
        creature_num = new QLabel(tab_1);
        creature_num->setObjectName(QStringLiteral("creature_num"));
        creature_num->setGeometry(QRect(35, 70, 200, 30));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(creature_num->sizePolicy().hasHeightForWidth());
        creature_num->setSizePolicy(sizePolicy);
        generate = new QPushButton(tab_1);
        generate->setObjectName(QStringLiteral("generate"));
        generate->setGeometry(QRect(25, 400, 220, 40));
        name = new QLabel(tab_1);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(35, 120, 200, 30));
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        speed = new QLabel(tab_1);
        speed->setObjectName(QStringLiteral("speed"));
        speed->setGeometry(QRect(35, 360, 200, 30));
        sizePolicy.setHeightForWidth(speed->sizePolicy().hasHeightForWidth());
        speed->setSizePolicy(sizePolicy);
        clear = new QPushButton(tab_1);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(25, 480, 220, 40));
        defense = new QLabel(tab_1);
        defense->setObjectName(QStringLiteral("defense"));
        defense->setGeometry(QRect(35, 330, 200, 30));
        sizePolicy.setHeightForWidth(defense->sizePolicy().hasHeightForWidth());
        defense->setSizePolicy(sizePolicy);
        hp = new QLabel(tab_1);
        hp->setObjectName(QStringLiteral("hp"));
        hp->setGeometry(QRect(35, 270, 200, 30));
        sizePolicy.setHeightForWidth(hp->sizePolicy().hasHeightForWidth());
        hp->setSizePolicy(sizePolicy);
        user_name = new QLabel(tab_1);
        user_name->setObjectName(QStringLiteral("user_name"));
        user_name->setGeometry(QRect(35, 40, 200, 30));
        sizePolicy.setHeightForWidth(user_name->sizePolicy().hasHeightForWidth());
        user_name->setSizePolicy(sizePolicy);
        upgrade = new QPushButton(tab_1);
        upgrade->setObjectName(QStringLiteral("upgrade"));
        upgrade->setGeometry(QRect(25, 440, 220, 40));
        type = new QLabel(tab_1);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(35, 180, 200, 30));
        sizePolicy.setHeightForWidth(type->sizePolicy().hasHeightForWidth());
        type->setSizePolicy(sizePolicy);
        id = new QLabel(tab_1);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(35, 150, 200, 30));
        sizePolicy.setHeightForWidth(id->sizePolicy().hasHeightForWidth());
        id->setSizePolicy(sizePolicy);
        level = new QLabel(tab_1);
        level->setObjectName(QStringLiteral("level"));
        level->setGeometry(QRect(35, 210, 200, 30));
        sizePolicy.setHeightForWidth(level->sizePolicy().hasHeightForWidth());
        level->setSizePolicy(sizePolicy);
        strength = new QLabel(tab_1);
        strength->setObjectName(QStringLiteral("strength"));
        strength->setGeometry(QRect(35, 300, 200, 30));
        sizePolicy.setHeightForWidth(strength->sizePolicy().hasHeightForWidth());
        strength->setSizePolicy(sizePolicy);
        exp = new QLabel(tab_1);
        exp->setObjectName(QStringLiteral("exp"));
        exp->setGeometry(QRect(35, 240, 200, 30));
        sizePolicy.setHeightForWidth(exp->sizePolicy().hasHeightForWidth());
        exp->setSizePolicy(sizePolicy);
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 30, 131, 431));
        creatures_Layout = new QVBoxLayout(verticalLayoutWidget);
        creatures_Layout->setSpacing(6);
        creatures_Layout->setContentsMargins(11, 11, 11, 11);
        creatures_Layout->setObjectName(QStringLiteral("creatures_Layout"));
        creatures_Layout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget) {
        Widget->setWindowTitle(QApplication::translate("Widget", "Pokemon Test", nullptr));
        creature_num->setText(
                QApplication::translate("Widget", "\347\262\276\347\201\265\346\225\260\351\207\217:", nullptr));
        generate->setText(QApplication::translate("Widget", "\345\257\273\346\211\276", nullptr));
        name->setText(QApplication::translate("Widget", "\345\220\215:", nullptr));
        speed->setText(QApplication::translate("Widget", "\351\200\237:", nullptr));
        clear->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        defense->setText(QApplication::translate("Widget", "\351\230\262:", nullptr));
        hp->setText(QApplication::translate("Widget", "\344\275\223:", nullptr));
        user_name->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215:", nullptr));
        upgrade->setText(QApplication::translate("Widget", "\345\215\207\347\272\247", nullptr));
        type->setText(QApplication::translate("Widget", "\347\261\273:", nullptr));
        id->setText(QApplication::translate("Widget", "\347\274\226:", nullptr));
        level->setText(QApplication::translate("Widget", "\347\272\247:", nullptr));
        strength->setText(QApplication::translate("Widget", "\345\212\233:", nullptr));
        exp->setText(QApplication::translate("Widget", "Ex:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("Widget", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget : public Ui_Widget {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
