

#include<iostream>
using namespace std;


//template<class T>    //template typename and class are equivalent for simple uses
template<typename T>
auto getMax1(T x,T y) ->decltype(x>y?x:y) //For c++11 decltype is used not for c++14
{
    return x>y?x:y;
}

template<typename T>
auto getMax2(T x,T y) //For c++14, auto deduces automatically
{
    return x>y?x:y;
}

int main()
{
    int x= 180,y=20;
    char c1='x',c2='a';
    //Usig Templates - newer compilers can auto deduce types for new compilers
    //cout<<getMax<int>(x,y);
    cout<<getMax1(x,y);
    //cout<<static_cast<char>(getMax<char>(c1,c2));
    cout<<static_cast<char>(getMax2(c1,c2));
}