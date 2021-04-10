//Topic: std::array

/*  Syntax: std::array<T,N> array;
*/

/*
Note:
1.std::array is a container that encapsulates fixed size arrays
2.arraysize is needed at compile time
3.Assign by value is actually by value
4.Access Elements:
    a.at()  //this gives out of bound exception
    b.[]    //this doesn't give out of bound exception
    c.front()
    d.back()
    e.data()  //gives acces to underlying array
*/

#include<iostream>
#include<array>
using namespace std;

int main()
{
    //Declare 
    std::array<int,5> myarray;

    //Initialization
    std::array<int,5> myarray={1,2,3,4,5}; //Initializer list
    std::array<int,5> myarray2{1,2,3,4,5}; //Uniform initialization

    //Assign using initializer list
    std::array<int,5> myarray;
    myarray={1,2,3,4,5};
}