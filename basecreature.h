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
    static int id;
    
    BaseCreature();

    void setName(QString name) { this->name = name; };

    QString getName() const { return this->name; };

    int getLevel() const { return this->level; };

    int getExp() const { return this->exp; };

    int getHp() const { return this->hp; };

    int getID() const { return this->creature_id; };

    float getStrength() const { return this->strength; };

    float getDefense() const { return this->defense; };

    float getSpeed() const { return this->speed; };

    QString getType() const {
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

    void printCreature();

    void printCreature_QT();

    virtual void upgrade();

protected:

    void setType(Type type) { this->type = type; };

    void setLevel(int level) { this->level = level; };

    void setHp(int hp) { this->hp = hp; };

    void setExp(int exp) { this->exp = exp; };

    void setStrength(float strength) { this->strength = strength; };

    void setDefense(float defense) { this->defense = defense; };

    void setSpeed(float interval) { this->speed = interval; };

    void addExp(int exp);

    int attack();

    void defend(float attack);

    float randomGrow(float attribute);

    virtual void initAbility();

private:
    Type type;
    Property Property;
    QString name;
    int level;
    int exp;
    int creature_id;
    float strength;
    float defense;
    int hp;
    float speed;
};


#endif //POKEMON_CREATURE_H
