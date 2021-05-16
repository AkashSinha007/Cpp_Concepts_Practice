/*
Topic: Assignment Operator Overloading in C++

Update: This is for Test t = Base b

Notes:
1.When should we write our own assignment operator in C++ => When we have pointers
2.This comes under binary operator overloading
3.When we need deep copy, assignment operator must be overloaded.
4.We should also create own copy constructor when overloading assignment 
    operator and vise versa.

Function Points:
1.Check self assignment because it is dangerous ( Don't depend in compiler =)
2.Assignment operator must be overloaded by a non-static member function only
*/

#include<iostream>
using namespace std;

class Base
{
    int x;
public:
    Base(int x=0):x{x}{}
    friend class Test;
};

class Test{
    int *x;
public:
    Test(int val=0):x{new int(val)} {}
    void setX(int val) {*x = val;}
    void print(){cout<<"OUTPUT: "<<*x<<endl;}
    ~Test(){delete x;}
    Test& operator=(const Test& rhs)
    {
        if(this!=&rhs)  //Check self asignment
            *x=*rhs.x;
        return *this;  /* return *this is required because (t1=t2)=t3; 
                          implies t1=t2 and after that t1=t3; */
    }

    Test& operator = (const Base& rhs)
    {
        *x=rhs.x;
        return *this;
    }

    Test(const Test& rhs)
    {
        x= new int(*rhs.x);
    }
};

int main()
{
    Test t1(10);
    t1.print();
    Base b(20);
    t1=b;
    t1.print();

    Test t2,t3;
    t1.print();
    t2.print();
    t3.print();
    return 0;
}