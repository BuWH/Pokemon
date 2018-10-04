//
// Created by 温和 on 2018/9/30.
//
#pragma once
#ifndef POKEMON_BASECREATURE_H
#define POKEMON_BASECREATURE_H

#include <string>
#include <QString>
#include <random>
#include "constdefine.h"
#include <QDebug>

class BaseCreature {
public:
    BaseCreature();

    std::string getName() { return this->name; };

    int getLevel() { return this->level; };

    int getExp() { return this->exp; };

    int getHp() { return this->hp; };

    float getStrength() { return this->strength; };

    float getDefense() { return this->defense; };

    float getAttackInterval() { return this->attack_interval; };

    std::string getType() {
        switch (this->type) {
            case Type::attacker:
                return "力士";
            case Type::tanker  :
                return "坦克";
            case Type::defender:
                return "御者";
            case Type::assassin:
                return "刺客";
        }
    }

    void setType(Type type) { this->type = type; };

    void setName(std::string name) { this->name = name; };

    void setLevel(int level) { this->level = level; };

    void setHp(int hp) { this->hp = hp; };

    void setExp(int exp) { this->exp = exp; };

    void setStrength(float strength) { this->strength = strength; };

    void setDefense(float defense) { this->defense = defense; };

    void setAttackInterval(float interval) { this->attack_interval = interval; };

    void addExp(int exp);

    void printCreature();

    void printCreature_QT();

    int attack();

    void defend(float attack);

    float randomGrow(float attribute);

    void initAbility();
private:
    Type type;
    std::string name;
    int level;
    int exp;
    float strength;
    float defense;
    int hp;
    float attack_interval;

    virtual void upgrade();
};


#endif //POKEMON_CREATURE_H
