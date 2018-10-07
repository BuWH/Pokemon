//
// Created by 温和 on 2018/10/1.
//
#pragma once
#ifndef POKEMON_ATTACKER_H
#define POKEMON_ATTACKER_H

#include "basecreature.h"

class AttackerCreatrue : public BaseCreature {
public:

    AttackerCreatrue();

    void upgrade();

protected:

    void initAbility();
};


#endif //POKEMON_ATTACKER_H
