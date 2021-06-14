//Function Overloading example

/*
Rules where Function Overoading will not work:
1.Function declarations that differ only in the return type.
2.In class if we have similar function name and parameter but one is 
  static function another one is non-static.
3.When we receive array as pointer or array both are similar
4.const and volatile doesn't make any difference.
5.One function parameter declared as function type and another as pointer
  to the same function type are equivalent. Ex: fun(()){}  and fun((*)()){} are equivalent
6.Two function parameters are equal if they differ only if one of them is
  having default parameter.
*/

#include<iostream>
using namespace std;

void print(int i)
{
    cout<<"Integer fun "<<i<<endl;
}

void print(double d)
{
    cout<<"Double fun "<<d<<endl;
}

int main()
{
    print(5);
    print(5.5);
    return 0;
}


/*
Output:
Integer fun5
Double fun5.5
*/