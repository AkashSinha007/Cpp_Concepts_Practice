/*
Topic:
Overloading [] operator in c++ (Array Subscript Operator)

Notes:
1.Array subscript operator can be used to check out of bound cases.
2.Array subscript operator cannot be friend and others to ( ->,(),=)
*/

#include<iostream>
using namespace std;

class Point{
    int arr[2]; // x -> 0 y-> 1
public:
    Point(int x=0,int y=0)
    {
        arr[0]=x;
        arr[1]=y;
    }
    void print()
    {
        cout<<"\n x= "<<arr[0]<<" y= "<<arr[1]<<endl;
    }

    int & operator[](int pos)
    {
        if(pos==0)
            return arr[0];
        else if(pos==1)
            return arr[1];
        else
        {
            cout<<"\n Out of bound case."<<endl;
            exit(0);
        }
        
    }
};

int main()
{
    Point p1(3,4);
    p1.print();
    p1[0] = 7;
    p1[1] = 8;
    p1.print();
    p1[2] =10;
    return 0;
}

/*
Output:
 x= 3 y= 4

 x= 7 y= 8

 Out of bound case.
*/