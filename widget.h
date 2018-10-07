#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "attacker.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget {

Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();

protected:
    //QLabel name, type, level, exp, hp, strength, defense, speed;
    //QPushButton generate, upgrade;

    void refresh();
    void creatureTest();

    void upgradeCreature();
    void generateCreature();

private:
    Ui::Widget *ui;
    AttackerCreatrue *attacker;
    TankerCreatrue *tanker;
};

#endif // WIDGET_H
