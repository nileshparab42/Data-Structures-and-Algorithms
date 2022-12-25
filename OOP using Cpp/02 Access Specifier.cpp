/* 
Accessibility of access specifiers:
1. private ->   1. Class iteslf
                2. Friend of class

2. Protected -> 1. Class iteslf
                2. Inherited class

3. Public ->    1. Anywhere accessible
*/

#include <iostream>
using namespace std;
class A{
    private:
    int a;
    protected:
    int b;
    public:
    int c;
};
int main()
{
    A obj;
    // obj.a=10;        Not allowed
    // obj.b=20;        Not allowed
    obj.c=30;           //allowed
    cout<<obj.c;
    return 0;
}
