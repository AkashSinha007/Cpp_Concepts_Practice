//Topic : Multimap in C++

/*
SYNTAX: multimap<T1,T2> obj;  //Where T1 is key type and T2 is value type
*/

/*
NOTES:
1.Multimap is an associative container that contains a sorted list of 
  key-value pairs, while permitting multiple entries with the same key.
2.It stores key-value pair in sorted order on the basis of key(ascending/descending).
  Syntax: std::multimap<char,int,std::greater<>> Multimap;
3.Data structure used in multimap is not defined by standard, but red-black
  tree is assumed by most of the people.
4.Lookup: count, find,contains,equal_range,lower_bound, upper_bound
5.We don't have at() and [] functions to get element like we had in std::map
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    std::multimap<char,int> Multimap;
    Multimap.insert(pair<char,int>('a',1));
    Multimap.insert(make_pair('a',2));
    Multimap.insert(make_pair('a',3));
    Multimap.insert(make_pair('b',4));
    Multimap.insert(make_pair('b',5));

    //Iterate over multimap
    cout<<"\nIterating over Multimap\n";
    for(auto& elm:Multimap)
    {
        cout<<elm.first<<" "<<elm.second<<endl;
    }

    //Get all the pairs of given key
    cout<<"\nGetting All pairs of given key\n";
    //pair<multimap<char,int>::iterator,multimap<char,int>::iterator> range=Multimap.equal_range('a');
    auto range=Multimap.equal_range('a');  //Use auto for simpler syntax
    for (auto it=range.first; it!=range.second;++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<"\n====Getting count of 'a'======\n";
    cout<<"Multimap.count('a')="<<Multimap.count('a');

    cout<<"\n====find can return any pair with 'a'======\n";
    auto pair=Multimap.find('a');
    cout<<pair->first<<" "<<pair->second<<endl;

    cout<<"\n========Finding Upper and Lower bound======\n";
    auto range1=Multimap.lower_bound('a');
    cout<<"\nLower bound: "<<range1->first<<" "<<range1->second<<endl;

    auto range2=Multimap.upper_bound('a');
    cout<<"\nUpper bound: "<<range2->first<<" "<<range2->second<<endl;

    return 0;
}


/*
Output:

Iterating over Multimap
a 1
a 2
a 3
b 4
b 5

Getting All pairs of given key
a 1
a 2
a 3

====Getting count of 'a'======
Multimap.count('a')=3
====find can return any pair with 'a'======
a 1

========Finding Upper and Lower bound======

Lower bound: a 1

Upper bound: b 4
*/