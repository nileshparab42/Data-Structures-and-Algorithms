/*We use std keyword for searching C++ in-build functions and classes. It is a inbuilt namespace.*/ 
#include <iostream>
// using namespace std;
template <class A>
class print{
    public:
        print(A x,A y){
            std::cout<<x<<"\t"<<y<<"\n";
        }
};
int main()
{
    print <char> obj('n','p');
    return 0;
}


// Creating our own namespace:
#include <iostream>
using namespace std;
namespace A{
    int a;
    void print(){
        a=10;
        cout<<a;
    }
}
int main()
{
    A::print();
    return 0;
}