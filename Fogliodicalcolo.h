#ifndef FOGLIODICALCOLO_H
#define FOGLIODICALCOLO_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FoglioDiCalcolo; }
QT_END_NAMESPACE


class FoglioDiCalcolo : public QMainWindow
{
    Q_OBJECT

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


public:
    FoglioDiCalcolo(QWidget *parent = nullptr);
    ~FoglioDiCalcolo();
    double sum(double a, double b);
    double mul(double a, double b);
    double div(double a, double b);
    double sub(double a, double b);

    double max = std::numeric_limits<double>::max();
    double min = std::numeric_limits<double>::min();
    double r = 0.0;

};
#endif // FOGLIODICALCOLO_H
