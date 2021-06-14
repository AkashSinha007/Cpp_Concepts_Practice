

#include<iostream>
using namespace std;

void *operator new(size_t size)
{
    cout << "\nWithout value Overloaded new operator size: " << size << endl;
    void *p = malloc(size);
    return p;
}

void *operator new(size_t size,int val)
{
    cout << "\nwith value Overloaded new operator size: " << size << endl;
    void *p = malloc(size);
    if(p!=nullptr)
    {
        *static_cast<int*>(p) = val;
    }
    return p;
}

void operator delete(void *p)
{
    cout << "\nOverloaded Delete Operator" << endl;
    free(p);
}


int main()
{
    unsigned long long u=21;
    int *x = new(u) int; //Calls the overloaded new operator with val
    cout<<"*x is = "<<*x;
    int *y= new int;
    delete x;
    delete y;
}

/*
Output:
with value Overloaded new operator size: 4
*x is = 21
Without value Overloaded new operator size: 4
*/