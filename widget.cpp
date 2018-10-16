#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
        : QWidget(parent),
          ui(new Ui::Widget) {
    ui->setupUi(this);
    //测试程序
    //this->creatureTest();
    connect(ui->generate, &QPushButton::clicked, this, &Widget::generateCreature);
    connect(ui->upgrade, &QPushButton::clicked, this, &Widget::upgradeCreature);
}

Widget::~Widget() {
    delete ui;
}

void Widget::creatureTest() {
    for (int i = 0; i <= 9; ++i) {
        BaseCreature *temp_creature = new BaseCreature;
        temp_creature->printCreature_QT();
        delete temp_creature;
    }
}

void Widget::refresh() {

    QString temp = "名: ";
    temp.append(attacker->getName());
    ui->name->setText(temp);
    temp = "类: ";
    temp.append(attacker->getType());
    ui->type->setText(temp);
    temp = "级: ";
    temp.append(QString::number(attacker->getLevel()));
    ui->level->setText(temp);
    temp = "Ex: ";
    temp.append(QString::number(attacker->getExp()));
    ui->exp->setText(temp);
    temp = "体: ";
    temp.append(QString::number(attacker->getHp()));
    ui->hp->setText(temp);
    temp = "力: ";
    temp.append(QString::number(attacker->getStrength()));
    ui->strength->setText(temp);
    temp = "防: ";
    temp.append(QString::number(attacker->getDefense()));
    ui->defense->setText(temp);
    temp = "速: ";
    temp.append(QString::number(attacker->getSpeed()));
    ui->speed->setText(temp);
}

void Widget::upgradeCreature() {
    attacker->upgrade();
    this->refresh();
}

void Widget::generateCreature() {
    delete (attacker);
    attacker = new AttackerCreatrue;
    ui->upgrade->setDisabled(FALSE);
    this->refresh();
}