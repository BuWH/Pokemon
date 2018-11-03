//
// Created by 温和 on 2018/10/27.
//

#pragma once
#ifndef POKEMON_SINGLECREATURE_H
#define POKEMON_SINGLECREATURE_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include "user.h"

namespace Ui {
    class SingleCreature;
}

class SingleCreature : public QWidget {

Q_OBJECT

public:
    explicit SingleCreature(QWidget *parent = 0);

    ~SingleCreature();

    void setCreature(BaseCreature *creature);

    void refresh() const;

private:
    Ui::SingleCreature *ui;
    BaseCreature *creature;
};


#endif //POKEMON_SINGLECREATURE_H
