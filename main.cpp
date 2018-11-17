#include "widget.h"
#include <QApplication>

unsigned int BaseCreature::creature_id = 0;
unsigned int User::user_id = 0;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
