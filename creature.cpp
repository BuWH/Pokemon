//
// Created by 温和 on 2018/10/1.
//
#include "creature.h"

AttackerCreatrue::AttackerCreatrue() {
    this->setName("Attacker");
    this->setType(Type::attacker);
    this->initAbility();
}

void AttackerCreatrue::upgrade() {
    this->setLevel(this->getLevel() + 1);
    this->setHp(this->getHp() + this->randomGrow(ATTACKER_GROW_HP));
    this->setStrength(this->getStrength() + this->randomGrow(ATTACKER_GROW_STRENGTH));
    this->setDefense(this->getDefense() + this->randomGrow(ATTACKER_GROW_DEFNESE));
    this->setAttackInterval(this->getAttackInterval() + this->randomGrow(ATTACKER_GROW_ATTACK_INTERVAL));
}