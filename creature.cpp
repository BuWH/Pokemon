//
// Created by 温和 on 2018/10/16.
//
#include "creature.h"


Creature::Creature() {
    this->initCreature();
}

void Creature::initCreature() {
    this->deleteCreature();
    std::default_random_engine e(time(NULL));
    int type_num = e() % 4;
    switch (type_num) {
        case Type::attacker:
            this->type = Type::attacker;
            this->attacker = new AttackerCreatrue;
            break;
        case Type::defender:
            this->type = Type::defender;
            this->defender = new DefenderCreatrue;
            break;
        case Type::tanker:
            this->type = Type::tanker;
            this->tanker = new TankerCreatrue;
            break;
        case Type::assassin:
            this->type = Type::assassin;
            this->assassin = new AssassinCreatrue;
            break;
    }
}

void Creature::deleteCreature() {
    delete this->attacker;
    this->attacker = nullptr;
    delete this->defender;
    this->defender = nullptr;
    delete this->tanker;
    this->tanker = nullptr;
    delete this->assassin;
    this->assassin = nullptr;
}