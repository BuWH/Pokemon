//
// Created by 温和 on 2018/10/16.
//
#include "/Users/wenhe/code/Pokemon/include/user.h"
#include <random>
#include <ctime>
#include <include/user.h>


User::User(QString name) {
    this->id = user_id;
    this->name = name;
}

User::~User() {
    for (auto &creature : creatures) {
        delete creature;
    }
    creatures.clear();
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
        default:
            break;
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

QString User::generateData() const {
    QString data = "";
    data += (QString::number(id) + ',');
    data += (name + ',');
    data += (QString::number(winFights) + ',');
    data += (QString::number(totalFights) + ',');
    data += (QString::number(creatures.size()));
    for (auto creature : creatures) {
        data += (',' + creature->generateData());
    }
    return data;
}
