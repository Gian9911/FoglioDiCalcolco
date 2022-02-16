#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include"../Calcolatrice/listaoperazioni.h"
#include <iostream>

using namespace testing;
//sum

TEST(Sum, MyCase0){
    ListaOperazioni f;
    ASSERT_THROW(f.sum((std::numeric_limits<double>::max() ), 30), std::overflow_error);
}
TEST(Sum, MyCase1){
    ListaOperazioni f;
    ASSERT_THROW(f.sum(-(std::numeric_limits<double>::max() -1), -3), std::underflow_error);
}
TEST(Sum, MyCase2){
    ListaOperazioni f;
    ASSERT_THROW(f.sum(std::numeric_limits<double>::max(), 1), std::overflow_error);
}
TEST(Sum, MyCase3){
    ListaOperazioni f;
    ASSERT_THROW(f.sum(1, std::numeric_limits<double>::max()), std::overflow_error);
}
TEST(Sum, MyCase4){
    ListaOperazioni f;
    ASSERT_THROW(f.sum((-1)*std::numeric_limits<double>::max(), -10), std::underflow_error);
}
TEST(Sum, MyCase5){
    ListaOperazioni f;
    ASSERT_EQ(f.sum(25,77), 102);
}
TEST(Sum, MyCase6){
    ListaOperazioni f;
    ASSERT_EQ(f.sum(-25,77), 52);
}
TEST(Sum, MyCase7){
    ListaOperazioni f;
    ASSERT_EQ(f.sum(25,-77), -52);
}
TEST(Sum, MyCase8){
    ListaOperazioni f;
    ASSERT_EQ(f.sum(-25,-77), -102);
}
    //sub
TEST(Sub, MyCase01){
    ListaOperazioni f;
    ASSERT_THROW(f.sub((std::numeric_limits<double>::max()), -30), std::overflow_error);
}
TEST(Sub, MyCase02){
    ListaOperazioni f;
    ASSERT_THROW(f.sub(-(std::numeric_limits<double>::max() -1), 3), std::underflow_error);
}
TEST(Sub, MyCase03){
    ListaOperazioni f;
    ASSERT_THROW(f.sub(-10, std::numeric_limits<double>::max()), std::underflow_error);
}
TEST(Sub, MyCase04){
    ListaOperazioni f;
    ASSERT_THROW(f.sub(-(std::numeric_limits<double>::max()), 10), std::underflow_error);
}
TEST(Sub, MyCase05){
    ListaOperazioni f;
    ASSERT_THROW(f.sub(10,std::numeric_limits<double>::max()), std::underflow_error);
}
TEST(Sub, MyCase5){
    ListaOperazioni f;
    ASSERT_EQ(f.sub(25,77), -52);
}
TEST(Sub, MyCase6){
    ListaOperazioni f;
    ASSERT_EQ(f.sub(-25,77), -102);
}
TEST(Sub, MyCase7){
    ListaOperazioni f;
    ASSERT_EQ(f.sub(25,-77), 102);
}
TEST(Sub, MyCase8){
    ListaOperazioni f;
    ASSERT_EQ(f.sub(-25,-77), 52);
}
    //mul
TEST(Mul, MyCase001){
    ListaOperazioni f;
    ASSERT_THROW(f.mul((std::numeric_limits<double>::max()-1), 3), std::overflow_error);
}
TEST(Mul, MyCase002){
    ListaOperazioni f;
    ASSERT_THROW(f.mul((std::numeric_limits<double>::max()-1), -3), std::underflow_error);
}
TEST(Mul, MyCase003){
    ListaOperazioni f;
    ASSERT_THROW(f.mul(std::numeric_limits<double>::max(), -1), std::underflow_error);
}
TEST(Mul, MyCase004){
    ListaOperazioni f;
    ASSERT_THROW(f.mul(-2, std::numeric_limits<double>::max()), std::underflow_error);
}
TEST(Mul, MyCase005){
    ListaOperazioni f;
    ASSERT_THROW(f.mul(std::numeric_limits<double>::max(), -12), std::underflow_error);
}
TEST(Mul, MyCas006){
    ListaOperazioni f;
    ASSERT_THROW(f.mul(-2,std::numeric_limits<double>::max()), std::underflow_error);
}

TEST(Mul, MyCase007){
    ListaOperazioni f;
    ASSERT_THROW(f.mul(std::numeric_limits<double>::max(), 2.5), std::overflow_error);
}
TEST(Mul, MyCase008){
    ListaOperazioni f;
    ASSERT_THROW(f.mul(2, std::numeric_limits<double>::max()), std::overflow_error);
}
TEST(Mul, MyCase009){
    ListaOperazioni f;
    ASSERT_EQ(f.mul(55,22), 1210);
}
TEST(Mul, MyCase010){
    ListaOperazioni f;
    ASSERT_EQ(f.mul(-55,22), -1210);
}
TEST(Mul, MyCase011){
    ListaOperazioni f;
    ASSERT_EQ(f.mul(55,-22), -1210);
}
TEST(Mul, MyCase012){
    ListaOperazioni f;
    ASSERT_EQ(f.mul(-55,-22), 1210);
}
    //div
TEST(Div, MyCase0000){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div((std::numeric_limits<double>::max()-1), 0.5));
}
TEST(Div, MyCase0001){
    ListaOperazioni f;
    ASSERT_THROW(f.div((std::numeric_limits<double>::max()-1), -0.5), std::underflow_error);
}

TEST(Div, MyCase0002){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div(0,0));
}

TEST(Div, MyCase003){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div(std::numeric_limits<double>::infinity(),0.5));
}
TEST(Div, MyCase0004){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.div(std::numeric_limits<double>::infinity(),-0.5));
}
TEST(Div, MyCase0005){
    ListaOperazioni f;
    ASSERT_EQ(f.div(33, 11), 3);
}
TEST(Div, MyCase0006){
    ListaOperazioni f;
    ASSERT_EQ(f.div(33, -11), -3);
}

TEST(Div, MyCase0007){
    ListaOperazioni f;
    ASSERT_EQ(f.div(-33, 11), -3);
}
TEST(Div, MyCase0008){
    ListaOperazioni f;
    ASSERT_EQ(f.div(-33, -11), 3);
}
//SIN
TEST(Sin, MyCase0){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.degsin(std::numeric_limits<double>::infinity()));
}
TEST(Sin, MyCase1){
    ListaOperazioni f;
    ASSERT_FLOAT_EQ(f.degsin(30),0.50);
}
//COS
TEST(Cos, MyCase0){
    ListaOperazioni f;
    ASSERT_ANY_THROW(f.degsin(std::numeric_limits<double>::infinity()));
}
TEST(Cos, MyCase1){
    ListaOperazioni f;
    ASSERT_FLOAT_EQ(f.degcos(60), 0.50);
}


