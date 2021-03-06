#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
        : QWidget(parent),
          ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setFixedWidth(300);
    ui->fight->setDisabled(true);
    ui->upgrade->setDisabled(true);
    login = new Login(ui->tab_3);
    login->show();
    //ui->tab_1->setWindowIconText("Single");
    connect(ui->sendUser, &QPushButton::clicked, this, &Widget::sendUser);
    connect(ui->sendCreature, &QPushButton::clicked, this, &Widget::sendCreature);
    connect(ui->generate, &QPushButton::clicked, this, &Widget::generateCreature);
    connect(ui->upgrade, &QPushButton::clicked, this, &Widget::upgradeCreature);
    connect(ui->clear, &QPushButton::clicked, this, &Widget::clearUser);
    connect(ui->fight, &QPushButton::clicked, this, &Widget::fightTest);
}

Widget::~Widget() {
    for (auto &creature : creatures) {
        ui->creatures_list_layout->removeWidget(creature);
    }
    creatures.clear();
    if(user)
        delete user;
    if(tempCreature)
        delete tempCreature;
    delete ui;
}


void Widget::upgradeCreature() {
    currentCreature->upgrade();
    refresh();
}

void Widget::generateCreature() {
    if (user == nullptr) {
        user = new User(ui->user_name_2->text());
    }
    user->addCreature();
    currentCreature = user->getCreature(user->getCreaturesNum() - 1);
    tempCreature = new SingleCreature(ui->creatures_list);
    ui->creatures_list_layout->addWidget(tempCreature, Qt::AlignTop);
    tempCreature->setGeometry(0, (user->getCreaturesNum() - 1) * 120, 200, 120);
    creatures.append(tempCreature);

    refresh();
}

void Widget::sendUser() {
    if (user) {
        login->send(RequestType::updateuser, user->generateData());
    }
}

void Widget::sendCreature() {
    qDebug() << "send creature";
}

void Widget::clearUser() {
    if(user){
        for (auto &creature : creatures) {
            ui->creatures_list_layout->removeWidget(creature);
        }
        creatures.clear();
        ui->user_name_2->clear();
        delete user;
        user = nullptr;
        refresh();
    }
}

void Widget::fightTest() {
    fight = new Fight;
    fight->init(*user, currentCreature, user->getCreature(0));
    fight->show();
}

void Widget::refresh_tab1() {
    if (user == nullptr) {
        ui->user_name->setText("用户名:");
        ui->creature_num->setText("精灵数量:");
        ui->name->setText("名:");
        ui->id->setText("编:");
        ui->type->setText("类:");
        ui->property->setText("性:");
        ui->level->setText("级:");
        ui->exp->setText("Ex:");
        ui->hp->setText("体:");
        ui->strength->setText("力:");
        ui->defense->setText("防:");
        ui->speed->setText("速:");

        ui->upgrade->setDisabled(true);
        ui->fight->setDisabled(true);
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
        temp = "性: ";
        temp.append(currentCreature->getPropertyString());
        ui->property->setText(temp);
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

        if(user->getCreaturesNum() >= 2)
            ui->fight->setDisabled(false);
        ui->upgrade->setDisabled(false);
    }
}

void Widget::refresh_tab2() {
    ui->creatures_list->setFixedSize(200, creatures.size() * 120);
    for (int i = 0; i < creatures.size(); ++i) {
        creatures[i]->setCreature(user->getCreature(i));
        creatures[i]->refresh();
        if (i % 3 == 0) {
            creatures[i]->setStyleSheet("background-color: rgb(215,215,215)");
        } else if (i % 3 == 1) {
            creatures[i]->setStyleSheet("background-color: rgb(200,200,200)");
        } else if (i % 3 == 2) {
            creatures[i]->setStyleSheet("background-color: rgb(230,230,230)");
        }
        creatures[i]->show();
    }
}

void Widget::refresh() {
    refresh_tab1();
    refresh_tab2();
}