//
// Created by 温和 on 2018/10/7.
//
#include "tanker.h"

TankerCreatrue::TankerCreatrue() {
    this->setName("Tanker");
    this->setType(Type::tanker);
    this->initAbility();
}

void TankerCreatrue::upgrade() {
    if (this->getLevel() < LEVEL_TOP) {
        this->setLevel(this->getLevel() + 1);
        this->setHp(this->getHp() + this->randomGrow(TANKER_GROW_HP));
        this->setStrength(this->getStrength() + this->randomGrow(TANKER_GROW_STRENGTH));
        this->setDefense(this->getDefense() + this->randomGrow(TANKER_GROW_DEFNESE));
        this->setSpeed(this->getSpeed() + this->randomGrow(TANKER_GROW_SPEED));
    }
}

void TankerCreatrue::initAbility() {
    static std::default_random_engine e;
    static std::normal_distribution<float> n(0, 0.2);
    this->setHp(TANKER_INIT_HP + round(n(e)));
    this->setStrength(TANKER_INIT_STRENGTH + round(n(e) * 10) / 10);
    this->setDefense(TANKER_INIT_DEFNESE + round(n(e) * 10) / 10);
    this->setSpeed(TANKER_INIT_SPEED + round(n(e) * 10) / 10);
}