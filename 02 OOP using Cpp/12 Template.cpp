/*Defination:
Template is the frame which defined its actual meaning in a C++ programming. The main purpose of template is to "it accepts any type of value" at the time of program execution.

We can use template in C++ by two ways:
1. Function template
2. Class template
*/

/*
Function template:
Normal function works only with one type of value at a time but "function template" works with different-different types at a time.
*/
// Program:
#include <iostream>
using namespace std;
template <class A>
void print(A a){
    cout<<a<<"\n";
}
int main()
{
    print(20);
    print(14.56);
    print("Nilesh");
    return 0;
}

/*
Class template:
Class template is also known as generic class. We use class template when user doesn't know what kind of value to pass from the parameters.
*/
// Program:
#include <iostream>
using namespace std;
template <class A>
class print{
    public:
        print(A x,A y){
            cout<<x<<"\t"<<y<<"\n";
        }
};
int main()
{
    print <char> obj('n','p');
    return 0;
}