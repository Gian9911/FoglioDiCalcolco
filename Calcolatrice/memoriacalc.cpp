#include "memoriacalc.h"
#include <iostream>

MemoriaCalc::MemoriaCalc(){
    stringList = {"start"};
}
MemoriaCalc::~MemoriaCalc(){}


void MemoriaCalc::update( QString item){
    stringList.append(item);
    int i = stringList.size()-1;
    std::cout << stringList.at(i).toLocal8Bit().constData() << std::endl;
}
