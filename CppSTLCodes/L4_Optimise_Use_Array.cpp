//Problem in vector - Difference between capacity and size


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec1;  //Issue with vec1 copy to new array and double size
    vector<int> vec2;  //Reserve the size initially to reduce copy
    
    vec2.reserve(31);

    //For vec1
    cout<<"\n=========For Vec1============";
    for (size_t i = 0; i < 32; i++)
    {
        vec1.push_back(i);
        cout<<"\nSize="<<vec1.size()<<"\tCapacity= "<<vec1.capacity();
    }

    //For vec2
    cout<<"\n=========For Vec2============";
    for (size_t i = 0; i < 32; i++)
    {
        vec2.push_back(i);
        cout<<"\nSize="<<vec2.size()<<"\tCapacity= "<<vec2.capacity();
    }
    return 0;
}

/*
Output:
=========For Vec1============
Size=1  Capacity= 1
Size=2  Capacity= 2
Size=3  Capacity= 4
Size=4  Capacity= 4
Size=5  Capacity= 8
Size=6  Capacity= 8
Size=7  Capacity= 8
Size=8  Capacity= 8
Size=9  Capacity= 16
Size=10 Capacity= 16
Size=11 Capacity= 16
Size=12 Capacity= 16
Size=13 Capacity= 16
Size=14 Capacity= 16
Size=15 Capacity= 16
Size=16 Capacity= 16
Size=17 Capacity= 32
Size=18 Capacity= 32
Size=19 Capacity= 32
Size=20 Capacity= 32
Size=21 Capacity= 32
Size=22 Capacity= 32
Size=23 Capacity= 32
Size=24 Capacity= 32
Size=25 Capacity= 32
Size=26 Capacity= 32
Size=27 Capacity= 32
Size=28 Capacity= 32
Size=29 Capacity= 32
Size=30 Capacity= 32
Size=31 Capacity= 32
Size=32 Capacity= 32
=========For Vec2============
Size=1  Capacity= 31
Size=2  Capacity= 31
Size=3  Capacity= 31
Size=4  Capacity= 31
Size=5  Capacity= 31
Size=6  Capacity= 31
Size=7  Capacity= 31
Size=8  Capacity= 31
Size=9  Capacity= 31
Size=10 Capacity= 31
Size=11 Capacity= 31
Size=12 Capacity= 31
Size=13 Capacity= 31
Size=14 Capacity= 31
Size=15 Capacity= 31
Size=16 Capacity= 31
Size=17 Capacity= 31
Size=18 Capacity= 31
Size=19 Capacity= 31
Size=20 Capacity= 31
Size=21 Capacity= 31
Size=22 Capacity= 31
Size=23 Capacity= 31
Size=24 Capacity= 31
Size=25 Capacity= 31
Size=26 Capacity= 31
Size=27 Capacity= 31
Size=28 Capacity= 31
Size=29 Capacity= 31
Size=30 Capacity= 31
Size=31 Capacity= 31
Size=32 Capacity= 62
*/