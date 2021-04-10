//Topic: std::deque in c++ ( DOuble-Ended- Queue)

/*
Notes:
1.std::deque is an indexed sequence container
2.It allows fast insertion at both beginning and end;
3.Unlike vector elements of deque are not stored contiguous.
4.It uses individual allocated fixed size array, with additional 
  bookkeeping, meaning index based access to deque must perform 
  two pointer dereference, but in vector we get in one dereference.
5.The storage of a deque is automatically expanded and contracted 
  as needed.
6.Expansion of deque is cheaper than expansion of vector.
7.A deque holding just one element has to allocate its full internal 
  array(e.g. 8 times the object size on 64-bit libstdc++; 16times the 
  object size or 4096bytes,whichever is larger, on 64-bit libc++).

*/

/*
TIME COMPLEXITY
Random access - constant O(1)
Insertion or removal of elements at the end or beginning - Constant O(1)
Insertion or removal of elements - O(n)
*/

#include<iostream>
#include<deque>
using namespace std;

void print(const std::deque<int>& dqu)
{
    for(int num:dqu)
        cout<<num<<" ";
    cout<<endl;
}

int main()
{
    {
        std::deque<int> dqu={2,3,4};
        dqu.push_front(1);
        dqu.push_back(5);
        print(dqu);
    }
    {
        std::deque<int> dqu={2,3,4};
        dqu.pop_front();
        dqu.pop_back();
        print(dqu);
    }

    return 0;
}

/*
Output:
1 2 3 4 5 
3
*/