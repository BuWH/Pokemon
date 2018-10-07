//
// Created by 温和 on 2018/10/7.
//
#pragma once
#ifndef POKEMON_TANKER_H
#define POKEMON_TANKER_H

#include "basecreature.h"

class TankerCreatrue : public BaseCreature {
public:

    TankerCreatrue();

    void upgrade();

protected:

    void initAbility();
};

#endif //POKEMON_TANKER_H
