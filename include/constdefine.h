//
// Created by 温和 on 2018/10/1.
//
#pragma once
#ifndef POKEMON_CONST_DEFINE_H
#define POKEMON_CONST_DEFINE_H

#define TRUE 1
#define FALSE 0

enum Type {
    attacker,
    tanker,
    defender,
    assassin
};

enum Property {
    gold,
    wood,
    water,
    fire,
    solid
};

const int LEVEL_TOP = 15;
#define CREATURE_TYPES 4;

const int ATTACKER_INIT_HP = 20;
const float ATTACKER_INIT_STRENGTH = 5;
const float ATTACKER_INIT_DEFNESE = 2;
const float ATTACKER_INIT_SPEED = 1.0;

const int ATTACKER_GROW_HP = 2;
const float ATTACKER_GROW_STRENGTH = 1.5;
const float ATTACKER_GROW_DEFNESE = 0.5;
const float ATTACKER_GROW_SPEED = 0.1;

const int TANKER_INIT_HP = 36;
const float TANKER_INIT_STRENGTH = 5;
const float TANKER_INIT_DEFNESE = 2;
const float TANKER_INIT_SPEED = 1.0;

const int TANKER_GROW_HP = 10;
const float TANKER_GROW_STRENGTH = 5;
const float TANKER_GROW_DEFNESE = 2;
const float TANKER_GROW_SPEED = 1.0;

const int DEFENDER_INIT_HP = 10;
const float DEFENDER_INIT_STRENGTH = 5;
const float DEFENDER_INIT_DEFENSE = 2;
const float DEFENDER_INIT_SPEED = 1.0;

const int DEFENDER_GROW_HP = 10;
const float DEFENDER_GROW_STRENGTH = 5;
const float DEFENDER_GROW_DEFNESE = 2;
const float DEFENDER_GROW_SPEED = 1.0;

const int ASSASSIN_INIT_HP = 10;
const float ASSASSIN_INIT_STRENGTH = 5;
const float ASSASSIN_INIT_DEFNESE = 2;
const float ASSASSIN_INIT_SPEED = 1.0;

const int ASSASSIN_GROW_HP = 10;
const float ASSASSIN_GROW_STRENGTH = 5;
const float ASSASSIN_GROW_DEFNESE = 2;
const float ASSASSIN_GROW_SPEED = 1.0;


#endif //POKEMON_CONST_DEFINE_H
