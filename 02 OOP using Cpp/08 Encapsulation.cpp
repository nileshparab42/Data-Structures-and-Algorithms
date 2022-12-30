/* Defination:
Encapsulation is the concept of OOPs, that is used to wrap the data members and member function into a single unit.

Note:
The main purpose of the encapsulation is to secure the data.
*/
#include <iostream>
using namespace std;
class Bank{
    private:
        string name;
        int atmPIN;
    public:
    void input(){
        atmPIN=1234;
        name="Nilesh";
    }
};

int main()
{
    Bank obj;
    obj.input();
    // cout<<obj.name<<"\n";     //This is hidden
    // cout<<obj.atmPIN<<"\n";
    return 0;
}