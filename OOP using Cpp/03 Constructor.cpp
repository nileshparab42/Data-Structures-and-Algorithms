/* Defination:
Constructor is a special type of function which is automatically called at the time of object creation

Note:
The main purpose of constructor is used to "initialize the object"

Types:
1. Default 
2. Parametrized
3. Copy
*/

// 1. Default :
#include <iostream>
using namespace std;
class A{
    private:
    int a,b;
    public:
    A(){
        a=10;
        b=20;
        cout<<a<<"\t"<<b;
    }
};
int main()
{
    A obj;
    return 0;
}

// 2. Parametrized:
#include <iostream>
using namespace std;
class A{
    public:
    A(int a, int b){
        cout<<a<<"\t"<<b;
    }
};
int main()
{
    A obj(100,200);
    return 0;
}

// 3. Copy:
#include <iostream>
using namespace std;
class A{
    private:
    int x,y;
    public:
    A(int a, int b){
        x=a; y=b;
        cout<<a<<"\t"<<b<<"\n";
    }
    A(A &ref){      //Copy constructor
        x=ref.x;
        y=ref.y;
        cout<<x<<"\t"<<y<<"\n";
    }
};
int main()
{
    A obj(100,200);
    A obj2(obj);
    return 0;
}
