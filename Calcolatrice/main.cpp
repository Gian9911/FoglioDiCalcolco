#include "calcolatrice.h"
#include "lista.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lista* list = new Lista();

    Calcolatrice w;
    w.subscribe(list);
    list->show();
    w.show();

    return a.exec();
}
