/*
Array of bit fields is not allowed.
For example, the below program fails in compilation
*/

struct Node
{
    unsigned int x[10]:2;    //==> Compilation error
};

int mian()
{
    return 0;
}