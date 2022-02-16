#ifndef LISTA_H
#define LISTA_H

#include "Observer.h"
#include <QMainWindow>

namespace Ui {
class Lista;
}

class Lista : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    explicit Lista(QWidget *parent = nullptr);
    virtual ~Lista();
    virtual void update( QString item) override;
    int foo(){
        int c = 2;
        return 2*c;
    }

private:
    Ui::Lista *ui;
    QStringList stringList;
};

#endif // LISTA_H
