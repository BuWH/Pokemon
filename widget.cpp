#include "widget.h"

Widget::Widget(QWidget *parent)
        : QWidget(parent) {
    setWindowTitle("Pokemon Test");
    this->setFixedSize(300, 600);
}

Widget::~Widget() {

}
