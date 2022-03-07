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
    myFileHandler.open("test2.txt",ios::out | ios::app);

    /*
        ios::in  - INPUT - READING
        
        ios::out  - OUTPUT - WRITE TO FILE -> if there is 
        no file then create it, if there is a file then truncate 
        it (remove content) unless it occurs with ios::in flag. 
        Therefore it makes sense to use ios::in along with ios::out , but there are better
        option below like ios::ate and ios::app.


        ios::trunc - TRUNCATE - it is truncating the file (cutting everything inside)

        ios::ate - At The End - sets pointer at the end of life -  the place of 
        pointer can be changed in that mode, it's possible to read and write in that mode

        ios::app - Append - the content is added at the end of 
        file( it's not possible to remove content nor adding something in other place than the end of file) 
    */


   /*
        DEFAULT MODE (FLAGS)
        fstream - ios::in | ios::out
        ifstream - ios::in
        ofstream - ios::out
    */

    if(myFileHandler.is_open())
    {
        cout<<"\nFile has been opened successfully";

        myFileHandler<<"\nthis is sample text..";
        myFileHandler.close();
    }
    else
    {
        cout<<"\nunable to open requested file..";
    }
    return 0;
}