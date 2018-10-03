//
// Created by 温和 on 2018/10/1.
//
#include "creature.h"

AttackerCreatrue::AttackerCreatrue() {
    this->setName("Attacker");
    this->setType(Type::attacker);
    this->initAbility();
}