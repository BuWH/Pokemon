//
// Created by 温和 on 2018/11/17.
//

#include "myserver.h"

TcpServer::TcpServer(const std::string &ip, int port, QTcpServer *parent) : QTcpServer(parent) {
    bool bsucc;
    if (ip.empty()) {
        bsucc = this->listen(QHostAddress::Any, port);
    } else {
        bsucc = this->listen(QHostAddress(ip.c_str()), port);
    }
}

TcpServer::~TcpServer() {
    this->close();
    QList<TcpSocket *>::iterator it = m_socketList.begin();
    for (; it != m_socketList.end();) {
        TcpSocket *sock = *it;
        m_socketList.erase(it++);
        delete sock;
        sock = NULL;
    }
    m_socketList.clear();
}

void TcpServer::incomingConnection(qintptr socketDescriptor) {
    TcpSocket *socket = new TcpSocket(socketDescriptor);
    qDebug() << "new connection: " << socket->peerAddress().toString() << socket->peerPort();

    connect(socket, SIGNAL(readyRead()), socket, SLOT(ReadAndParseData())); // 会移进线程里
    connect(socket, SIGNAL(disconnected()), this, SLOT(SocketDisconn()));

    QThread *thread = new QThread(socket); // 以socket为父类，当socket释放删除后也会删除线程，或者将线程的quit信号关联槽deleteLater()也可以达到效果
    connect(socket, SIGNAL(disconnected()), thread, SLOT(quit()));
    socket->moveToThread(thread);
    thread->start();
    emit newConnection();   //文档要求继承本函数需要发射此信号，此处没有与此信号连接的槽
}

void TcpServer::SocketDisconn() {
    TcpSocket *socket = (TcpSocket *) sender();
    QList<TcpSocket *>::iterator it = std::find(m_socketList.begin(), m_socketList.end(), socket);
    if (it != m_socketList.end()) {
        m_socketList.erase(it);
        delete socket;
        socket = NULL;
    }
    qDebug() << "connection closed";
    qDebug() << "current connection: " << m_socketList.size();
}