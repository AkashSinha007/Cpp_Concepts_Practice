/*
Structural Padding Part 2 
*/

#include<iostream>
using namespace std;

struct A
{
    int x;
    double d;
};

struct B
{
    int y;
    A a;
};

int main()
{
    cout<<sizeof(B)<<endl;
    return 0;
}