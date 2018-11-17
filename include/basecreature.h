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
    static unsigned int creature_id;
    BaseCreature();
    ~BaseCreature();
    void setName(QString name) { this->name = name; };

    QString getName() const { return this->name; };
    int getLevel() const { return this->level; };
    int getExp() const { return this->exp; };
    int getHp() const { return this->hp; };

    unsigned int getID() const { return this->id; };
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
            default:
                return "ERROR";
        }
    }

    Property getProperty() const { return this->property; };
    QString getPropertyString() const {
        switch (this->property) {
            case Property::gold:
                return "金";
            case Property::wood:
                return "木";
            case Property::water:
                return "水";
            case Property::fire:
                return "火";
            case Property::solid:
                return "土";
            default:
                return "ERROR";
        }
    }

    void initLevel(int level) {
        for (int i = 0; i < (this->level - level); ++i) {
            upgrade();
        }
    }

    virtual void upgrade();

protected:
    void setType(Type type) { this->type = type; };
    void setHp(int hp) { this->hp = hp; };
    void setLevel(int level) { this->level = level; };
    void setStrength(float strength) { this->strength = strength; };
    void setDefense(float defense) { this->defense = defense; };
    void setSpeed(float interval) { this->speed = interval; };

    void addExp(int exp);

    float randomGrow(float attribute);

    void initProperty();
    virtual void initAbility();

private:
    Type type;
    Property property;
    QString name;
    int level;
    int exp;
    unsigned int id;
    float strength;
    float defense;
    int hp;
    float speed;
};


#endif //POKEMON_CREATURE_H
