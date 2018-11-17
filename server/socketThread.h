//
// Created by 温和 on 2018/11/17.
//

#ifndef SERVER_SOCKETTHREAD_H
#define SERVER_SOCKETTHREAD_H
#include <QtNetwork>
#include <QDebug>
#include <QString>
#include <QThread>
#include "mysocket.h"

class socketThread: public QThread {
    Q_OBJECT
public:
    socketThread(int socketDescriptor, QObject* parent = 0);
    ~socketThread();
    virtual void run();

signals:
    void revData(QString, QByteArray);
    void sendDat(QByteArray data, int id);
    void disconnectTCP(int);

private slots:
    void sendData(QByteArray data, int id);
    void recvData(QString, QByteArray);
    void disconnectToHost();

private:
    int socketDescriptor;
    MySocket *socket;
};


#endif //SERVER_SOCKETTHREAD_H
