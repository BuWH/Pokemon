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

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();

private:
    Ui::Widget *ui;
    QTcpServer *server;
    QTcpSocket *clientConnection;

    void processRequest(QString str);

    int accountExist(QString str);

    void signup(QString account, QString password);

    void login(QString account, QString password);

private slots:

    void acceptConnection();

    void readClient();

};

#endif // WIDGET_H
