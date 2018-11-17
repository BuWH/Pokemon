//
// Created by 温和 on 2018/11/17.
//

#include "socketThread.h"

socketThread::socketThread(int socketDescriptor, QObject *parent) {
    this->socketDescriptor = socketDescriptor;
}

socketThread::~socketThread() {
    socket->close();
}

void socketThread::run() {
    socket = new MySocket(socketDescriptor);
    if(!socket->setSocketDescriptor(socketDescriptor)){
        qDebug()<<"socket descriptor error";
    }

    connect(socket, SIGNAL(disconnected), this, SIGNAL(disconnectToHost()));
    connect(socket, SIGNAL(revData(QString, QByteArray)), this, SLOT(recv(QString, QByteArray)));
    connect(this, SIGNAL(sendDat(QByteArray, int)), socket, SLOT(sendMsg(QByteArray, int)));

    exec();
    //QThread::run();
}
void socketThread::sendData(QByteArray data, int id)
{
    if (data == "")
        return ;

    emit sendDat(data, id);
}

void socketThread::recvData(QString peerAddr, QByteArray data) {
    emit revData(peerAddr, data);
}

void socketThread::disconnectToHost() {
    emit disconnectTCP(socketDescriptor);
    socket->disconnectFromHost();
}
