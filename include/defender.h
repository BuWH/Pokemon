//
// Created by 温和 on 2018/10/7.
//
#pragma once
#ifndef POKEMON_DEFENDER_H
#define POKEMON_DEFENDER_H

#include "basecreature.h"

class DefenderCreatrue : public BaseCreature {
public:
    DefenderCreatrue();

    virtual void upgrade();

protected:
    virtual void initAbility();
};

#endif //POKEMON_DEFENDER_H
