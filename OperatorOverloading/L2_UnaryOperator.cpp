/*
Notes:
1.Operator overloading works with {class/struct}
2.Unary perator overloading needs only one operand

*/

#include<iostream>
using namespace std;

class Point{
    int x;
    int y;
public:
    Point(int x=0,int y=0):x{x},y{y} {}  //Constructor

    void Print()
    {
        cout<<"\nx: "<<x<<" y:"<<y<<endl;
    }

    Point operator - ()
    {
        return Point(-x,-y);
    }
};

int main()
{
    Point p1(1,2),p2;
    p1.Print();
    p2.Print();
    Point p3= -p1;  //Unary operator is getting called
    p3.Print();
    return 0;
}