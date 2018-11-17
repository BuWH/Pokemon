//
// Created by 温和 on 2018/11/17.
//

#include "mysocket.h"

MySocket::MySocket(int socketDescriptor, QObject *parent)
        : QTcpSocket(parent), socketDescriptor(socketDescriptor)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(recvData()));
}

void MySocket::sendMsg(QByteArray msg, int id)
{
    if (id == socketDescriptor)
    {
        write(msg);
        waitForBytesWritten();
    }
}

void MySocket::recvData()
{
    QByteArray data;
    QString peerAddr;

    data = readAll();
    qDebug()<<"get:" <<data;

    QString temp = peerAddress().toString();
    peerAddr = temp.remove(0, 7);

    emit revData(peerAddr, data);
}

void MySocket::processRequest(QString str) {
    QString temp = str.section(',', 0, 0);
    if (temp == "login") {
        QString account = str.section(',', 1, 1);
        QString password = str.section(',', 2, 2);
        this->login(account, password);
    }
    if (temp == "signup") {
        QString account = str.section(',', 1, 1);
        QString password = str.section(',', 2, 2);
        this->signup(account, password);
    }
    if (temp == "logout") {
        qDebug() << "logout";
    }
}

void MySocket::signup(QString account, QString password) {
    QFile database("accounts.txt");
    if (!database.open(QFile::WriteOnly | QFile::Text | QFile::Append)) {
        qDebug() << "database open error";
        return;
    }
    if (this->accountExist(account) == FALSE) {
        QTextStream data(&database);
        data << account << "," << password << "\n";
        qDebug() << "signup: " << account << " " << password;
        database.close();
        return;
    } else if (this->accountExist(account) == ERROR) {
        write("server error");
        waitForBytesWritten();
    } else {
        qDebug() << "account exists";
        write("signup denied");
        waitForBytesWritten();
    }
}

void MySocket::login(QString account, QString password) {
    QFile database("accounts.txt");
    if (!database.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "send: database open error";
        write("server error");
        waitForBytesWritten();
        return;
    }
    QTextStream data(&database);
    QString temp, temp1, temp2;
    while (!data.atEnd()) {
        temp = data.readLine();
        temp1 = temp.trimmed().section(',', 0, 0);
        temp2 = temp.trimmed().section(',', 1, 1);
        if (temp1 == account && temp2 == password) {
            qDebug() << "send: login permitted";
            write("login permitted");
            waitForBytesWritten();
            database.close();
            return;
        }
    }
    qDebug() << "send: login denied";
    write("login denied");
    waitForBytesWritten();
    database.close();
}

int MySocket::accountExist(QString str) {
    QFile database("accounts.txt");
    if (!database.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "database open error";
        return ERROR;
    }
    QTextStream data(&database);
    QString temp;
    while (!data.atEnd()) {
        temp = data.readLine();
        temp = temp.trimmed().section(',', 0, 0);
        if (temp == str)
            return TRUE;
    }
    database.close();
    return FALSE;
}