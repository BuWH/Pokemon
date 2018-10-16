//
// Created by 温和 on 2018/10/16.
//
#pragma once
#ifndef POKEMON_CREATURE_H
#define POKEMON_CREATURE_H

#include "constdefine.h"
#include "attacker.h"
#include "assassin.h"
#include "defender.h"
#include "tanker.h"
#include <ctime>

class Creature {
public:
    Creature();

private:
    Type type;

    AttackerCreatrue *attacker = nullptr;
    DefenderCreatrue *defender = nullptr;
    TankerCreatrue *tanker = nullptr;
    AssassinCreatrue *assassin = nullptr;

    void initCreature();

    void deleteCreature();
};

#endif //POKEMON_CREATURE_H
