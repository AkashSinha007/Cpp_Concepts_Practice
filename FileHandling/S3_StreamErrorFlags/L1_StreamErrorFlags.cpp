/*
Sample code to open and close a existing file.
Also add some content through code.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    /*
        bad() - badbit(1) - returns true if there is an error like writing to file which was opened only for reading (ios::in)
        fail() - failbit(4) - returns true if we try to assign string to integer while reading from file or when badbit situation happens

        eof() - eofbit(2) - returns true if the file opened to read reaches the End of File


        1 - 001
        2 - 010
        4 - 100

        bitwise operators: & | ^

        ^
        110 - 6
        010 - 2
        100 - 4
        ^
        010
        010
        000

        good() - goodbit(0) - returns true if everything is fine (if any of the above flags are false)

        rdstate() - ReaD State
        clear() - clear state
    */
    fstream myFileHandler;
    myFileHandler.open("test3.txt", ios::in);

    if (myFileHandler.is_open())
    {
        cout << "\nFile has been opened successfully";

        string buffer;

        do
        {
            myFileHandler >> buffer;

            cout << buffer << endl;
        } while (!myFileHandler.eof());

        cout << (myFileHandler.rdstate() ^ ifstream::eofbit) << endl;
        if ((myFileHandler.rdstate() ^ ifstream::eofbit) == 0)
        {
            myFileHandler.clear();
            // set indicator of place in file to some other place
            //  some other operations on file
        }

        cout << myFileHandler.rdstate();
    }
    else
    {
        cout << "\nunable to open requested file..";
    }
    return 0;
}

/*
OUTPUT:
File has been opened successfully
4
6
*/