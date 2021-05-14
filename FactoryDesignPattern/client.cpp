/*
Advantages:
1.Less code changes if we change object creation process
2.We create object without exposing creation logic to the client
3.We get the benefits of virtual constructor
*/

#include<iostream>
#include "ToyFactory.cpp"
using namespace std;



int main()
{
    //client code starts
    int type;
    while(1)
    {
        cout<<endl<<"\nEnter type or Zero for exit: "<<endl;
        cin>>type;
        if(!type)
            break;
        Toy *v= ToyFactory::createToy(type);
        if(v)
        {
            v->showProduct();
            delete v;
        }
    }
    cout<<"\nExit.."<<endl;
    //client code ends
    return 0;
}

