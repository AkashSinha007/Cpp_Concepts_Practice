/*
Topic: Overload TypeCast in C++

Notes:
1.Thee is no need to typecast implicit data types (Compiler knows how to do that)
2.User defined data types needs this overloading
*/

#include<iostream>
using namespace std;

double dollarToRupeeExchangeRate()
{
    return 71.5;
}

class Rupee
{
    double rupee;
public:
    Rupee(double r=0):rupee(r) {}
    void print() {cout<<rupee<<endl;}
};

class Dollar
{
    double dollar;
public:
    Dollar(double d=0):dollar{d} {}
    void print(){cout<<dollar<<endl;}

    operator Rupee()   //Notice here no returntype when compared with previous overloadings
    {
        return Rupee(dollar*dollarToRupeeExchangeRate());
    }
};

int main()
{
    Dollar d(10);
    Rupee r;
    r= d;
    d.print();
    r.print();
    return 0;
}