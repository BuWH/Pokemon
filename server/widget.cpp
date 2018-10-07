#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget) {
    ui->setupUi(this);
    server = new QTcpServer();
    server->listen(QHostAddress::Any, 6666);
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

Widget::~Widget() {
    delete ui;
}

void Widget::acceptConnection() {
    qDebug() << "new Connection!";
    clientConnection = server->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void Widget::readClient() {
    QString str = clientConnection->readAll();
    qDebug() << str;
}
