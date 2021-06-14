/*
Overloading operator new and operator delete in C++

Why: Overloading new and delete operator gives developer more flexibility 
for heap allocation

Points:
1.There are two different types of overloading:
    a.Local overloading (class/struct)
    b.Global Overloading
2.Syntax for overloading operator new
    void *operator new(size_t size);
3.Syntax for overloading operator delete
    void operator delete(void *);
4.Both new and delete operator are static member functions
  So they don't have access to this pointer(we don't have to
  write static keyword it is automatically static)
5.Don't forget to overload for array version of both(new/delete).
6.We can have multiple overloaded new/delete operator functions.
*/

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

class Test
{
    int x;

public:
    Test(int x = 0) : x{x} {}
    void *operator new(size_t size)
    {
        cout << "\nLocal Overloaded new operator size: " << size << endl;
        void *p = malloc(size);
        return p;
    }

    void operator delete(void *p)
    {
        cout << "\nLocal Overloaded Delete Operator" << endl;
        free(p);
    }
};

int main()
{
    Test *t = new Test(); //Local Overloading
    delete t;

    int *x = new int; //Global overloading
    delete x;
    cout<<"all memory cleared successfully";
}

/*
Output:
Local Overloaded new operator size: 4

Local Overloaded Delete Operator

Global Overloaded new operator size: 4
all memory cleared successfully
*/