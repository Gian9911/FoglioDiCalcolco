#ifndef LISTAOPERAZIONI_H
#define LISTAOPERAZIONI_H

#include <iostream>
#include <limits>
#include <math.h>
#define PI 3.14159265

class ListaOperazioni
{
public:
    double sum(double a, double b){
        double r = 0.0;
        if((a + b) <= std::numeric_limits<double>::max())
            r = a + b;
        else
             throw std::overflow_error("got overflow");
        if((a + b) > r)
            r = a + b;
        else
            throw std::underflow_error("got underflow");
        return r;
    }

    double sub(double a, double b){
        double r = 0.0;
        if((a - b) > std::numeric_limits<double>::max())
            r = a - b;
        else
            throw std::overflow_error("got overflow");
        if((a - b) >= std::numeric_limits<double>::min())
            r = a - b;
        else
            throw std::underflow_error("got underflow");
        return r;
    }

    double mul(double a, double b){
        double r = 0.0;
        if((a * b) <= std::numeric_limits<double>::max())
            r = a * b;
        else
           throw std::overflow_error("got overflow");
        if((a * b) > r)
            r = a * b;
        else
           throw std::underflow_error("got underflow");;
        return r;
    }

    double div(double a, double b){
        double r = 0.0;
        if (((a == 0) && (b == 0)) || (b == std::numeric_limits<double>::max()) || (b == std::numeric_limits<double>::min()) ||
                ((a ==  std::numeric_limits<double>::infinity()) && (b == 0)) || ((a ==  std::numeric_limits<double>::infinity()) &&
                (b ==  std::numeric_limits<double>::infinity())) || ((a == 0) && (b ==  std::numeric_limits<double>::infinity())))
           throw std::exception();
        if((a / b) <= std::numeric_limits<double>::max())
               r = a / b;
        else
           throw std::overflow_error("got overflow");
        if((a / b) > r)
           r = a / b ;
        else
           throw std::underflow_error("got underflow");
        return r;
    }

    double degsin(double a){
        double r = 0.0;
        if ( a != std::numeric_limits<double>::infinity())
            r = sin ( a * PI / 180 );
        else
              throw std::exception();
        return r ;
    }
    double degcos(double a){
        double r = 0.0;
        if ( a != std::numeric_limits<double>::infinity())
            r = cos ( a * PI / 180 );
        else
              throw std::exception();
        return r;
    }
    double radsin(double a){
        double r = 0.0;
        if ( a != std::numeric_limits<double>::infinity())
            r = sin ( a );
        else
              throw std::exception();
        return r;
    }
    double radcos(double a){
        double r = 0.0;
        if ( a != std::numeric_limits<double>::infinity())
            r = cos ( a );
        else
              throw std::exception();
        return r;
    }
};

#endif // LISTAOPERAZIONI_H
