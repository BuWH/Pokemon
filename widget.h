#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "user.h"
#include "singlecreature.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget {

Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();

protected:
    void refresh();

    void refresh_tab1();

    void refresh_tab2();

    void upgradeCreature();
    void generateCreature();

    void clearUser();

private:
    Ui::Widget *ui;
    SingleCreature *test;
    BaseCreature *currentCreature;
    User *user;

    QVector<SingleCreature *> creatures;
};

#endif // WIDGET_H
