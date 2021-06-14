/*
How to pass a function pointer as an argument
*/

#include<iostream>
using namespace std;

int add(int a,int b)
{
    return a+b;
}

int fun1(int (*someFun)(int,int))
{
    int c = someFun(1,2);
    cout<<"\nsum = "<<c;
    return c;
}

int main()
{
    int c = fun1(add);
    return 0;
}

/*
Output:
sum = 3
*/