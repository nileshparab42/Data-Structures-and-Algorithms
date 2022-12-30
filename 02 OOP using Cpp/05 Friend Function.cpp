/*Defination:
Friend function is a function which is not the member of class instead of that it can access private and protected member of class. 

Note:
1. Friend function is declared with keyword friend.
2. Using friend function we can work with two different classes members.
*/

// Program 1:
#include <iostream>
using namespace std;
int count=0;
class A{
    private:
        string tv;
    public:
        void show(){
            tv = "IPL Final 2022";
        }
        friend void B(A obj);
};
void B(A obj){
    cout<<"Watching "<<obj.tv;
}
int main()
{
    A obj1;
    obj1.show();
    B(obj1);
    return 0;
}

// Program 2:
#include <iostream>
using namespace std;
int count=0;
class A;
class B;
class A{
    private:
        int a;
    public:
        void money(){
            a = 10;
        }
        friend void C(A obj1, B obj2);
};
class B{
    private:
        int b;
    public:
        void money(){
            b = 20;
        }
        friend void C(A obj1, B obj2);
};
void C(A obj1, B obj2){
    int c;
    c=obj1.a+obj2.b;
    cout<<"Money : "<<c;
}
int main()
{
    A obj1;
    obj1.money();
    B obj2;
    obj2.money();
    C(obj1, obj2);
    return 0;
}
