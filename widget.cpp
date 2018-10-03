#include "widget.h"

Widget::Widget(QWidget *parent)
        : QWidget(parent) {
    //测试程序
    //this->creatureTest();
    setWindowTitle("Pokemon Test");
    this->setFixedSize(TEST_WIDTH, TEST_HEIGHT);
    name.setParent(this);
    name.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2, LINE_WIDTH, LINE_HEIGHT);
    name.setText("名: ");
    type.setParent(this);
    type.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT), LINE_WIDTH, LINE_HEIGHT);
    type.setText("类: ");
    level.setParent(this);
    level.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 2, LINE_WIDTH, LINE_HEIGHT);
    level.setText("级: ");
    exp.setParent(this);
    exp.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 3, LINE_WIDTH, LINE_HEIGHT);
    exp.setText("Ex: ");
    hp.setParent(this);
    hp.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 4, LINE_WIDTH, LINE_HEIGHT);
    hp.setText("血: ");
    strength.setParent(this);
    strength.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 5, LINE_WIDTH, LINE_HEIGHT);
    strength.setText("力: ");
    defense.setParent(this);
    defense.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 6, LINE_WIDTH, LINE_HEIGHT);
    defense.setText("防: ");
    attack_interval.setParent(this);
    attack_interval.setGeometry(SIDE_INTERVAL, TEST_HEIGHT / 2 + (LINE_INTERVAL + LINE_HEIGHT) * 7, LINE_WIDTH,
                                LINE_HEIGHT);
    attack_interval.setText("速: ");

    generate.setParent(this);
    generate.setGeometry(SIDE_INTERVAL, TEST_HEIGHT - SIDE_INTERVAL * 2, TEST_WIDTH - SIDE_INTERVAL * 2, 50);
    generate.setText("寻找");
    connect(&generate, &QPushButton::clicked, this, &Widget::generateCreature);
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

void Widget::generateCreature() {
    QString temp = "名: ";
    temp.append(QString::number(1));
    name.setText(temp);
}