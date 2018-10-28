#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
        : QWidget(parent),
          ui(new Ui::Widget) {
    ui->setupUi(this);
    //test = new SingleCreature(this);
    //test->setGeometry(0, 0, 200, 200);
    //test->raise();
    //test->show();
    //ui->creatures_Layout->setAlignment(Qt::AlignTop);
    connect(ui->generate, &QPushButton::clicked, this, &Widget::generateCreature);
    connect(ui->upgrade, &QPushButton::clicked, this, &Widget::upgradeCreature);
    connect(ui->clear, &QPushButton::clicked, this, &Widget::clearUser);
}

Widget::~Widget() {
    delete ui;
    delete user;
    delete currentCreature;
}


void Widget::upgradeCreature() {
    currentCreature->upgrade();
    refresh();
}

void Widget::generateCreature() {
    if (user == nullptr) {
        user = new User;
    }
    user->addCreature();
    currentCreature = user->getCreature(user->getCreaturesNum() - 1);
    test = new SingleCreature();
    ui->creatures_Layout->addWidget(test, Qt::AlignTop);
    creatures.append(test);
    /*
    ui->creatures_Layout->addWidget(test);
    test->setCreature(currentCreature);
    test->refresh();
    test->show();
    */
    refresh();
}

void Widget::clearUser() {
    delete user;
    creatures.clear();
    user = nullptr;
    refresh();
}

void Widget::refresh_tab1() {
    if (user == nullptr) {
        ui->user_name->setText("用户名:");
        ui->creature_num->setText("精灵数量:");
        ui->name->setText("名:");
        ui->id->setText("编:");
        ui->type->setText("类:");
        ui->level->setText("级:");
        ui->exp->setText("Ex:");
        ui->hp->setText("体:");
        ui->strength->setText("力:");
        ui->defense->setText("防:");
        ui->speed->setText("速:");
    } else {
        QString temp;
        temp = "用户名: ";
        temp.append(user->getName());
        ui->user_name->setText(temp);
        temp = "精灵数量: ";
        temp.append(QString::number(user->getCreaturesNum()));
        ui->creature_num->setText(temp);
        temp = "名: ";
        temp.append(currentCreature->getName());
        ui->name->setText(temp);
        temp = "编: ";
        temp.append(QString::number(currentCreature->getID()));
        ui->id->setText(temp);
        temp = "类: ";
        temp.append(currentCreature->getType());
        ui->type->setText(temp);
        temp = "级: ";
        temp.append(QString::number(currentCreature->getLevel()));
        ui->level->setText(temp);
        temp = "Ex: ";
        temp.append(QString::number(currentCreature->getExp()));
        ui->exp->setText(temp);
        temp = "体: ";
        temp.append(QString::number(currentCreature->getHp()));
        ui->hp->setText(temp);
        temp = "力: ";
        temp.append(QString::number(currentCreature->getStrength()));
        ui->strength->setText(temp);
        temp = "防: ";
        temp.append(QString::number(currentCreature->getDefense()));
        ui->defense->setText(temp);
        temp = "速: ";
        temp.append(QString::number(currentCreature->getSpeed()));
        ui->speed->setText(temp);
    }
}

void Widget::refresh_tab2() {
    for (int i = 0; i < creatures.size(); ++i) {
        creatures[i]->setCreature(user->getCreature(i));
        creatures[i]->refresh();
        creatures[i]->show();
    }
}

void Widget::refresh() {
    refresh_tab1();
    refresh_tab2();
}