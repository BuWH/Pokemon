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
    explicit User(QString name);
    ~User();

    static unsigned int user_id;

    BaseCreature *getCreature(int i) const;
    int getCreaturesNum() const { return this->creatures.size(); };
    QString getName() const { return this->name; };
    float getWinRate() const { return float(winFights / totalFights); };
    unsigned int getId() const { return this->id; };

    QString generateData() const;

public slots:
    void addCreature();
    void addCreature(BaseCreature *&creature);

private:
    QString name;
    unsigned int id;
    QVector<BaseCreature *> creatures;
    int winFights;
    int totalFights;

    BaseCreature *getRandomCreature();
};

#endif //POKEMON_USER_H
