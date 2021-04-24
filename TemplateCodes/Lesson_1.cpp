/*
POINTS:
1. There are two places where we can apply templates.
   a. function templates
   b. class templates
2. Templates are the way to write generic programs.
3. The main point is we pass data type as parameter to function or class.

*/

#include<iostream>

using namespace std;
int getMaxInt(int x,int y)
{
    return x>y ? x : y;
}

char getMaxChar(char x,char y)
{
    return x>y ? x : y;
}

//template<class T>    //template typename and class are equivalent for simple uses
template<typename T>
T getMax(T x,T y)
{
    return x>y?x:y;
}

int main()
{
    int x= 180,y=20;
    cout<<getMaxInt(x,y);

    char c1='a' ,c2= 'x';
    cout<<static_cast<char>(getMaxChar(c1,c2));

    //Usig Templates - newer compilers can auto deduce types for new compilers
    //cout<<getMax<int>(x,y);
    cout<<getMax<int>(x,y);
    //cout<<static_cast<char>(getMax<char>(c1,c2));
    cout<<static_cast<char>(getMax<char>(c1,c2));
}