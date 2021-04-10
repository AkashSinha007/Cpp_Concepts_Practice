//Topic: std::unordered_map in c++

/*
Notes:
1.std::unordered_map is an associative container that contains key-value
  pairs with unique keys.
2.Search,insertion, and removal have average constant-time complexity
3.Internally,the elements are organized into buckets.
4.It uses hashing to insert elements into buckets.
5.This allows fast access to individual elements, because after computing
  the hash of the value it refers to the exact bucket the element is 
  placed into.
*/

/*
Why unordered_map
Ans: maintain a collection of unique {key:value} pairs with fast insertion
     and removal.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    std::unordered_map<int,char> umap={{1,'a'},{2,'b'}};

    //Access
    cout<<umap[1]<<endl;
    cout<<umap[2]<<endl;

    //Update
    umap[1]='c';

    //Iterate 
    for(auto& elm:umap)
    {
        cout<<elm.first<<" "<<elm.second<<" "; 
    }
    return 0;
}

/*
Output:
a
b
2 b 1 c
*/