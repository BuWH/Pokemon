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
#include <QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "const_define.h"

class TcpServer;

class TcpSocket : public QTcpSocket
{
Q_OBJECT
public:
    TcpSocket(int socketdesc, QTcpSocket *parent = NULL);

    ~TcpSocket();

private slots:
    void ReadAndParseData();

    void SocketErr(QAbstractSocket::SocketError socketError);

private:
    QString m_recvDataStr;

    QSqlDatabase account_db, creature_db;

    void processRequest(QString str);

    void signup(QString account, QString password);

    void login(QString account, QString password);

    void logout(QString account);

    void updateUserData(int id, QString account, int winfights, int totalfights, int num);

    void updateCreature(QString data);

    void sendUserData(QString account);

    QString getCreaetureData(QString master);

};

#endif //SERVER_MYSOCKET_H
