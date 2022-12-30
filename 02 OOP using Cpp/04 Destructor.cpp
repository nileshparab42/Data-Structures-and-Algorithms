/*Defination:
Destructor is also a special type of member function that is used to de-allocate the memory, allocated by the constructor.
*/

// Program:
#include <iostream>
using namespace std;
int count=0;
class A{
    public:
    A(){
        cout<<"Object "<<++count<<" created"<<endl;
    }
    ~A(){
        cout<<"Object "<<count--<<" deleted"<<endl;
    }
};
int main()
{
    A obj1;
    A obj2;
    return 0;
}