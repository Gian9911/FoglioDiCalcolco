#include "calcolatrice.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calcolatrice w;
    w.show();
    return a.exec();
}
