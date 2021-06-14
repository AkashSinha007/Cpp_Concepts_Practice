#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v1 = {1,2,3,4,5};

    //Fill Constructor
    vector<int> v2(10,7); //Fill 10 elements with same value 7

    //Pop_back
    v1.pop_back();

    //push_back
    v1.push_back(20);

    //print all the elemecountnts
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<",";
    }
    
    //Size of vector(number of elements)
    cout<<"\nsize: "<<v1.size();

    //Capacity of the vector
    cout<<"\ncapacity: "<<v1.capacity();


    return 0;
}


/*
Output:

1,2,3,4,20,
size: 5
capacity: 5   --- For initialized array size and capacity are same
*/