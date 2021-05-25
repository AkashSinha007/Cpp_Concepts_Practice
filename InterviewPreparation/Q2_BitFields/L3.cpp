/*
Taking pointers to bit field members not allowed as they 
may not start at a byte boundary
*/

#include<iostream>
using namespace std;

struct Node 
{
    unsigned int a:5;
    unsigned int b:5;
    unsigned int c;
};

int main()
{
    Node t;

    //This will not work  == compile error
    cout<<&t.a;
    //This will work because c is not bit field member
    cout<<&t.c;

}