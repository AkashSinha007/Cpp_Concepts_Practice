//Topic: unordered_multiset in c++

/*
Notes:
1. std::unordered_multiset is an associative container that contains set
   of possibly non-unique objects.
2.Search,insertion, and removal have average constant-time complexity
3.Internally, the elements are organized into buckets
4.It uses hashing to insert elements into buckets
5.This allows fast access to individual elements, because after computing
  the hash of the value it refers to the exact bucket the element is placed
  into.
*/

/*
Why Unordered_Multiset
Ans: maintain a collection of non-unique items with fast insertion and 
     removal.
*/

#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    std::unordered_multiset<int> umset= {4,1,2,3,9,4,3,2,9,8,10};
    auto search=umset.find(2);
    if(search!=umset.end())
    {
            cout<<"\nFound "<<(*search)<<"\n";
    }
    else
    {
        cout<<"\nNot Found.";
    }

    for(auto& elem:umset)
    {
        cout<<elem<<" ";
    }
    
    cout<<endl;
    cout<<"\nNumber of 4= "<<umset.count(4);
}


/*
Output:
Found 2
10 8 9 9 3 3 2 2 1 4 4

Number of 4= 2
*/