#ifndef MEMORIACALC_H
#define MEMORIACALC_H
#include"Observer.h"

class MemoriaCalcData;

class MemoriaCalc : public Observer{
public:
    MemoriaCalc();
    virtual ~MemoriaCalc();
    virtual void update( QString item) override;
    int foo(){
        int c = 2;
        return 2*c;
    }

private:

};

#endif // MEMORIACALC_H
