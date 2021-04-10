//Topic: std::vector

/*  
    Syntax: std::vector<T> vec;
*/

/*
Notes:
1.std::vector is a sequence container and also known as Dynamic array
   or ArrayList.
2.Its size can grow and shrink dynamically, and no need to provide size 
  at compile time.

Element Access:
at(), [] , front(),back(),  data()

Modifiers:
insert(), emplace(),push_back(),emplace_back(),pop_back(),resize(),
swap(),erase(),clear()
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //Declarations
    std::vector<int> arr1;
    std::vector<int> arr2(5,20);  //Create vector with size=5 and each element as 20
    std::vector<int> arr3={1,2,3,4,5};  //Initializer List
    std::vector<int> arr4={1,2,3,4,5}; //Uniform Initialization

    //Accessing Elements
    arr2[3]=10;
    arr2.at(2)=10;
}