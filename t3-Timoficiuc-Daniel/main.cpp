#include <QApplication>
#include <QPushButton>
#include "Gui.h"
#include "iostream"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Gui g;
    g.show();
    return a.exec();
}
