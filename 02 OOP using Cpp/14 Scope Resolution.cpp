/*Defination:
The Scope Resolution Operator in C++ is used to reference the global variable or member function that is out of scope. So, we use the scope resolution operator to access the hidden variable or function of a program. The operator is represented as the double colon (::) symbol.*/

// Program:
#include <iostream>
using namespace std;
class Print{
    public:
    void show();
};
void Print::show(){
        cout<<"Hello i am Nilesh";
    }
int main()
{
    Print obj;
    obj.show();
    return 0;
}