#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include"../Calcolatrice/listaoperazioni.h"

using namespace testing;

//32767
//sum

TEST(Sum, MyCase0){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sum((std::numeric_limits<double>::max() ), 30));
}

TEST(Sum, MyCase1){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sum(-(std::numeric_limits<double>::max() -1), -3));
}
TEST(Sum, MyCase2){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sum(std::numeric_limits<double>::max(), 1));
}
TEST(Sum, MyCase3){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sum(1, std::numeric_limits<double>::max()));
}
TEST(Sum, MyCase4){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sum(std::numeric_limits<double>::min(), -1));
}
TEST(Sum, MyCase5){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sum(-1,std::numeric_limits<double>::min()));
}
    //sub
TEST(Sub, MyCase01){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sub((std::numeric_limits<double>::max()-1), -3));
}
TEST(Sub, MyCase02){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sub(-(std::numeric_limits<double>::max() -1), 3));
}
TEST(Sub, MyCase03){
    ListaOperazioni f;
     ASSERT_ANY_THROW(f.sub(std::numeric_limits<double>::max(), -1));
}
TEST(Sub, MyCase04){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sub(-1, std::numeric_limits<double>::max()));
}
TEST(Sub, MyCase05){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sub(std::numeric_limits<double>::min(), 1));
}
TEST(Sub, MyCase06){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.sub(1,std::numeric_limits<double>::min()));
}
    //mul
TEST(Mul, MyCase001){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.mul((std::numeric_limits<double>::max()-1), 3));
}
TEST(Mul, MyCase002){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.mul((std::numeric_limits<double>::max()-1), -3));
}
TEST(Mul, MyCase003){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.mul(std::numeric_limits<double>::max(), -1));
}
TEST(Mul, MyCase004){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.mul(-2, std::numeric_limits<double>::max()));
}
TEST(Mul, MyCase005){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.mul(std::numeric_limits<double>::min(), -12));
}
TEST(Mul, MyCas006){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.mul(-2,std::numeric_limits<double>::min()));
}

TEST(Mul, MyCase007){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.mul(std::numeric_limits<double>::max(), 2.5));
}
TEST(Mul, MyCase008){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.mul(2, std::numeric_limits<double>::max()));
}

TEST(Mul, MyCase009){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.mul(std::numeric_limits<double>::min(), 12));
}
TEST(Mul, MyCas010){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.mul(2,std::numeric_limits<double>::min()));
}
    //div
TEST(Div, MyCase0000){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div((std::numeric_limits<double>::max()-1), 0.5));
}
TEST(Div, MyCase0001){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div((std::numeric_limits<double>::max()-1), -0.5));
}
TEST(Div, MyCase0002){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div(0,0));
}
TEST(Div, MyCase0003){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div(std::numeric_limits<double>::min(),-0.5));
}
TEST(Div, MyCase0004){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div(std::numeric_limits<double>::max(),0.5));
}
TEST(Div, MyCase0005){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div(std::numeric_limits<double>::max(),-0.5));
}
TEST(Div, MyCase0006){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div(std::numeric_limits<double>::min(),0.5));
}
TEST(Div, MyCase0007){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div(3, std::numeric_limits<double>::min()));
}
TEST(Div, MyCase0008){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div(3, std::numeric_limits<double>::min()));
}
TEST(Sin, MyCase0){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.degsin(std::numeric_limits<double>::infinity()));
}
TEST(Cos, MyCase0){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.degsin(std::numeric_limits<double>::infinity()));
}


