/*
Bit Fields in C++

It is used to reduce the size of "class/struct" if we can
*/

#include<iostream>
using namespace std;

struct Date
{ 
    unsigned int d;    //Note: date max 31  (1-31) ==> 2^5 = 32 (5 bits enough)
    unsigned int m;    //Note: Month max 12 (1-12) ==> 2^4 = 16 (4 bits enough)
    unsigned int y;    //Year can be anything
};

struct DateBitField
{ 
    unsigned int d:5; 
    unsigned int m:4; 
    unsigned int y; 
};

int main()
{
    Date d;
    d.d=8;
    d.m=8;
    d.y= 1989;
    cout<<d.d<<"/"<<d.m<<"/"<<d.y<<endl;
    cout<<"\nsizeof Date = "<<sizeof(Date)<<endl;
    cout<<"\nsize of DateBitField= "<<sizeof(DateBitField)<<endl;
    return 0;
}

/*
Output:
8/8/1989

sizeof Date = 12

size of DateBitField= 8
*/