//Topic: std::unordered_set

/*
Note:
1.Unordered set is a associative container that contains set of
  unique objects.
2.Search,iteration, and removal have average constant-time complexity.
3.Internally, the elements are organized into buckets
4.It uses hashing to insert elements into buckets.
5.This allows fast access to individual elements, since once a hash is
  computed, it refers to the exact bucket the element is placed into.
*/

/*
Why Un-ordered Set ?
Ans: Maintain a collection of unique items with fast insertion and removal.
*/

#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    std::unordered_set<int> uset={4,1,2,3,4,2,3};
    auto search =uset.find(2);
    if(search!=uset.end())
    {
        std::cout<<"\nFound "<<(*search)<<"\n";
    }
    else
    {
        std::cout<<"\nNot Found\n";
    }

    for(auto& elem:uset)
    {
        cout<<elem<<" ";
    }
    
    return 0;
}

/*
Output:
Found 2
3 2 1 4
*/