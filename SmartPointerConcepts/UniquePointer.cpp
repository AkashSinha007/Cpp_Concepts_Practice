/*
0. unique_ptr is a class template
1. unique_ptr is one of the smart pointer provided by c++11 to revent memory leaks
2.unique_ptr wraps a raw pointer in it, and deallocates the raw pointer,
    when unique_ptr object goes out of scope.
3.similar to actual pointers we can use -> and * on the object of unique_ptr,
    because it is overloaded in unique_ptr class
4.When exception comes then also it will de-allocate the memory hence no memory leak.
5. Not only object, we can create array of object of unique_ptr.

Operations:
release, reset,swap, get, get_deleter
*/

#include<iostream>
#include<memory>
using namespace std;

class Foo
{
    int x;
    public:
        explicit Foo(int x):x{x}
        {}
        int getX()
        {
            return x;
        }
};

int main()
{
    unique_ptr<Foo> p1(new Foo(10));
    unique_ptr<Foo> p2(new Foo(100));

    unique_ptr<Foo> p3 = make_unique<Foo>(20); 
    /*should use make_unique - there are reasons - exception safe*/

    //p1= p3; //FAIL: This  will fail because you cannot copy ownership
    unique_ptr<Foo> p4 = std::move(p1); //PASS: Because moving ownership is allowed

    Foo* p = p4.get();

    Foo* p5 = p4.release();

    p3.reset(p5);
    cout<<p3->getX();

    return 0;
}