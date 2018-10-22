//
// Created by 温和 on 2018/10/16.
//
#pragma once
#ifndef POKEMON_USER_H
#define POKEMON_USER_H

#include "constdefine.h"
#include "attacker.h"
#include "assassin.h"
#include "defender.h"
#include "tanker.h"

#include <QVector>

class User {
public:
    User();

public slots:

    void setName(QString name) { this->name = name; };
private:
    QString name;

    //float getWinRate();

    QVector<BaseCreature *> creatures;

    int getCreaturesNum() { return this->creatures.size(); };

    BaseCreature *getRandomCreature();

private slots:

    void addCreature();

    void addCreature(BaseCreature *&creature);
};

#endif //POKEMON_USER_H
