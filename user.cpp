//
// Created by 温和 on 2018/10/16.
//
#include "user.h"
#include <random>
#include <time.h>

User::User() {
    this->name = "wenhe";
}

BaseCreature *User::getRandomCreature() {
    static std::default_random_engine e;
    static std::uniform_int_distribution<int> dis(0, 3);
    BaseCreature *creature;
    switch (dis(e)) {
        case Type::attacker: {
            AttackerCreatrue *tempAttacker = new AttackerCreatrue;
            creature = tempAttacker;
            break;
        }
        case Type::defender: {
            DefenderCreatrue *tempDefender = new DefenderCreatrue;
            creature = tempDefender;
            break;
        }
        case Type::tanker: {
            TankerCreatrue *tempTanker = new TankerCreatrue;
            creature = tempTanker;
            break;
        }
        case Type::assassin: {
            AssassinCreatrue *tempAssassin = new AssassinCreatrue;
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
        return NULL;
    } else {
        return creatures[i];
    }
}