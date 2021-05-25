/*
What is structural padding and packing in C++ ?

Answer: It is a way to speed up cpu optimization
*/

#include<iostream>
using namespace std;

//#pragma pack(1)  //disables packing

struct Base
{
    char a;
    char b;
    int i;
    char c;
};

int main()
{
    cout<<sizeof(Base)<<endl;
    return 0;
}


/*
Notes:
1 word is 4 Bytes in 32 bit processor (max 4 byte process in 1 clock cycle)
1 word is 8 Bytes in 64 bit processor(max 8 byte process in 1 clock cycle)


===========================Case 1 ===================
struct Base
{
    char a;
    char b;
    int i;
};

|a|b|-|-|i|i|i|i|
 0 1 2 3 4 5 6 7   --> bytes (how position-wise stored)

 ************************explain packaging ***********************


 ========================= Case 2 =================================
struct Base
{
    char a;
    int i;
    char b;
};

|a|-|-|-|i|i|i|i|b|-|-|-|
 0 1 2 3 4 5 6 7 8.....11    ---> bytes (how position-wise stored)

 
 How data  gets memory slots

1 Byte ==> can be stored at multiple of 1 memory slot
2 Byte ==> can be stored at multiple of 2 memory slot
4 Byte ==> can be stored at multiple of 4 memory slot
8 Byte ==> can be stored at multiple of 8 memory slot
*/