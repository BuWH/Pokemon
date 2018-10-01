//
// Created by 温和 on 2018/9/30.
//
#pragma once
#ifndef POKEMON_BASECREATURE_H
#define POKEMON_BASECREATURE_H

#include <string>
#include "constdefine.h"
#include <QDebug>

class BaseCreature {
public:
    BaseCreature();

    std::string getName() { return this->name; };

    int getLevel() { return this->level; };

    int getExp() { return this->exp; };

    int getHp() { return this->hp; };

    std::string getType() {
        switch (this->type) {
            case Type::attacker:
                return "attacker";
            case Type::tanker  :
                return "tanker";
            case Type::defender:
                return "defender";
            case Type::assassin:
                return "assassin";
        }
    }

    void setType(Type type) { this->type = type; };

    void setName(std::string name) { this->name = name; };

    void setHp(int hp) { this->hp = hp; };

    void setExp(int exp) { this->exp = exp; };

    void setStrength(int strength) { this->strength = strength; };

    void setDefense(int defense) { this->defense = defense; };

    void setAttackInterval(int interval) { this->attack_interval = interval; };

    void addExp(int exp);

    void printCreature();

    int attack();

    void defend(int attack);

private:
    Type type;
    std::string name;
    int level;
    int exp;
    int strength;
    int defense;
    int hp;
    float attack_interval;

    void upgrade();
};


#endif //POKEMON_CREATURE_H
