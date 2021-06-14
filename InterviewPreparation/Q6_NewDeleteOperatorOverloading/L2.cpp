
#include <iostream>
using namespace std;

void *operator new(size_t size)
{
    cout << "\nGlobal Overloaded new operator size: " << size << endl;
    void *p = malloc(size);
    return p;
}

void operator delete(void *p)
{
    cout << "\nGlobal Overloaded Delete Operator" << endl;
    free(p);
}


void *operator new [](size_t size)
{
    cout << "\nArray Overloaded new operator size: " << size << endl;
    void *p = malloc(size);
    return p;
}

void operator delete [](void *p)
{
    cout << "\nArray Overloaded Delete Operator" << endl;
    free(p);
}

int main()
{

    int *x = new int[10]; //Global overloading
    delete[] x;
    cout<<"all memory cleared successfully";
}

/*
Output:
Array Overloaded new operator size: 40

Array Overloaded Delete Operator
all memory cleared successfully
*/