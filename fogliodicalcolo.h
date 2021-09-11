#ifndef FOGLIODICALCOLO_H
#define FOGLIODICALCOLO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FoglioDiCalcolo; }
QT_END_NAMESPACE

class FoglioDiCalcolo : public QMainWindow
{
    Q_OBJECT

public:
    FoglioDiCalcolo(QWidget *parent = nullptr);
    ~FoglioDiCalcolo();

private:
    Ui::FoglioDiCalcolo *ui;
    double memory;
    double result;
    bool divTrigger;
    bool mulTrigger;
    bool subTrigger;
    bool addTrigger;
    bool addMemory;
    bool getMemory;
    bool clrMemory;

private slots:
    void MathButton();
    void NumButton();
    void Equals();
    void ChangeSign();
    void Memory();
    void AC();
};
#endif // FOGLIODICALCOLO_H
