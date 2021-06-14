/*
Function hiding in C++
*/

#include <iostream>
using namespace std;

class Base
{
public:
    void fun()
    {
        cout << "void" << endl;
    }

    int fun(int i, int j)
    {
        cout << "Base" << endl;
    }
};

class Derived : public Base
{
public:
    using Base::fun;  //Notice here no paranthesis

    int fun(char c)
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    Derived d;
    d.fun(1, 1);    //If not "using"  replace with d.Base::fun(1,1)
    //d.fun('a');
    //d.fun();
    return 0;
}