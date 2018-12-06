#include "widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent) {
    server = new TcpServer("", 6666);
    qDebug() << "Started Listening...";
}

Widget::~Widget() {
    delete server;
}
