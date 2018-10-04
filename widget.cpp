#include "widget.h"

Widget::Widget(QWidget *parent)
        : QWidget(parent) {
    //测试程序
    //this->creatureTest();
    setWindowTitle("Pokemon Test");
    this->setFixedSize(TEST_WIDTH, TEST_HEIGHT);
    name.setParent(this);
    name.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 - (LINE_INTERVAL + LINE_HEIGHT) * 2, LINE_WIDTH, LINE_HEIGHT);
    name.setText("名: ");
    type.setParent(this);
    type.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 - (LINE_INTERVAL + LINE_HEIGHT), LINE_WIDTH, LINE_HEIGHT);
    type.setText("类: ");
    level.setParent(this);
    level.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2, LINE_WIDTH, LINE_HEIGHT);
    level.setText("级: ");
    exp.setParent(this);
    exp.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 1, LINE_WIDTH, LINE_HEIGHT);
    exp.setText("Ex: ");
    hp.setParent(this);
    hp.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 2, LINE_WIDTH, LINE_HEIGHT);
    hp.setText("体: ");
    strength.setParent(this);
    strength.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 3, LINE_WIDTH, LINE_HEIGHT);
    strength.setText("力: ");
    defense.setParent(this);
    defense.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 4, LINE_WIDTH, LINE_HEIGHT);
    defense.setText("防: ");
    attack_interval.setParent(this);
    attack_interval.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 5, LINE_WIDTH,
                                LINE_HEIGHT);
    attack_interval.setText("速: ");

    generate.setParent(this);
    generate.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 6,
                         TEST_WIDTH - SIDE_INTERVAL * 2, 45);
    generate.setText("寻找");
    connect(&generate, &QPushButton::clicked, this, &Widget::generateCreature);

    upgrade.setParent(this);
    upgrade.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 7 + LINE_HEIGHT,
                        TEST_WIDTH - SIDE_INTERVAL * 2, 45);
    upgrade.setText("升级");
    upgrade.setDisabled(TRUE);
    connect(&upgrade, &QPushButton::clicked, this, &Widget::upgradeCreature);
}

Widget::~Widget() {

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
    temp.append(QString::fromStdString(attacker->getName()));
    name.setText(temp);
    temp = "类: ";
    temp.append(QString::fromStdString(attacker->getType()));
    type.setText(temp);
    temp = "级: ";
    temp.append(QString::number(attacker->getLevel()));
    level.setText(temp);
    temp = "Ex: ";
    temp.append(QString::number(attacker->getExp()));
    exp.setText(temp);
    temp = "体: ";
    temp.append(QString::number(attacker->getHp()));
    hp.setText(temp);
    temp = "力: ";
    temp.append(QString::number(attacker->getStrength()));
    strength.setText(temp);
    temp = "防: ";
    temp.append(QString::number(attacker->getDefense()));
    defense.setText(temp);
    temp = "速: ";
    temp.append(QString::number(attacker->getAttackInterval()));
    attack_interval.setText(temp);
}

void Widget::upgradeCreature() {
    attacker->upgrade();
    this->refresh();
}

void Widget::generateCreature() {
    delete (attacker);
    attacker = new AttackerCreatrue;
    upgrade.setDisabled(FALSE);
    this->refresh();
}