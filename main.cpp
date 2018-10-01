#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    AttackerCreatrue A;
    A.printCreature_QT();
    w.show();

    return a.exec();
}
