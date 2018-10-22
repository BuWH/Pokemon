#pragma once
#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtNetwork>
#include <QLineEdit>
#include <QPushButton>
#include <string>
#include "const_define.h"

namespace Ui {
    class Login;
}

class Login : public QWidget {
Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);

    ~Login();

private:
    Ui::Login *ui;
    QTcpSocket *client;

    void loginRequest();

    void signupRequest();

    void send(RequestType type, QString account, QString password);

    bool connectedToServer();

private slots:

    void acceptData();
};

#endif // LOGIN_H
