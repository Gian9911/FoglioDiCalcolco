#include "fogliodicalcolo.h"
#include "ui_fogliodicalcolo.h"

FoglioDiCalcolo::FoglioDiCalcolo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FoglioDiCalcolo)
{
    mulTrigger = false;
    divTrigger = false;
    addTrigger = false;
    subTrigger = false;
    result = 0;
    memory = 0;
    ui->setupUi(this);
    ui->Display->setText(QString::number(result));
    QPushButton *Buttons[10];
    for(int i = 0; i < 10; i++){
        QString butName = "Button" +
                QString::number(i);
        Buttons[i] = FoglioDiCalcolo::findChild<
                QPushButton *>(butName);
        connect(Buttons[i], SIGNAL(released()),
                this,SLOT(NumButton()));
    }
}

FoglioDiCalcolo::~FoglioDiCalcolo()
{
    delete ui;
}


void FoglioDiCalcolo::NumButton(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble() == 0) ||
            (displayVal.toDouble() == 0.0)){
        ui->Display->setText(butVal);
    }else{
        QString newVal = displayVal + butVal;
        double dbNewVal = newVal.toDouble();
        ui->Display->setText(QString::number
                             (dbNewVal, 'g', 16));
    }
}
