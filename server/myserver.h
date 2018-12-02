//
// Created by 温和 on 2018/11/17.
//

#ifndef SERVER_MYSERVER_H
#define SERVER_MYSERVER_H

#include <QtNetwork>
#include <QDebug>
#include <QString>
#include <QThread>
#include <QList>
#include "widget.h"
#include "mysocket.h"

class TcpSocket;

class TcpServer : public QTcpServer {
Q_OBJECT
public:
    TcpServer(const std::string &ip, int port, QTcpServer *parent = NULL);

    ~TcpServer();

protected:
    void incomingConnection(qintptr socketDescriptor);

private slots:

    void SocketDisconn();

private:
    QList<TcpSocket *> m_socketList;
};


#endif //SERVER_MYSERVER_H
