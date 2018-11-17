//
// Created by 温和 on 2018/11/17.
//

#ifndef SERVER_MYSOCKET_H
#define SERVER_MYSOCKET_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QtNetwork>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QDebug>
#include "const_define.h"

class MySocket : public QTcpSocket
{
Q_OBJECT
public:
    explicit MySocket(int socketDescriptor, QObject *parent = 0);

    void processRequest(QString str);

    int accountExist(QString str);

    void signup(QString account, QString password);

    void login(QString account, QString password);

signals:
    void revData(QString, QByteArray);

public slots:
    void recvData();
    void sendMsg(QByteArray msg, int id);

private:

    int socketDescriptor;
};


#endif //SERVER_MYSOCKET_H
