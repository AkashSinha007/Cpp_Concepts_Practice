/*Template Specialization In C++

POINTS:
1. Some time we have to specialize template for a particular data type.
2. We can specialize both "function" and "class" template.
*/

#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

template<typename T>
T addAll(vector<T> list)
{
    T count = 0;
    for(auto& elem:list)
    {
        count+= elem;
    }
    return count;
}

template<>
string addAll(vector<string> list)
{
    int count= 0;
    for(const string& elem:list)
    {
        for(const char& chr:elem)
            count += chr;
    }
    ostringstream Ostr;
    Ostr<<count;
    string strCount = Ostr.str();
    return strCount;
}

int main()
{
    vector<int> vecInt = {4,3,2,5,6,1};
    std::vector<double> vecDouble= {4.0,3.0,2.0,5.0,6.0,1.0};
    vector<string> vecString = {"ab"};
    cout<<addAll(vecInt)<<endl;
    cout<<addAll(vecDouble)<<endl;
    cout<<addAll(vecString)<<endl;

}