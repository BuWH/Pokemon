//
// Created by 温和 on 2018/10/1.
//
#include "creature.h"

AttackerCreatrue::AttackerCreatrue() {
    this->setName("Attacker");
    this->setType(Type::attacker);
    this->setHp(10);
    this->setStrength(5);
    this->setDefense(2);
    this->setAttackInterval(1);
}
