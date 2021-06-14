/*
How to use arrays of function pointers
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

int main()
{
    //int (*Arr[2])(int,int) ={add,sub}; => syntax without typedef
    mathFun Arr[2]={add,sub};
    int c = Arr[0](1,2);
    int d = Arr[0](2,1);

    /*
    Traditional Syntax
    int c = (*Arr[0])(1,2);
    int d = (*Arr[0])(2,1);
    */

    cout<<"\nc= "<<c;
    cout<<"\nd= "<<d;

    return 0;
}

/*
Output:
c= 3
d= 3
*/