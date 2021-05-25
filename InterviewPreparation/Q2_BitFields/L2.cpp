/*
Force alignment is possible using unnamed bit fields of size 0;
*/

#include<iostream>
using namespace std;

struct Node1
{
    unsigned int a: 6;
    unsigned int b: 9;
};

//With forced alignment
struct Node2
{
    unsigned int a: 6;
    unsigned int :0;
    unsigned int b: 9;
};

int main()
{
    cout<<"\nsize(Node1) = "<<sizeof(Node1);
    cout<<"\nsize(Node2) = "<<sizeof(Node2);
}

/*
Output:
size(Node1) = 4
size(Node2) = 8
*/