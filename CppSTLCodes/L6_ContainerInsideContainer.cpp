//Topic: COntainer inside Container
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    std::vector<vector<int>> Tree;
    int edge, n1,n2;

    cout<<"\nenter edge:";
    cin>>edge;  
    Tree.resize(edge);

    for (size_t i = 0; i < edge; i++)
    {
        cin>>n1>>n2;
        Tree[n1].push_back(n2);
    }
    
    for(const auto &e1:Tree)
    {
        for(const auto &e2:e1)
        {
            cout<<e2;
        }
        cout<<endl;
    }

    return 0;
}

/*
Output:

enter edge:6
1 2
1 3
2 4
2 5
3 6
3 8

23
45
68
*/