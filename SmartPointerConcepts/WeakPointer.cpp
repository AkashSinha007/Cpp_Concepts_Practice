/*
NOTES:
0. If we say unique_ptr is for unique ownership and shared_ptr is for 
    shared ownership then weak_ptr is for non-ownership smart pointer.
1.It actually reference to an object which is managed by shared_ptr;
2.A weak_ptr is created as a copy of shared_ptr
3.We have to convert weak_ptr to shared_ptr in order to use the managed object.
4.It is used to remove cyclic dependency between shared_ptr
*/

#include<iostream>
#include<memory>
using namespace std;

int main()
{
    auto sharedPtr = std::make_shared<int>(100);
    weak_ptr<int> weakPtr(sharedPtr);

    cout<<"weakPtr.use_count(): "<<weakPtr.use_count()<<endl;
    cout<<"sharedPtr.use_count(): "<<sharedPtr.use_count()<<endl;
    cout<<"weakPtr.use_count(): "<<weakPtr.use_count()<<endl;

    if(shared_ptr<int> sharedPtr1 = weakPtr.lock())
    {
        cout<<"sharedPtr: "<<*sharedPtr<<endl;
        std::cout<<"sharedPtr1.use_count(): "<<sharedPtr1.use_count()<<endl;
    }
    else
    {
        cout<<"Don't get the resource"<<endl;
    }

    weakPtr.reset();
    if(shared_ptr<int> sharedPtr1= weakPtr.lock())
    {
        cout<<"sharedPtr: "<<*sharedPtr<<endl;
        std::cout<<"sharedPtr1.use_count(): "<<sharedPtr1.use_count()<<endl;

    }
    else
    {
        cout<<"Don't get the resource"<<endl;
    }
    
}