Defination:
File handling is a machanism so that we can store the output of the program in the file and we can perform many operations on the data present in a file.

File operations:
1. Create   -> ofstream
2. Write    -> ofstream
3. Read     -> ifstream

Program:
#include <fstream>
int main()
{
    string str;
    ofstream newFile("\\Location\\Filename.cpp");   //File Creation
    cout<<"File Created...";
    newFile<<"Hello Nilesh Here ...";               //File Write
    newFile.close();
    ifstream newFile("\\Location\\Filename.cpp");   //File Read
    while(getline(newFile,str)){
        cout<<str<<"\n";
    }
    newFile.close();
    return 0;
}