#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "/Users/wenhe/code/Pokemon/include/user.h"
#include "singlecreature/singlecreature.h"
#include "fight/fight.h"
#include "login/login.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget {

Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();

protected:
    void refresh();
    void refresh_tab1();
    void refresh_tab2();
    void upgradeCreature();
    void generateCreature();
    void clearUser();
    void fightTest();
    void sendUser();
    void sendCreature();
private:
    Ui::Widget *ui;
    SingleCreature *tempCreature = nullptr;
    Login *login;
    Fight *fight;
    BaseCreature *currentCreature = nullptr;
    User *user = nullptr;
    QVector<SingleCreature *> creatures;
};

#endif // WIDGET_H
