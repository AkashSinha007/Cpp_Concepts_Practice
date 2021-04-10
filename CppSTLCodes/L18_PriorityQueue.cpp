//Topic: std::priority_queue in C++ (Priority Queue)

/*
Notes:
1.std::priority_queue is a container adaptor that provides constant time 
  lookup of the largest OR smallest element.
2.By default std::vector is the container used inside.
3.Cost of insertion and extraction is logarithmic
4.std::priority_queue is implemented using std::make_heap, std::push_heap,
  std::pop_heap functions. 
*/
/*
Note: Read about Min heap and Max heap to understand this better.
*/

#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

template<typename T>
void print_queue(T& q)
{
    while(!q.empty())
    {
        std::cout<<q.top()<<" ";
        q.pop();
    }
    cout<<"\n";
}

int main()
{
    {//First example
        std::priority_queue<int> q1;
        for(int elem: {1,8,5,6,3,4,0,9,7,2})
        {
            q1.push(elem);
        }
        cout<<"\n===printing q1======\n";
        print_queue(q1);
    }

    { //Second  example
        std::priority_queue<int,std::vector<int>,std::greater<int>> q2;
        for(int elem: {1,8,5,6,3,4,0,9,7,2})
        {
            q2.push(elem);
        }
        std::cout<<"\n===printing q2======\n";
        print_queue(q2);
    }

    {//Using Lambda to compare elements
        auto cmp=[](int left,int right){
            return (left)<(right);
        };
        std::priority_queue<int,std::vector<int>,decltype(cmp)> q3(cmp);

        for(int elem: {1,8,5,6,3,4,0,9,7,2})
        {
            q3.push(elem);
        }
        std::cout<<"\n===printing q3======\n";
        print_queue(q3);

    }
}

/*
Output:

===printing q1======
9 8 7 6 5 4 3 2 1 0

===printing q2======
0 1 2 3 4 5 6 7 8 9

===printing q3======
9 8 7 6 5 4 3 2 1 0
*/