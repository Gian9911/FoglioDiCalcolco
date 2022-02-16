#include "lista.h"
#include "ui_lista.h"

Lista::Lista(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lista)
{
    ui->setupUi(this);
    stringList = {"start"};
}

Lista::~Lista()
{
    delete ui;
}

void Lista::update( QString item){
    stringList.append(item);
     ui->Storico->addItem(item);
    int i = stringList.size()-1;
    std::cout << stringList.at(i).toLocal8Bit().constData() << std::endl;

}
