//
// Created by 温和 on 2018/11/17.
//

#include "myserver.h"
MyServer::MyServer(QObject *parent):QTcpServer(parent){
    widget = dynamic_cast<Widget *>(parent);
}

void MyServer::incomingConnection(int socketDescriptor) {
    qDebug() << "New Connect is connect" << socketDescriptor;
    socketThread *thread = new socketThread(socketDescriptor);

    connect(thread, SIGNAL(started()), widget, SLOT(showConnection()));
    connect(thread, SIGNAL(disconnectTCP(int)), widget, SLOT(showDisconnection(int)));
    connect(thread, SIGNAL(revData(QString, QByteArray)), widget, SLOT(revData(QString, QByteArray)));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}