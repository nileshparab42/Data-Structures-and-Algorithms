/* Defination:
Class is a user-defined datatype. It has it's own "data members" and "member functions" which are used by creating an "instance of the class".

Note:
By default the access specifier of class is "private"

Defination:
Object is an instance of class that have state and behaviour.
*/

#include <iostream>
using namespace std;
class Print{
    public:
    void show(){
        cout<<"Hello i am Nilesh";
    }
};
int main()
{
    Print obj;
    obj.show();
    return 0;
}
