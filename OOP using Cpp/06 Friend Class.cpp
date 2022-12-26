/*Defination:
If a class become a friend class to a other class then it can access the all private and protected members of that class.

Note:
1. Friend class is declared always with friend keyword.
*/

// Program:
#include <iostream>
using namespace std;
class A;
class B;
class A{
    private:
        int a,b;
    public:
        void initialize(){
            a=10;b=20;
        }
        friend class B;
};
class B{
    private:
        int c;
    public:
    void add(A ref){
        c=ref.a+ref.b;
        cout<<"Addition : "<<c;
    }
};
int main()
{
    A obj1;
    obj1.initialize();
    B obj2;
    obj2.add(obj1);
    return 0;
}