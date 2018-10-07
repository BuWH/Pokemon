//
// Created by 温和 on 2018/10/1.
//
#include "attacker.h"

AttackerCreatrue::AttackerCreatrue() {
    this->setName("Attacker");
    this->setType(Type::attacker);
    this->initAbility();
}

void AttackerCreatrue::upgrade() {
    if (this->getLevel() < LEVEL_TOP) {
        this->setLevel(this->getLevel() + 1);
        this->setHp(this->getHp() + this->randomGrow(ATTACKER_GROW_HP));
        this->setStrength(this->getStrength() + this->randomGrow(ATTACKER_GROW_STRENGTH));
        this->setDefense(this->getDefense() + this->randomGrow(ATTACKER_GROW_DEFNESE));
        this->setSpeed(this->getSpeed() + this->randomGrow(ATTACKER_GROW_SPEED));
    }
}

void AttackerCreatrue::initAbility() {
    static std::default_random_engine e;
    static std::normal_distribution<float> n(0, 0.2);
    this->setHp(ATTACKER_INIT_HP + round(n(e) * 10) / 10);
    this->setStrength(ATTACKER_INIT_STRENGTH + round(n(e) * 10) / 10);
    this->setDefense(ATTACKER_INIT_DEFNESE + round(n(e) * 10) / 10);
    this->setSpeed(ATTACKER_INIT_SPEED + round(n(e) * 10) / 10);
}
