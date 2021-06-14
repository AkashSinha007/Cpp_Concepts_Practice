
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> pairSum(vector<int> v1,int Sum)
{
    //Logic
    unordered_set<int> s;
    vector<int> result;

    for(int i=0;i<v1.size();i++)
    {
        int x= Sum - v1[i];
        if(s.find(x)!=s.end())
        {
            result.push_back(x);
            result.push_back(v1[i]);
            return result;
        }

        //insert the crrent number inside set
        s.insert(v1[i]);
    } 

    return {};
}

int main()
{
    vector<int> v{10,5,2,3,-6,11};
    int S=4;

    auto p=pairSum(v,S);
    if(p.size()==0)
    {
        cout<<"No such pair";
    }
    else
    {
        cout<<p[0]<<","<<p[1]<<endl;
    }

    return 0;
    
}

/*
Output:
10,-6

*/