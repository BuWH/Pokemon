#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget) {
    ui->setupUi(this);
    connect(ui->sendText, &QPushButton::clicked, this, &Widget::sendText);
    char *data = "hello~";
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("127.0.0.1"), 6666);
    if (client->waitForConnected(10000)) {
        qDebug() << "Connection Success!";
        client->write(data);
    }
}

Widget::~Widget() {
    delete ui;
}

void Widget::sendText() {
    client->write(ui->inputText->text().toStdString().c_str());
    ui->inputText->clear();
}