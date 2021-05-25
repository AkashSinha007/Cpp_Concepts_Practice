#include "shared_lib.h"
#include<cstdlib>
#include<cstdio>

void  StrCat(const char* str1,const char* str2,char *newstr)
{
    string str = string(str1)+string(str2);
    strcpy(newstr,str.c_str());
}


void  StrCopy(char* str1,char* str2)
{
    strcpy(str1,str2);
}
int  add(int a, int b)
{
    return a+b;
}
void  pipecommand(const char* strCmd)
{
    std::array<char,80> buffer;
    File *pipe= popen(strCmd,"r");
    if(!pipe)
    {
        std::cerr<<"cannot open pipe for reading"<<endl;
    }
    int c= 0;
    while(fgets(buffer.data(),80,pipe)!=NULL)
    {
        c++;
        std::cout<<c<<"\t"<<buffer.data();
    }
    pclose(pipe);
}
void SaySomething(const char* str)
{
    std::cout<<" I typed : "<<str<<endl;
}