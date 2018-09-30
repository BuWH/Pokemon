//
// Created by 温和 on 2018/9/30.
//
#pragma once
#ifndef POKEMON_CREATURE_H
#define POKEMON_CREATURE_H

#include <string>
#include <QDebug>

enum Type {
    attacker,
    tanker,
    defender,
    assassin
};

class BaseCreature {
public:
    BaseCreature();

    int getLevel() { return this->level; };

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

    std::string getName() { return this->name; };

    int getExp() { return this->exp; };

    int getHp() { return this->hp; };

    void printCreature();

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

    int attack();

    void defend(int attack);
};

BaseCreature::BaseCreature() {
    type = Type::attacker;
    name = "lalala";
    level = 1;
    exp = 0;
    strength = 1;
    defense = 1;
    hp = 1;
    attack_interval = 1.0;
}

void BaseCreature::printCreature() {
    /*
    std::cout<< "Name: " << std::setw(10) << this->name    << "   Type: " << std::setw(3) << this->getType() << std::endl
             << "Lv: "   << std::setw(3)  << this->level   << "  Exp: "   << std::setw(3) << this->exp       << std::endl
             << "H : "   << std::setw(3)  << this->hp      << "  S  : "   << std::setw(3) << this->strength
             << "  D: "  << std::setw(3)  << this->defense << "  T: "     << std::setw(3) << this->attack_interval << std::endl;
    */
    qDebug() << "QDebug Test";
}

void BaseCreature::upgrade() {
    this->level++;
}

int BaseCreature::attack() {
    return 100;
}

void BaseCreature::defend(int attack) {
    this->hp -= (attack - this->defense);
}

#endif //POKEMON_CREATURE_H
