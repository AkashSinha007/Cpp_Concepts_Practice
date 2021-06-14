//Function overriding example

#include<iostream>
using namespace std;

class Base
{
public:
    void print()
    {
        cout<<"Base Class "<<endl;
    }
};

class Derived:public Base
{
public:
    void print()
    {
        cout<<"Derived Class "<<endl;
    }
};

int main()
{
    Base b;
    Derived d;
    b.print();
    d.print();
}

/*
Output:
Base Class 
Derived Class
*/