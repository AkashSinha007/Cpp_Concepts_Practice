/*
Assigning an out-of-range value to a bit field member is 
implementation defined -- compiler vendor will provide in reference
*/

#include<iostream>
using namespace std;

struct Node
{
    unsigned int a: 2;
    unsigned int b: 2;
    unsigned int c: 2;
    
};

int main()
{
    Node n;
    n.a=5;   //Exceeds the max limit of 4 because 2 bits can occupy 4
    cout<<n.a<<endl;
    return 0;
}