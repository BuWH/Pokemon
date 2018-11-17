//
// Created by 温和 on 2018/11/17.
//

#ifndef SERVER_MYSERVER_H
#define SERVER_MYSERVER_H

#include <QtNetwork>
#include <QDebug>
#include <QString>
#include <QThread>
#include "socketThread.h"
#include "widget.h"

class Widget;

class MyServer: public QTcpServer{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

protected:
    virtual void incomingConnection(int socketDescriptor);

private:
    Widget *widget;
};


#endif //SERVER_MYSERVER_H
