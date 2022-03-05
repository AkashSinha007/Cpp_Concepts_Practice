/*
Sample code to open and close a existing file.
Also add some content through code.
*/

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
fstream myFileHandler;
    myFileHandler.open("test1.txt");

    if(myFileHandler.is_open())
    {
        cout<<"\nFile has been opened successfully";

        myFileHandler<<"this is sample text to be written to file..";
        myFileHandler.close();
    }
    else
    {
        cout<<"\nunable to open requested file..";
    }
    return 0;
}