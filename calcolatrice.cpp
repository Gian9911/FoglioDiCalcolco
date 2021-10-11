#include "calcolatrice.h"
#include "ui_calcolatrice.h"
#include "listaoperazioni.h"

Calcolatrice::Calcolatrice(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calcolatrice)
{
    ui->setupUi(this);
    mulTrigger = false;
    divTrigger = false;
    addTrigger = false;
    subTrigger = false;
    addMemory = false;
    getMemory = false;
    clrMemory = false;
    degTrigger = true;
    radTrigger = false;
    cosTrigger = false;
    sinTrigger = false;
    result = 0.0;
    memory = 0.0;
    solution = 0.0;
    ui->Display->setText(QString::number(result));
    QPushButton *Buttons[10];
    for(int i = 0; i < 10; i++){
        QString butName = "Button" +
                QString::number(i);
        Buttons[i] = Calcolatrice::findChild<
                QPushButton *>(butName);
        connect(Buttons[i], SIGNAL(released()),
                this,SLOT(NumButton()));
    }
    connect(ui->Add, SIGNAL(released()),
            this,SLOT(MathButton()));
    connect(ui->Divide, SIGNAL(released()),
            this,SLOT(MathButton()));
    connect(ui->Multiply, SIGNAL(released()),
            this,SLOT(MathButton()));
    connect(ui->Subtract, SIGNAL(released()),
            this,SLOT(MathButton()));
    connect(ui->AC, SIGNAL(released()),
            this,SLOT(AC()));
    connect(ui->ChangeSign, SIGNAL(released()),
            this,SLOT(ChangeSign()));
    connect(ui->Equals, SIGNAL(released()),
            this,SLOT(Equals()));
    connect(ui->MemAdd, SIGNAL(released()),
            this,SLOT(Memory()));
    connect(ui->MemClear, SIGNAL(released()),
            this,SLOT(Memory()));
    connect(ui->MemGet, SIGNAL(released()),
            this,SLOT(Memory()));
    connect(ui->Sin, SIGNAL(released()),
            this,SLOT(TrigonButton()));
    connect(ui->Cos, SIGNAL(released()),
            this,SLOT(TrigonButton()));
    connect(ui->Rad, SIGNAL(released()),
            this,SLOT(RadDegButton()));
    connect(ui->Deg, SIGNAL(released()),
            this,SLOT(RadDegButton()));
}

Calcolatrice::~Calcolatrice(){
    delete ui;
}

void Calcolatrice::NumButton(){
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

void Calcolatrice::MathButton(){
    mulTrigger = false;
    addTrigger = false;
    subTrigger = false;
    divTrigger = false;
    QString displayVal = ui->Display->text();
    result = displayVal.toDouble();
    QPushButton * button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        divTrigger = true;
    }else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        addTrigger = true;
    }else if(QString::compare(butVal, "-", Qt::CaseInsensitive) == 0){
        subTrigger = true;
    }else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
        mulTrigger = true;
    }
    ui->Display->setText("");
}

void Calcolatrice::Equals(){
    double solution = 0.0;
    ListaOperazioni l;
    QString displayVal = ui->Display->text();
    double dbDisplayVal = displayVal.toDouble();
    if(addTrigger | mulTrigger | divTrigger | subTrigger){
        if(addTrigger)
            solution = l.sum(result, dbDisplayVal);
        else if(subTrigger)
            solution = l.sub(result, dbDisplayVal);
        else if(mulTrigger)
            solution = l.mul(result, dbDisplayVal);
        else if(divTrigger)
            solution = l.div(result, dbDisplayVal);
    }
    ui->Display->setText(QString::number(solution));
    this->solution = solution;
}

void Calcolatrice::ChangeSign(){
    QString displayVal = ui->Display->text();
    double dbDisplayVal = displayVal.toDouble();
    dbDisplayVal *= -1;
     ui->Display->setText(QString::number(dbDisplayVal));
}

void Calcolatrice::Memory(){
    addMemory = false;
    getMemory = false;
    clrMemory = false;
    QPushButton * button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "M", Qt::CaseInsensitive) == 0){
        getMemory = true;
    }else if(QString::compare(butVal, "M+", Qt::CaseInsensitive) == 0){
        addMemory = true;
    }else if(QString::compare(butVal, "M-", Qt::CaseInsensitive) == 0){
        clrMemory = true;
    }
    if(addMemory | getMemory | clrMemory){
        if(addMemory){
            QString displayVal = ui->Display->text();
             memory = displayVal.toDouble();
              ui->Display->setText(QString::number(0.0));
        }
        else if(getMemory)
            ui->Display->setText(QString::number(memory));
        else if(clrMemory)
            memory = 0.0;
    }
}

void Calcolatrice::AC(){
    result = 0.0;
    ui->Display->setText(QString::number(0.0));
}

void Calcolatrice::TrigonButton(){
    sinTrigger = false;
    cosTrigger = false;
    QPushButton * button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "sin", Qt::CaseInsensitive) == 0){
        sinTrigger = true;
    }else if(QString::compare(butVal, "cos", Qt::CaseInsensitive) == 0)
        cosTrigger = true;
    ListaOperazioni l;
    QString displayVal = ui->Display->text();
    double dbDisplayVal = displayVal.toDouble();
    if(sinTrigger | cosTrigger | radTrigger | degTrigger){
        if(sinTrigger && radTrigger)
            solution = l.radsin(dbDisplayVal);
        else if(sinTrigger && degTrigger)
            solution = l.degsin(dbDisplayVal);
        else if(cosTrigger && radTrigger)
            solution = l.radcos(dbDisplayVal);
        else if(cosTrigger && degTrigger)
            solution = l.degcos(dbDisplayVal);

    ui->Display->setText(QString::number(solution));
    }
}

void Calcolatrice::RadDegButton(){
    radTrigger = false;
    degTrigger = false;
    QPushButton * button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "RAD", Qt::CaseInsensitive) == 0)
        radTrigger = true;
    else if(QString::compare(butVal, "DEG", Qt::CaseInsensitive) == 0)
        degTrigger = true;
     ui->lineEdit->setText(QString(butVal));
}





