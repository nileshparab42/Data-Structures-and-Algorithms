/* Defination:
Polymorphism is the greek word whose meaning is "Same object having different behaviour".
Poly -> Many
Morphism -> Forms

Types:

1. Compile time polymorphism (Function Overloading)
Whenever a class contains more than one method with same name different types of parameters called as function overloading
Note:
1. This polymorphism exist at the time of compilation
2. Compiletime polymorphism is also known as early binding or static polymorphism.
*/

#include <iostream>
using namespace std;
class A{
    int a,b;
    float res;
    public:
    void add(){
            a=40;b=55;
            res=a+b;
            cout<<res<<"\n";
        }
        void add(int a,int b){
            res=a+b;
            cout<<res<<"\n";
        }
        void add(double a,double b){
            res=a+b;
            cout<<res<<"\n";
        }
};
int main()
{
    A obj;
    obj.add();
    obj.add(30,20);
    obj.add(10.3,10.2);
    return 0;
}

/*
2. Runtime polymorphism(Function Overriding)
Whenever we writing method in the base and derived classes in such a way that function name, parameters must be same this is called as function overriding
Note:
1. This polymorphism exist at the time of execution of the program this is called as runtime polymorphism
2. Runtime polymorphism is also known as late binding or dynamic polymorphism.
3. In this case we can't call the base class object is known as function overriding problem.
*/
#include <iostream>
using namespace std;
class A{
    public:
    void msg(){
            cout<<"Good Morning"<<"\n";
    }
};
class B: public A{
    int a,b;
    float res;
    
    public:
    void msg(){
            cout<<"Good Night"<<"\n";
    }
};

// By specifing class:
int main()
{
    B obj;
    obj.msg();
    obj.A::msg();
    return 0;
}

// By using pointer:
// To use fuction of derived class use virtual keyword to base class 
int main()
{
    A *p;
    B obj;
    p=&obj;
    p->msg();
    return 0;
}