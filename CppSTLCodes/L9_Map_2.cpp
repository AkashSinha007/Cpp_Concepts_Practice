//Topic: Map in C++

/*
SYNTAX: map<T1,T2> obj; //where T1 is key type and T2 is value type.
*/

/*
Note:
1.std::map is associative container that store elements in 
 key-value combination,where key should be unique, otherwise it overrides 
 the previous value.

2.It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree)
3.It store key value pair in sorted order on the basis of key(ascending/descending)
4.std::map is generally used in Dictionary type problem.
5.STL map does not allow same Keys to be used. 
  You may want to go for multi-map for that. 
  a map will not throw any compile/run time error while inserting value 
  using duplicate key. 
  but while inserting, using the duplicate key it will not insert a new 
  value, it will return the same exiting value only.
6.To check if a particular key in the map exists, use the count member 
  function in one of the following ways:
  m.count(key) > 0
  m.count(key) == 1
  m.count(key) != 0
  The documentation for map::find says: 
  "Another member function, map::count, can be used to just check 
  whether a particular key exists."

  The documentation for map::count says: "Because all elements in a map 
  container are unique, the function can only 
  return 1 (if the element is found) or zero (otherwise)."

7.To retrieve a value from the map via a key that you know to exist, use map::at:
  value = m.at(key)

8.C++20 gives us std::map::contains to do that.
    std::map<int, std::string> example = {{1, "One"}, {2, "Two"}, 
                                     {3, "Three"}, {42, "Don\'t Panic!!!"}};

    if(example.contains(42)) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not found\n";
    }

9.map<string, string> m;
  m.insert(make_pair("f","++--"));
  Use map::find
  if ( m.find("f") == m.end() ) {
    // not found
  } else {
    // found
  }
*/

#include<iostream>
#include<map>
#include<functional>
#include<vector>
using namespace std;

int main()
{
    std::map<string,vector<int>,std::less<>> Map;
    Map["Chotu"].push_back(909090);
    Map["Amit"].push_back(505050);
    Map["Amit"].push_back(515151);
    //Map.insert(std::make_pair("Bot",202020));


    //Loop through Map
    for(auto &el1:Map)
    {
        cout<<el1.first<<endl;
        for(auto &el2:el1.second)
        {
            cout<<el2<<" ";
        }
        cout<<"\n";
    }

    //Access using [] operator
    //cout<<"\nMap[Chotu]="<<Map["Chotu"];

    return 0;
}


/*
Output:
Amit
505050 515151
Chotu
909090
*/