//
// Created by 温和 on 2018/10/16.
//
#pragma once
#ifndef POKEMON_USER_H
#define POKEMON_USER_H

#include "constdefine.h"
#include "attacker.h"
#include "assassin.h"
#include "defender.h"
#include "tanker.h"

#include <QVector>

class User {
public:
    User();

    BaseCreature *getCreature(int i) const;

    int getCreaturesNum() const { return this->creatures.size(); };

    QString getName() const { return this->name; };

public slots:
    void setName(QString name) { this->name = name; };

    void addCreature();

    void addCreature(BaseCreature *&creature);

private:
    QString name;

    //float getWinRate();

    QVector<BaseCreature *> creatures;

    BaseCreature *getRandomCreature();

};

#endif //POKEMON_USER_H
