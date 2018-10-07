#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget) {
    ui->setupUi(this);
    server = new QTcpServer();
    server->listen(QHostAddress::Any, 6666);
    qDebug() << "Started Listening...";
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

Widget::~Widget() {
    delete ui;
}

void Widget::acceptConnection() {
    clientConnection = server->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void Widget::readClient() {
    QString str = clientConnection->readAll();
    QDateTime local = QDateTime::currentDateTime();
    QString localTime = local.toString("yyyy-MM-dd:hh:mm:ss");
    qDebug() << localTime << "get message: " << str;
}
