/*
We can have static members in a structure/class in C++,
but bit fields cannot be static
*/

struct Node
{
 static unsigned int x:5;  //===> Compiler error
};

int main()
{
    return 0;
}