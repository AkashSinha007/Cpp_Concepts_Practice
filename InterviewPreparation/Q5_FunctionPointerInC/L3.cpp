/*
How to return a function pointer
*/

#include<iostream>
using namespace std;

int add(int a,int b)
{
    return a+b;
}

int sub(int a,int b)
{
    return a-b;
}

typedef int(*mathFun)(int,int);

mathFun fun(int type)
{
    if(type==1)
        return add;
    if(type==2)
        return sub;
}

/*
Alternate syntax without typedef
int (*fun(int type))(int,int)
{
    if(type==1)
        return add;
    if(type==2)
        return sub;
}
*/

void main()
{
    int (*someFun)(int,int);
    someFun = fun(1);
    int c= someFun(1,2);
    cout<<"c= "<<c;
}