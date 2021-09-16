#include "Fogliodicalcolo.h"
#include "ui_Fogliodicalcolo.h"
#include <iostream>
#include <limits>


FoglioDiCalcolo::FoglioDiCalcolo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FoglioDiCalcolo){
    mulTrigger = false;
    divTrigger = false;
    addTrigger = false;
    subTrigger = false;
    addMemory = false;
    getMemory = false;
    clrMemory = false;
    r = 0.0;
    result = 0.0;
    memory = 0.0;
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
    connect(ui->Add, SIGNAL(released()),
            this,SLOT(MathButton()));
    connect(ui->Divide, SIGNAL(released()),
            this,SLOT(MathButton()));
    connect(ui->Multiply, SIGNAL(released()),
            this,SLOT(MathButton()));
    connect(ui->Subtract, SIGNAL(released()),
            this,SLOT(MathButton()));
    connect(ui->Clear, SIGNAL(released()),
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
}

FoglioDiCalcolo::~FoglioDiCalcolo(){
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

void FoglioDiCalcolo::MathButton(){
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

void FoglioDiCalcolo::Equals(){
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dbDisplayVal = displayVal.toDouble();
    if(addTrigger | mulTrigger | divTrigger | subTrigger){
        if(addTrigger)
            solution = sum(result, dbDisplayVal);
        else if(subTrigger)
            solution = sub(result, dbDisplayVal);
        else if(mulTrigger)
            solution = mul(result, dbDisplayVal);
        else if(divTrigger)
            solution = div(result, dbDisplayVal);
    }
    ui->Display->setText(QString::number(solution));
}

void FoglioDiCalcolo::ChangeSign(){
    QString displayVal = ui->Display->text();
    double dbDisplayVal = displayVal.toDouble();
    dbDisplayVal *= -1;
     ui->Display->setText(QString::number(dbDisplayVal));
}

void FoglioDiCalcolo::Memory(){
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

void FoglioDiCalcolo::AC(){
    result = 0.0;
    ui->Display->setText(QString::number(0.0));
}

double FoglioDiCalcolo::sum(double a, double b){
    if (((a == max) & (b > 0)) || ((a > 0) && (b == max))){
        throw std::overflow_error("got overflow");
        //r = 1.e1;
    }else if (((a == min) && (b < 0)) || ((a < 0) && (b == min))){
       throw std::underflow_error("got underflow");
        //r = 1.e1;
    }else
        r = a + b ;
    return r;
}

double FoglioDiCalcolo::sub(double a, double b){
        if (((a == max) && (b < 0)) || ((a > 0) && (b == min))){
             throw std::overflow_error("got overflow");
            //r = 1.e1;
        }else if (((a == min) && (b > 0)) || ((a < 0) && (b == max))){
            throw std::underflow_error("got underflow");
            //r = 1.e1;
        }else
            r = a - b ;
        return r;
 }

 double FoglioDiCalcolo::mul(double a, double b){
        if ((a == max && b >= 1) | (a == min && b <= -1) | (b == max && a >= 1) | (b == min && a <= -1)){
            throw std::overflow_error("got overflow");
            //r = 1.e1;
        }else if ((a == max && b <= -1) | (a == min && b >= 1) | (b == max && a <= -1) | (b == min && a >= 1)){
            throw std::underflow_error("got overflow");
            //r = 1.e1;
        }else
            r = a * b ;
        return r;
 }

 double FoglioDiCalcolo::div(double a, double b){
        if (((a == 0) && (b == 0)) || (b == max) || (b == min)){
            throw std::exception();
            //r = 1.e1;
        }else if ( ((a == min) && (std::abs(b) < 1) && (b < 0)) || ((a == max) && (std::abs(b) < 1) && (b > 0)) ){
            throw std::overflow_error("got overflow");
            //r = 1.e1;
        }else if ( ((a == min) && (std::abs(b) < 1) && (b > 0)) || ((a == max) && (std::abs(b) < 1) && (b < 0)) ){
            throw std::overflow_error("got overflow");
            //r = 1.e1;
        }else  if ((a ==  std::numeric_limits<double>::infinity()) && (b == 0)){
            r = a;
        }else  if (((a ==  std::numeric_limits<double>::infinity()) &&
                  (b ==  std::numeric_limits<double>::infinity())) ||
                  ((a == 0) && (b ==  std::numeric_limits<double>::infinity()))){
            r = 0;
        }else
            r = a / b ;
        return r;
    }


