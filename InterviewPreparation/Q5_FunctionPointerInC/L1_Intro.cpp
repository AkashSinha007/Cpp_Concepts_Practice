/*
Q:What is Function pointer and how to create them ?
A: Function pointer store address of another function
*/

#include<iostream>
using namespace std;

int add(int a,int b)
{
    return a+b;
}

int main()
{
    int (*fun)(int,int) = add;  //New type to assign address
    int (*fun)(int,int) = &add;  //Old type to assign address
    //int (*fun)(int,int,int) = add;  //Compile error must match both signature and no of args
  
    int c= fun(1,2);  //New way to call
    //int c= (*fun)(1,2); //Old/traditional way to call

    cout<<"\nc = "<<c;
}