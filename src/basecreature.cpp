//
// Created by 温和 on 2018/10/1.
//
#include <include/basecreature.h>

#include "/Users/wenhe/code/Pokemon/include/basecreature.h"

BaseCreature::BaseCreature() {
    this->type = Type::attacker;
    this->name = "base";
    creature_id++;
    this->id = creature_id;
    this->level = 1;
    this->exp = 0;
    this->initProperty();
    this->initAbility();
}

void BaseCreature::upgrade() {
    if (this->getLevel() < LEVEL_TOP)
        this->level++;
}

void BaseCreature::addExp(int exp) {
    this->exp += exp;
}

float BaseCreature::randomGrow(float attribute) {
    static std::default_random_engine e(unsigned((time(NULL))));
    static std::normal_distribution<float> n(0, 0.2);
    float temp = round(n(e) * 10) / 10;
    if (temp > 0)
        return attribute + temp;
    else
        return attribute;
}

void BaseCreature::initAbility() {
    //virtual function
}

void BaseCreature::initProperty() {
    static std::default_random_engine e(unsigned(time(NULL)));
    static std::uniform_int_distribution<int> dis(0, 4);
    switch (dis(e)) {
        case Property::gold: {
            this->property = Property::gold;
            break;
        }
        case Property::wood: {
            this->property = Property::wood;
            break;
        }
        case Property::water: {
            this->property = Property::water;
            break;
        }
        case Property::fire: {
            this->property = Property::fire;
            break;
        }
        case Property::solid: {
            this->property = Property::solid;
            break;
        }
    }
}

BaseCreature::~BaseCreature() {
    //qDebug()<<"bye";
}

QString BaseCreature::generateData() const {
    QString data = "";
    data += (QString::number(id) + ',');
    data += (name + ',');
    data += (QString::number(type) + ',');
    data += (QString::number(property) + ',');
    data += (QString::number(level) + ',');
    data += (QString::number(exp) + ',');
    data += (QString::number(strength) + ',');
    data += (QString::number(defense) + ',');
    data += (QString::number(hp) + ',');
    data += (QString::number(speed));
    return QString();
}
