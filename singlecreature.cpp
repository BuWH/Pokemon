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