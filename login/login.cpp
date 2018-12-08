#include <QMessageBox>
#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Login) {
    ui->setupUi(this);
    client = new QTcpSocket(this);
    this->connectedToServer();
    connect(ui->login, &QPushButton::clicked, this, &Login::loginRequest);
    connect(ui->signup, &QPushButton::clicked, this, &Login::signupRequest);
    connect(ui->logout, &QPushButton::clicked, this, &Login::logoutRequest);
    //connect(ui->passwordInput, &QLineEdit::editingFinished, this, &Login::login );
}

Login::~Login() {
    delete ui;
    client->close();
}

bool Login::connectedToServer() {
    if (client->waitForConnected(5000))
        return TRUE;
    else {
        client->close();
        client->connectToHost(QHostAddress("127.0.0.1"), 6666);
        if (client->waitForConnected(3000)) {
            qDebug() << "connected to server";
            connect(client, SIGNAL(readyRead()), this, SLOT(acceptData()));
            return TRUE;
        } else {
            qDebug() << "can't access server";
            return FALSE;
        }
    }
}

void Login::loginRequest() {
    if (ui->accountInput->text() != "") {
        if (ui->passwordInput->text() != "") {
            //ui->accountInput->setReadOnly(1);
            //ui->passwordInput->setReadOnly(1);
            if (this->connectedToServer())
                this->send(RequestType::login, ui->accountInput->text(), ui->passwordInput->text());
        }
    }
}

void Login::signupRequest() {
    if (ui->accountInput->text() != "") {
        if (ui->passwordInput->text() != "") {
            //ui->accountInput->setReadOnly(1);
            //ui->passwordInput->setReadOnly(1);
            if (this->connectedToServer())
                this->send(RequestType::signup, ui->accountInput->text(), ui->passwordInput->text());
        }
    }
}

void Login::logoutRequest() {
    if (ui->accountInput->text() != "") {
        if (this->connectedToServer()) {
            this->send(RequestType::logout, ui->accountInput->text());
        }
    }
}

void Login::send(RequestType type, QString account, QString password) {
    if (type == RequestType::login) {
        QByteArray data(("login," + account + "," + password).toUtf8());
        qDebug() << data;
        client->write(data);
        if (!client->waitForBytesWritten(1000)) {
            qDebug() << "server error";
        }
        qDebug() << "ask for login permission : " << account + "," + password;
        return;
    }
    if (type == RequestType::signup) {
        QByteArray data(("signup," + account + "," + password).toUtf8());
        client->write(data);
        if (!client->waitForBytesWritten(1000)) {
            qDebug() << "server error";
            return;
        }
        qDebug() << "ask for signup permission: " << account + "," + password;
        return;
    }
}

void Login::send(RequestType type, QString str) {
    if (type == RequestType::updateuser) {
        QByteArray data(("updateuser," + str).toUtf8());
        qDebug() << data;
        client->write(data);
        if (!client->waitForBytesWritten(1000)) {
            qDebug() << "server error";
        }
        qDebug() << "update user data:" + str.section(',', 0, 1);
        return;
    }
    if (type == RequestType::logout) {
        QByteArray data(("logout," + str).toUtf8());
        client->write(data);
        if (!client->waitForBytesWritten(1000)) {
            qDebug() << "server error";
            return;
        }
        qDebug() << "ask for logout permission: " << str;
        return;
    }
}

void Login::acceptData() {
    QString readData = client->readAll();
    QString str = readData.section(',', 0, 0);
    if (str == "login") {
        if (readData.section(',', 1, 1) == "success") {
            qDebug() << "login success";
        } else {
            QMessageBox::information(this, "info", readData.section(',', 1, 1));
        }
    }
    if (str == "logout") {
        if (readData.section(',', 1, 1) == "success") {
            qDebug() << "logout success";
        } else {
            QMessageBox::information(this, "info", readData.section(',', 1, 1));
        }
    }
    if (str == "update creature") {
        if (readData.section(',', 1, 1) == "success") {
            qDebug() << "upload success";
        } else {
            QMessageBox::information(this, "info", readData.section(',', 1, 1));
        }
    }
    if (str == "download") {
        qDebug() << readData;
    }
}