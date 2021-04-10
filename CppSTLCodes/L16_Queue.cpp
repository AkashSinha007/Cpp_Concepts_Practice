/*
Topic: std::queue in c++
*/
/*
Notes:
1.std::queue class is a container adapter that gives the programmer
  the functionality of a queue.
2.queue is FIFO (First-in, First-out) data structure
3.std::queue provides only specific set of functions.
4.std::queue allows to push(insert) at back and pop(remove) from front.
5.std::queue gives front, back,push,pop,empty,size
*/

#include<iostream>
#include<queue>
using namespace std;

void print(std::queue<int> que)
{
    while(!que.empty())
    {
        cout<<que.front()<<",";
        que.pop();
    }
}

int main()
{
    std::queue<int> que;

    que.push(2);
    que.push(3);
    que.push(4);

    print(que);  //Prints 2,3,4
    return 0;
}

/*
Output:
2,3,4
*/