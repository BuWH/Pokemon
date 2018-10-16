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

typedef struct creature {
    Type type;
    AttackerCreatrue *attacker;
    DefenderCreatrue *defender;
    TankerCreatrue *tanker;
    AssassinCreatrue *assassin;
} *Creatrue;

class User {
public:
    User();

private:
    QString name;

    float getWinRate();

    QVector creatrues<Creatrue>;

    Creatrue getRandomCreature();
};

#endif //POKEMON_USER_H
