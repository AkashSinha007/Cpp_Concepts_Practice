//Topic:std::unordered_multimap in C++

/*
Notes:
1.Unordered multimap is an unordered associative container that supports
  equivalent keys(an unordered_multimap may contain multiple copies of 
  each key value) and that associates values of another type with the keys.

2.Search,insertion, and removal have average constant-time complexity.
3.Internally, the elements are organized into buckets.
4.It uses hashing to insert elements into buckets.
5.This allows fast access to individual elements,since once a hash 
  is computed, it refers to the exact bucket the element is placed into.
*/

/*
Why Unordered_multimap
1.Maintains a collection of duplicate {key:value} pairs with 
  fast insertion and removal.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    std::unordered_multimap<int,char> umm={{5,'d'}};
    umm.insert({1,'a'});
    umm.insert(std::pair<int,char>(2,'b'));
    umm.insert(std::make_pair(3,'c'));
    umm.insert(std::make_pair(3,'c')); //Note: key '3' repeated
    umm.insert(std::make_pair(3,'d'));//Note: key '3' repeated

    for(auto& elem:umm)
    {
        cout<<elem.first<<" "<<elem.second<<endl;
    }

    return 0;
}

/*
Output:
5 d
1 a
2 b
3 d
3 c
3 c
*/