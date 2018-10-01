//
// Created by 温和 on 2018/10/1.
//
#include "creature.h"

AttackerCreatrue::AttackerCreatrue() {
    this->setName("Attacker");
    this->setType(Type::attacker);
    this->setHp(ATTACKER_INIT_HP);
    this->setStrength(ATTACKER_INIT_STRENGTH);
    this->setDefense(ATTACKER_INIT_DEFNESE);
    this->setAttackInterval(ATTACKER_INIT_ATTACK_INTERVAL);
}
