
#ifndef CALCOLATRICE_H
#define CALCOLATRICE_H

#include <QMainWindow>
#include <iostream>
#include"memoriacalc.h"
#include <limits>
#include<list>
#include"Observer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Calcolatrice; }
QT_END_NAMESPACE

class Calcolatrice : public QMainWindow, public Subject
{
    Q_OBJECT

public:
    Calcolatrice(QWidget *parent = nullptr);
    virtual ~Calcolatrice();
    virtual void subscribe(Observer* observer) override;
    virtual void unsubscribe(Observer* observer) override;
    virtual void notify(QString item) override;

private:
    Ui::Calcolatrice *ui;
    double memory;
    double result;
    double solution;
    bool divTrigger;
    bool mulTrigger;
    bool subTrigger;
    bool addTrigger;
    bool addMemory;
    bool getMemory;
    bool clrMemory;
    bool radTrigger;
    bool degTrigger;
    bool sinTrigger;
    bool cosTrigger;
    std::list<Observer*> observer;


private slots:
    void MathButton();
    void NumButton();
    void Equals();
    void ChangeSign();
    void Memory();
    void AC();
    void TrigonButton();
    void RadDegButton();

};
#endif // CALCOLATRICE_H
