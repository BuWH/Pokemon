//
// Created by 温和 on 2018/10/7.
//
#pragma once
#ifndef POKEMON_ASSASSIN_H
#define POKEMON_ASSASSIN_H

#include "basecreature.h"

class AssassinCreatrue : public BaseCreature {
public:
    AssassinCreatrue();

    void upgrade();
protected:
    virtual void initAbility();
};

#endif //POKEMON_ASSASSIN_H
