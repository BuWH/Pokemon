//
// Created by 温和 on 2018/10/27.
//

#include "singlecreature.h"
#include "ui_singlecreature.h"

SingleCreature::SingleCreature(QWidget *parent)
        : QWidget(parent),
          ui(new Ui::SingleCreature) {
    ui->setupUi(this);
}

SingleCreature::~SingleCreature() {
    delete ui;
}

void SingleCreature::setCreature(BaseCreature *creature) {
    this->creature = creature;
    refresh();
}

void SingleCreature::refresh() const {
    if (creature != nullptr) {
        ui->name->setText(creature->getName());
        ui->type->setText(creature->getType());
        ui->level->setText(QString::number(creature->getLevel()));
        ui->exp->setText(QString::number(creature->getExp()));
        ui->hp->setText(QString::number(creature->getHp()));
        ui->strength->setText(QString::number(creature->getStrength()));
        ui->defense->setText(QString::number(creature->getDefense()));
        ui->speed->setText(QString::number(creature->getSpeed()));
    } else {
        ui->name->setText("Error Occurred!");
        ui->type->clear();
        ui->exp->clear();
        ui->level->clear();
        ui->strength->clear();
        ui->hp->clear();
        ui->defense->clear();
        ui->speed->clear();
    }
}