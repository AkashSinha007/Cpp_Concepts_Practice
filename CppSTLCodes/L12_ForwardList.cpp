//Topic: forward_list in STL

/*
Note:
1.This is single linked list what we know from C programming language.
2.Why forward_list why not single_list ?
3.We should use this class instead of traditional single linked list 
  because
    a.well tested
    b.Bunch of available function
4.Few Available Operations
    operator = , assign , front, empty, max_size, clear,insert_after,
    emplace_after,reverse,sort,merge,splice_after,unique,remove,
    remove_if,resize
*/

#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
    forward_list<int> fwd_list1={5,4,6,2};
    forward_list<int> fwd_list2={7,6,1,9};

    cout<<"\n======After insert=======\n";
    fwd_list1.insert_after(fwd_list1.begin(),8);    
    for(auto& elem:fwd_list1)
        cout<<elem<<",";      //Prints 5,8,4,6,2

    cout<<"\n======After reverse=======\n";
    fwd_list1.reverse();
    for(auto& elem:fwd_list1)
        cout<<elem<<",";   //Prints 2,6,4,8,5
    

    cout<<"\n======After Merging without sort=======\n";
    fwd_list1.merge(fwd_list2);
    for(auto& elem:fwd_list1)
        cout<<elem<<",";  //Prints 2,6,4,7,6,1,8,5,9,

    cout<<"\n======After Sorting and Merging=======\n";
    fwd_list1.sort();   //After sorting, it will remain sorted for entire program
    fwd_list2.sort();
    fwd_list1.merge(fwd_list2);
    for(auto& elem:fwd_list1)
        cout<<elem<<",";      //Prints 1,2,4,5,6,6,7,8,9

    cout<<"\n======After Splice: Remove from one one and add in other=======\n";
    fwd_list1.splice_after(fwd_list1.begin(),fwd_list2);
    cout<<"\nAfter Splice, size of fwd_list2= "<<std::distance(fwd_list2.begin(),fwd_list2.end());
                   //Prints: After Splice, size of fwd_list2= 0

    cout<<"\n=== using unique( only removes adjacent duplicates) ==\n";
    forward_list<int> fwd_list3={5,2,4,2,6,2,2,2};
    fwd_list3.unique();
    for(auto& elem:fwd_list3)
        cout<<elem<<",";   //Prints 5,2,4,2,6,2

    cout<<"\n=== using remove( Remove all instances irrespective of positions) ==\n";
    forward_list<int> fwd_list4={5,2,4,2,6,2,2,2};
    fwd_list4.remove(2);
    for(auto& elem:fwd_list4)
        cout<<elem<<",";    //Prints 5,4,6

    cout<<"\n========Using remove_if==========\n";
    forward_list<int> fwd_list5={5,2,4,2,6,2,2,2};
    fwd_list5.remove_if([](int n){
        return n>4;
    });
    for(auto& elem:fwd_list5)
        cout<<elem<<",";    //Prints 2,4,2,2,2,2

    cout<<"\n========Using resize==========\n";
    
    forward_list<int> fwd_list6={5,2,4,2,6,2,2,2};
    fwd_list6.resize(2);
    for(auto& elem:fwd_list6)
        cout<<elem<<",";    //Prints 5,2
    cout<<"\n";

    forward_list<int> fwd_list7={5,2,4,2,6,2,2,2};
    fwd_list7.resize(4);
    for(auto& elem:fwd_list7)
        cout<<elem<<",";    //Prints 5,2,4,2
    cout<<"\n";

    forward_list<int> fwd_list8={5,2,4,2,6,2,2,2};
    fwd_list8.resize(10);
    for(auto& elem:fwd_list8)
        cout<<elem<<",";    //Prints 5,2,4,2,6,2,2,2,0,0
    return 0;
}