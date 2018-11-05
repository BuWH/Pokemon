//
// Created by 温和 on 2018/10/7.
//

#include "/Users/wenhe/code/Pokemon/include/assassin.h"

AssassinCreatrue::AssassinCreatrue() {
    this->setName("Assassin");
    this->setType(Type::assassin);
    this->initAbility();
}

void AssassinCreatrue::upgrade() {
    if (this->getLevel() < LEVEL_TOP) {
        this->setLevel(this->getLevel() + 1);
        this->setHp(static_cast<int>(this->getHp() + this->randomGrow(ASSASSIN_GROW_HP)));
        this->setStrength(this->getStrength() + this->randomGrow(ASSASSIN_GROW_STRENGTH));
        this->setDefense(this->getDefense() + this->randomGrow(ASSASSIN_GROW_DEFNESE));
        this->setSpeed(this->getSpeed() + this->randomGrow(ASSASSIN_GROW_SPEED));
    }
}

void AssassinCreatrue::initAbility() {
    static std::default_random_engine e;
    static std::normal_distribution<float> n(0, 0.2);
    this->setHp(static_cast<int>(ASSASSIN_INIT_HP + round(n(e) * 10) / 10));
    this->setStrength(ASSASSIN_INIT_STRENGTH + round(n(e) * 10) / 10);
    this->setDefense(ASSASSIN_INIT_DEFNESE + round(n(e) * 10) / 10);
    this->setSpeed(ASSASSIN_INIT_SPEED + round(n(e) * 10) / 10);
}
