#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget) {
    ui->setupUi(this);
    char *data = "hello~";
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("127.0.0.1"), 6666);
    if (client->waitForConnected(10000)) {
        qDebug() << "Connection Success!";
    }
    client->write(data);
}

Widget::~Widget() {
    delete ui;
}
