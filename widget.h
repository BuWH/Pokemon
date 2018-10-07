#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "attacker.h"

class Widget : public QWidget {

Q_OBJECT

public:
    Widget(QWidget *parent = 0);

    ~Widget();

protected:
    QLabel name, type, level, exp, hp, strength, defense, speed;
    QPushButton generate, upgrade;

    void refresh();
    void creatureTest();

    void upgradeCreature();
    void generateCreature();

private:
    AttackerCreatrue *attacker;
    TankerCreatrue *tanker;
};

#endif // WIDGET_H
