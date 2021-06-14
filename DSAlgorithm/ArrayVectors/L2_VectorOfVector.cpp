#include <iostream>
#include <vector>
using namespace std;

int main()
{

    //2D Vector
    vector<vector<int>> v1 = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9, 10}, 
        {11, 12}};

    v1[0][0]+=10;  //update

    for (int i = 0; i < v1.size(); i++)
    {
        for(int number :v1[i])
        {
            cout<<number<<" ";
        }

        cout<<endl;
    }
    

    return 0;
}

/*
Output:
11 2 3 
4 5 6
7 8 9 10
11 12
*/