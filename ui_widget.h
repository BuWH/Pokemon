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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget {
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QVBoxLayout *tab_1_layout;
    QLabel *user_name;
    QLabel *creature_num;
    QLabel *name;
    QLabel *id;
    QLabel *type;
    QLabel *level;
    QLabel *exp;
    QLabel *hp;
    QLabel *strength;
    QLabel *defense;
    QLabel *speed;
    QPushButton *generate;
    QPushButton *upgrade;
    QPushButton *clear;
    QWidget *tab_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QWidget *creatures_list;
    QVBoxLayout *creatures_list_layout;

    void setupUi(QWidget *Widget) {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setEnabled(true);
        Widget->resize(300, 605);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        sizePolicy.setHeightForWidth(tab_1->sizePolicy().hasHeightForWidth());
        tab_1->setSizePolicy(sizePolicy);
        tab_1->setAutoFillBackground(false);
        tab_1_layout = new QVBoxLayout(tab_1);
        tab_1_layout->setSpacing(6);
        tab_1_layout->setContentsMargins(11, 11, 11, 11);
        tab_1_layout->setObjectName(QStringLiteral("tab_1_layout"));
        user_name = new QLabel(tab_1);
        user_name->setObjectName(QStringLiteral("user_name"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(user_name->sizePolicy().hasHeightForWidth());
        user_name->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(user_name);

        creature_num = new QLabel(tab_1);
        creature_num->setObjectName(QStringLiteral("creature_num"));
        sizePolicy1.setHeightForWidth(creature_num->sizePolicy().hasHeightForWidth());
        creature_num->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(creature_num);

        name = new QLabel(tab_1);
        name->setObjectName(QStringLiteral("name"));
        sizePolicy1.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(name);

        id = new QLabel(tab_1);
        id->setObjectName(QStringLiteral("id"));
        sizePolicy1.setHeightForWidth(id->sizePolicy().hasHeightForWidth());
        id->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(id);

        type = new QLabel(tab_1);
        type->setObjectName(QStringLiteral("type"));
        sizePolicy1.setHeightForWidth(type->sizePolicy().hasHeightForWidth());
        type->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(type);

        level = new QLabel(tab_1);
        level->setObjectName(QStringLiteral("level"));
        sizePolicy1.setHeightForWidth(level->sizePolicy().hasHeightForWidth());
        level->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(level);

        exp = new QLabel(tab_1);
        exp->setObjectName(QStringLiteral("exp"));
        sizePolicy1.setHeightForWidth(exp->sizePolicy().hasHeightForWidth());
        exp->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(exp);

        hp = new QLabel(tab_1);
        hp->setObjectName(QStringLiteral("hp"));
        sizePolicy1.setHeightForWidth(hp->sizePolicy().hasHeightForWidth());
        hp->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(hp);

        strength = new QLabel(tab_1);
        strength->setObjectName(QStringLiteral("strength"));
        sizePolicy1.setHeightForWidth(strength->sizePolicy().hasHeightForWidth());
        strength->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(strength);

        defense = new QLabel(tab_1);
        defense->setObjectName(QStringLiteral("defense"));
        sizePolicy1.setHeightForWidth(defense->sizePolicy().hasHeightForWidth());
        defense->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(defense);

        speed = new QLabel(tab_1);
        speed->setObjectName(QStringLiteral("speed"));
        sizePolicy1.setHeightForWidth(speed->sizePolicy().hasHeightForWidth());
        speed->setSizePolicy(sizePolicy1);

        tab_1_layout->addWidget(speed);

        generate = new QPushButton(tab_1);
        generate->setObjectName(QStringLiteral("generate"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(generate->sizePolicy().hasHeightForWidth());
        generate->setSizePolicy(sizePolicy2);
        generate->setMinimumSize(QSize(0, 0));

        tab_1_layout->addWidget(generate);

        upgrade = new QPushButton(tab_1);
        upgrade->setObjectName(QStringLiteral("upgrade"));
        sizePolicy2.setHeightForWidth(upgrade->sizePolicy().hasHeightForWidth());
        upgrade->setSizePolicy(sizePolicy2);

        tab_1_layout->addWidget(upgrade);

        clear = new QPushButton(tab_1);
        clear->setObjectName(QStringLiteral("clear"));
        sizePolicy2.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy2);

        tab_1_layout->addWidget(clear);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(40, 130, 200, 251));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy3);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 200, 249));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        creatures_list = new QWidget(scrollAreaWidgetContents);
        creatures_list->setObjectName(QStringLiteral("creatures_list"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(creatures_list->sizePolicy().hasHeightForWidth());
        creatures_list->setSizePolicy(sizePolicy4);
        creatures_list->setMinimumSize(QSize(200, 240));
        creatures_list_layout = new QVBoxLayout(creatures_list);
        creatures_list_layout->setSpacing(6);
        creatures_list_layout->setContentsMargins(11, 11, 11, 11);
        creatures_list_layout->setObjectName(QStringLiteral("creatures_list_layout"));
        creatures_list_layout->setContentsMargins(0, 0, 0, 5);

        verticalLayout_3->addWidget(creatures_list);

        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget) {
        Widget->setWindowTitle(QApplication::translate("Widget", "Pokemon Test", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        tab_1->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        user_name->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215:", nullptr));
        creature_num->setText(
                QApplication::translate("Widget", "\347\262\276\347\201\265\346\225\260\351\207\217:", nullptr));
        name->setText(QApplication::translate("Widget", "\345\220\215:", nullptr));
        id->setText(QApplication::translate("Widget", "\347\274\226:", nullptr));
        type->setText(QApplication::translate("Widget", "\347\261\273:", nullptr));
        level->setText(QApplication::translate("Widget", "\347\272\247:", nullptr));
        exp->setText(QApplication::translate("Widget", "Ex:", nullptr));
        hp->setText(QApplication::translate("Widget", "\344\275\223:", nullptr));
        strength->setText(QApplication::translate("Widget", "\345\212\233:", nullptr));
        defense->setText(QApplication::translate("Widget", "\351\230\262:", nullptr));
        speed->setText(QApplication::translate("Widget", "\351\200\237:", nullptr));
        generate->setText(QApplication::translate("Widget", "\345\257\273\346\211\276", nullptr));
        upgrade->setText(QApplication::translate("Widget", "\345\215\207\347\272\247", nullptr));
        clear->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
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
