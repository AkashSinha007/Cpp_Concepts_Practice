
#include<iostream>
using namespace std;

class Base 
{
    int a;
public:
    Base()
    {
        cout<<"\nConstructor called..";
    }
    ~Base()
    {
        cout<<"\nDestructor called..";
    }
};

int main()
{
    //Normal case
    cout<<"\nNormal case: "<<endl;
    Base *obj = new Base();
    delete obj;

    //Placement new Case:
    cout<<"\n\nPlacement new case:"<<endl;
    char* memory = new char[10*sizeof(Base)];

    Base *obj1 = new (&memory[0])Base();
    Base *obj2 = new (&memory[4])Base();
    Base *obj3 = new (&memory[8])Base();

    obj1->~Base();
    obj2->~Base();
    obj3->~Base();

    delete[] memory;
    return 0;
}


/*
Output:
Normal case: 

Constructor called..
Destructor called..

Placement new case:

Constructor called..
Constructor called..
Constructor called..
Destructor called..
Destructor called..
Destructor called..
*/