//Topic: Emplace in STL

/*
Note:
1.All the containers supports insert and emplace opeartion to store data.
2.Emplace is used to construct object in-place and avoids unnecessary
  copy of objects.
3.Insert and Emplace is equal for primitive data types but when we deal 
  with heavy objects we should use emplace if we can for efficiency.
*/

#include<iostream>
#include<set>
using namespace std;

class A
{
public:
    int x;
    A(int x=0):x{x}
    {
        cout<<"\nConstruct";
    }
    A(const A& rhs)
    {
        x=rhs.x;
        cout<<"\nCopy";
    }
};

bool operator< (const A& lhs,const A& rhs)
{
    return lhs.x<rhs.x;
}

int main()
{
    set<A> Set;
    cout<<"\n====using insert====\n";
    Set.insert(A(10));
    cout<<"\n====using emplace====\n";
    Set.emplace(20);

    cout<<"\n====Printing values====\n";
    for(auto& elem: Set)
    {
        cout<<elem.x<<endl;
    }
    return 0;
}

/*
Output:
====using insert====

Construct
Copy
====using emplace====

Construct
====Printing values====
10
20
*/