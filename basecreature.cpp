//
// Created by 温和 on 2018/10/1.
//
#include "basecreature.h"

BaseCreature::BaseCreature() {
    type = Type::attacker;
    name = "base";
    level = 1;
    exp = 0;
    strength = 1;
    defense = 1;
    hp = 1;
    attack_interval = 1.0;
}

void BaseCreature::printCreature_QT() {
    /*
    std::cout<< "Name: " << std::setw(10) << this->name    << "   Type: " << std::setw(3) << this->getType() << std::endl
             << "Lv: "   << std::setw(3)  << this->level   << "  Exp: "   << std::setw(3) << this->exp       << std::endl
             << "H : "   << std::setw(3)  << this->hp      << "  S  : "   << std::setw(3) << this->strength
             << "  D: "  << std::setw(3)  << this->defense << "  T: "     << std::setw(3) << this->attack_interval << std::endl;
    */
    qDebug() << "Name: " << QString::fromStdString(this->name) << "   Type: "
             << QString::fromStdString(this->getType());
    qDebug() << "Lv: " << this->level << "  Exp: " << this->exp;
    qDebug() << "H : " << this->hp << "  S  : " << this->strength
             << "  D: " << this->defense << "  T: " << this->attack_interval;
}

void BaseCreature::printCreature() {
    /*
    std::cout<< "Name: " << std::setw(10) << this->name    << "   Type: " << std::setw(3) << this->getType() << std::endl
             << "Lv: "   << std::setw(3)  << this->level   << "  Exp: "   << std::setw(3) << this->exp       << std::endl
             << "H : "   << std::setw(3)  << this->hp      << "  S  : "   << std::setw(3) << this->strength
             << "  D: "  << std::setw(3)  << this->defense << "  T: "     << std::setw(3) << this->attack_interval << std::endl;
    */
}

void BaseCreature::upgrade() {
    this->level++;
}

int BaseCreature::attack() {
    return 100;
}

void BaseCreature::defend(int attack) {
    this->hp -= (attack - this->defense);
}

void BaseCreature::addExp(int exp) {
    this->exp += exp;
}
