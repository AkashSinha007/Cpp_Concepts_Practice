
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    vector<int> v{2, 7, 1, 6, 2, -2, 4, 0};

    //count how many entries have the target value (2)

    //Basic implementation without algorithm
    int twos = 0;
    const int target = 2;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == target)
        {
            twos++;
        }
    }
    cout << "\nBasic implementation: twos= " << twos;

    //Alternate execution-1
    /*
    count():
    Returns the number of elements in the range [first,last) that compare equal to target.
    */
    twos = count(v.begin(), v.end(), target);
    cout << "\nAlternate execution-1: twos= " << twos;

    //Alternate execution-2
    twos = count(begin(v), end(v), target);
    cout << "\nAlternate execution-2: twos= " << twos;

    //count how many entries are odd

    //direct method
    int odds = 0;
    for (auto elem : v)
    {
        if (elem % 2 != 0)
        {
            odds++;
        }
    }
    cout << "\nUsing direct method: odds= " << odds;

    //using count_if
    /*
    count_if():
    Returns the number of elements in the range [first,last) for which pred is true.
    pred here is : condition to check
    */
    odds = count_if(begin(v), end(v), [](auto elem) { return elem % 2 != 0; });
    cout << "\nusing count_if: odds= " << odds;

    map<int, int> monthlengths{{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
    int longmonths = count_if(begin(monthlengths), end(monthlengths), [](auto elem) { return elem.second == 31; });
    cout << "\nNumber of long months in a year = " << longmonths;

    //are all, any, or none of the values odd? (Conclude from number of odd entries)
    bool allof, noneof, anyof;
    allof = (odds == v.size());
    noneof = (odds == 0);
    anyof = (odds > 0);

    /*
    all_of: Returns true if pred returns true for all the elements in the 
            range [first,last) or if the range is empty, 
            and false otherwise.
    none_of: Returns true if pred returns false for all the elements in the 
            range [first,last) or if the range is empty, and false otherwise.
    
    any_of: Returns true if pred returns true for any of the elements in 
            the range [first,last), and false otherwise.
            If [first,last) is an empty range, the function returns false.
    */

    allof = all_of(begin(v), end(v), [](auto elem) { return elem % 2 != 0; });
    noneof = none_of(begin(v), end(v), [](auto elem) { return elem % 2 != 0; });
    anyof = any_of(begin(v), end(v), [](auto elem) { return elem % 2 != 0; });

    cout << "\nif all of vector v are odd=" << allof;
    cout << "\nif none of vector v are odd=" << noneof;
    cout << "\nif any of vector v are odd=" << anyof;

    return 0;
}