//
// Created by 温和 on 2018/10/16.
//
#include "/Users/wenhe/code/Pokemon/include/user.h"
#include <random>
#include <ctime>

User::User(QString name) {
    this->name = name;
}

BaseCreature *User::getRandomCreature() {
    static std::default_random_engine e(unsigned(time(NULL)));
    static std::uniform_int_distribution<int> dis(0, 3);
    BaseCreature *creature;
    switch (dis(e)) {
        case Type::attacker: {
            auto tempAttacker = new AttackerCreatrue;
            creature = tempAttacker;
            break;
        }
        case Type::defender: {
            auto tempDefender = new DefenderCreatrue;
            creature = tempDefender;
            break;
        }
        case Type::tanker: {
            auto *tempTanker = new TankerCreatrue;
            creature = tempTanker;
            break;
        }
        case Type::assassin: {
            auto *tempAssassin = new AssassinCreatrue;
            creature = tempAssassin;
            break;
        }
    }
    return creature;
}

void User::addCreature() {
    this->creatures.append(this->getRandomCreature());
}

void User::addCreature(BaseCreature *&creature) {
    this->creatures.append(creature);
}

BaseCreature *User::getCreature(int i) const {
    if (i > this->creatures.size()) {
        return nullptr;
    } else {
        return creatures[i];
    }
}