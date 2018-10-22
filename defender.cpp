//
// Created by 温和 on 2018/10/7.
//
#include "defender.h"

DefenderCreatrue::DefenderCreatrue() {
    this->setName("Defender");
    this->setType(Type::defender);
    this->initAbility();
}

void DefenderCreatrue::upgrade() {
    if (this->getLevel() < LEVEL_TOP) {
        this->setLevel(this->getLevel() + 1);
        this->setHp(this->getHp() + this->randomGrow(DEFENDER_GROW_HP));
        this->setStrength(this->getStrength() + this->randomGrow(DEFENDER_GROW_STRENGTH));
        this->setDefense(this->getDefense() + this->randomGrow(DEFENDER_GROW_DEFNESE));
        this->setSpeed(this->getSpeed() + this->randomGrow(DEFENDER_GROW_SPEED));
    }
}

void DefenderCreatrue::initAbility() {
    static std::default_random_engine e;
    static std::normal_distribution<float> n(0, 0.2);
    this->setHp(DEFENDER_INIT_HP + round(n(e)));
    this->setStrength(DEFENDER_INIT_STRENGTH + round(n(e) * 10) / 10);
    this->setDefense(DEFENDER_INIT_DEFENSE + round(n(e) * 10) / 10);
    this->setSpeed(DEFENDER_INIT_SPEED + round(n(e) * 10) / 10);
}