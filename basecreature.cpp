//
// Created by 温和 on 2018/10/1.
//
#include "basecreature.h"

BaseCreature::BaseCreature() {
    type = Type::attacker;
    name = "base";
    level = 1;
    exp = 0;
    this->initAbility();
}

void BaseCreature::printCreature_QT() {
    qDebug() << "Name: " << this->name << "   Type: "
             << this->getType();
    qDebug() << "Lv: " << this->level << "  Exp: " << this->exp;
    qDebug() << "H : " << this->hp << "  S  : " << this->strength
             << "  D: " << this->defense << "  T: " << this->speed;
}

void BaseCreature::printCreature() {
    /*
    std::cout<< "Name: " << std::setw(10) << this->name    << "   Type: " << std::setw(3) << this->getType() << std::endl
             << "Lv: "   << std::setw(3)  << this->level   << "  Exp: "   << std::setw(3) << this->exp       << std::endl
             << "H : "   << std::setw(3)  << this->hp      << "  S  : "   << std::setw(3) << this->strength
             << "  D: "  << std::setw(3)  << this->defense << "  T: "     << std::setw(3) << this->speed << std::endl;
    */
}

void BaseCreature::upgrade() {
    if (this->getLevel() < LEVEL_TOP)
        this->level++;
}

int BaseCreature::attack() {
    return 100;
}

void BaseCreature::defend(float attack) {
    this->hp -= (attack - this->defense);
}

void BaseCreature::addExp(int exp) {
    this->exp += exp;
}

float BaseCreature::randomGrow(float attribute) {
    static std::default_random_engine e;
    static std::normal_distribution<float> n(0, 0.2);
    float temp = round(n(e) * 10) / 10;
    if (temp > 0)
        return temp + attribute;
    else
        return attribute;
}

void BaseCreature::initAbility() {
}