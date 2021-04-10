//Topic: std::multiset<T>

/*
SYNTAX: std::multiset<T> objectName;
*/

/*
Note:
1.std::multiset is an Associative Container that contains a sorted 
  set of duplicate objects of type key
2.It is usually implemented using Red-Black Tree
3.Insertion, removal,Search have logarithmic complexity
4.If we want to store user defined data type in multiset then we 
  have to provide compare function so that multiset can store them
  in sorted order.
5.We can pass the order of sorting while constructing set object 
*/

/*
Bottom Line:
multiset is similar to set except it can have multiple elements
with same value.
*/

#include<iostream>
#include<set>
#include<string>
#include<functional>
using namespace std;

class Person
{
public:
    float age;
    string name;
    //Note: Greater and less than operators are called during insertions
    bool operator <(const Person& rhs)const  //Ascending Logic
    {
        return age<rhs.age;
    }
    bool operator >(const Person& rhs)const  //Descending Logic
    {
        return age>rhs.age;
    }
};


int main()
{
    std::multiset<int> multiSet1={5,2,4,3,2,5}; //Printing will be: 223455
    //std::multiset<int,std::less<int>> multiSet={5,2,4,3,2,5}; //syntax is optional
    //multiSet1.insert(20);
    cout<<"\n==Printing ascending multiSet1==\n";
    for(const auto& e:multiSet1)
    {
        cout<<e<<endl;
    }

    std::multiset<int,std::greater<int>> multiSet2={5,2,4,3,2,5}; //Printing will be: 554322
    cout<<"\n==Printing descending multiSet2==\n";
    for(const auto& e:multiSet2)
    {
        cout<<e<<endl;
    }

    cout<<"\n===Display Person based on descending order by age===\n";
    set<Person,std::greater<>> myPerson2={{30,"Rupesh"},{25,"Hitesh"},{22,"John"}};
    for(const auto& e: myPerson2)
    {
        cout<<e.age<<" "<<e.name<<endl;
    }

    return 0;
}