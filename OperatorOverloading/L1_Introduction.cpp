/*
Using operator overloading in programs, makes them intuitive
Notes:
1. In c++ it is possibe to change the behaviour of operators ( +, - , * ...)
2.But we can change the behaviour for user defined types(class, struct) only
3.There are few operators we cannot overload as below:
    a) ::
    b) ?:
    c) .
    d) .*
    e) sizeof
    f) typeid
*/

#include<iostream>
using namespace std;

class Point{
    int x;
    int y;
public:
    Point(int x=0,int y=0):x{x},y{y} {}  //Constructor

    Point operator+ (const Point& rhs)
    {
        Point p;
        p.x= x + rhs.x;
        p.y= y + rhs.y;
        return p;
    }

    Point operator- (const Point& rhs)
    {
        Point p;
        p.x= x - rhs.x;
        p.y= y - rhs.y;
        return p;
    }

    Point add(const Point& rhs)
    {
        Point p;
        p.x= x + rhs.x;
        p.y= y + rhs.y;
        return p;
    }

    void Print()
    {
        cout<<"\nx: "<<x<<" y:"<<y<<endl;
    }
};

int main()
{
    Point p1(1,2),p2(3,4);
    Point p3= p1+p2;
    Point p4= p3-p1;
    Point p5= p1.add(p2);
    p3.Print();
    p4.Print();
    p5.Print();
    return 0;
}