#ifndef WIDGET_H
#define WIDGET_H

#include "const_define.h"
#include <QWidget>
#include <QtNetwork>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include "myserver.h"

class TcpServer;


class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();

private:
    TcpServer *server;
};

#endif // WIDGET_H
