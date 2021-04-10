//Topic: std::set<T>

/*
Syntax: std::set<T> objectName;
*/

/*
Note:
1.std::set is an Associative container that contains a sorted set of 
  unique objects of type Key.
  Note: there are 4 associative containers: set,multiset, map,multimap
2.It is usually implemented using Red-Black Tree.
3.Insertion,Removal,Search have logarithmic complexity
4.If we want to store user defined data type in set then we will
  have to provide compare function so that set can store them 
  in sorted order.
5.We can pass the order of sorting while constructing set object.
*/
/*
Bottom Line:
It store unique elements and thay are stored in sorted order(A/D).

Default order is ascending. To explictly use ascending or descending, 
use below syntax:
set<int,std::less> = Ascending order
set<int,std::greater> = Descending order
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
    set<int> myset={1,2,3,4,5,1,4,3,2,5};
    for(const auto& e:myset)
    {
        cout<<"\n"<<e;
    }

    //NOTE: default behaviour is ascending if nothing specified.
    cout<<"\n===Display based on Ascending order by age===\n";
    set<Person> myPerson1={{30,"Rupesh"},{25,"Hitesh"},{22,"John"}};
    for(const auto& e: myPerson1)
    {
        cout<<e.age<<" "<<e.name<<endl;
    }

    cout<<"\n===Display based on descending order by age===\n";
    set<Person,std::greater<>> myPerson2={{30,"Rupesh"},{25,"Hitesh"},{22,"John"}};
    for(const auto& e: myPerson2)
    {
        cout<<e.age<<" "<<e.name<<endl;
    }


    return 0;
}


/*
Output:
1
2
3
4
5
===Display based on Ascending order by age===
22 John
25 Hitesh
30 Rupesh

===Display based on descending order by age===
30 Rupesh
25 Hitesh
22 John
*/