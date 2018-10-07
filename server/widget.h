#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QDebug>
#include <QDateTime>

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


private slots:

    void acceptConnection();

    void readClient();

};

#endif // WIDGET_H
