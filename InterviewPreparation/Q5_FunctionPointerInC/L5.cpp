/*
Where to use function pointer.
Example: qsort
*/

#include<iostream>
using namespace std;

int compare(const void *p,const void *q)
{
    int l= *(const int*)p;
    int r= *(const int*)q;
    return l>r;
}

int main()
{
    int Arr[5]={3,2,4,1,5};

    int ArrSize = sizeof(Arr)/sizeof(Arr[0]);
    int elementSize = sizeof(Arr[0]);

    qsort(Arr,ArrSize,elementSize,compare);
    cout<<"\nOutput:";
    for(const auto ele:Arr)
    {
        cout<<"-"<<ele;
    }
    return 0;
}

/*
Output:
Output:-1-2-3-4-5
*/