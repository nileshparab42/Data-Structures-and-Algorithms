/* Defination:
Data abstraction is a technique by which only necessary data is shown to the user and unnecessary data is hidden.
*/

// Program:
#include <iostream>
using namespace std;
class Bank{
    private:
        int atmPIN, Balance;
    public:
        int accNumber;
    
    void input(){
        atmPIN=1234;
        Balance=6000;
        accNumber=123456789;
    }
};
int main()
{
    Bank obj;
    obj.input();
    // cout<<obj.atmPIN<<"\n";
    // cout<<obj.Balance<<"\n";     //This is hidden
    cout<<obj.accNumber<<"\n";
    return 0;
}