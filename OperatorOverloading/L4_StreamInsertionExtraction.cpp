/*
Topic: << & >> operator overloading in C++
>> is stream extraction operator ( direction of arrow shows from istream class to some object)
<< is stream insertion operator

Note:
1.When we need overload << & >> ?
    cout << (user defined type) or cin>> (user defined type)
2.It can't be class member function, we have to make it friend function of our class
*/

#include<iostream>
using namespace std;

class Test
{
    int x; // private member
public:
    Test(int x=0):x{x}{}
    friend istream& operator>>(istream& input , Test& obj);
    friend ostream& operator<<(ostream& output , Test& obj);
};

istream& operator>>(istream& input , Test& obj)
{
    input>>obj.x;
    return input;
}

ostream& operator<<(ostream& output , Test& obj)
{
    output<<obj.x<<endl;
    return output;
}

int main()
{
    Test t;
    cin>>t;
    cout<<t;
    return 0;
}