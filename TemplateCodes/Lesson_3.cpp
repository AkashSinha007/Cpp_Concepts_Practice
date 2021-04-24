//Overloading Function Template

#include<iostream>
using namespace std;

int const& max(int const& a,int const& b)
{
    cout<<"max(int,int)"<<endl;
    return a<b?b:a;
}

template<typename T>
T const& max(T const& a,T const& b)
{
    cout<<"max(T,T)"<<endl;
    return a<b?b:a;
}

template<typename T>
T const& max(T const& a,T const& b,T const& c)
{
    cout<<"max(T,T,T)"<<endl;
    return max(max(a,b),c);
}

int main()
{
    cout<<"\nCalling max(10.0,20.0)....\n";
    ::max(10.0,20.0);

    cout<<"\nCalling max('a','b')....\n";
    ::max('a','b');

    cout<<"\nCalling max(10,20)....\n";
    ::max(10,20);

    cout<<"\nCalling max<>(10,20)....\n";
    ::max<>(10,20);

    cout<<"\nCalling max<double>(10,20)....\n";
    ::max<double>(10,20);

    cout<<"\nCalling max(10,20,30)....\n";
    ::max(10,20,30);
    return 0;
}

/*
Ouput:
Calling max(10.0,20.0)....
max(T,T)

Calling max('a','b')....
max(T,T)

Calling max(10,20)....
max(int,int)

Calling max<>(10,20)....
max(T,T)

Calling max<double>(10,20)....
max(T,T)

Calling max(10,20,30)....
max(T,T,T)
max(int,int)
max(int,int)
*/