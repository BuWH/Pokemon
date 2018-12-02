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

    void processRequest(QString str);

    int accountExist(QString str);

    void signup(QString account, QString password);

    void login(QString account, QString password);
};

#endif //SERVER_MYSOCKET_H
