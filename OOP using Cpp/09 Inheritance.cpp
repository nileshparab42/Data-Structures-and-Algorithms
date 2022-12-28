/* Defination:
Inheritance is nothing but when one class access the properties of another class is called Inheritance.

Types:
1. Single/ Simple inheritance
2. Multilevel inheritance
3. Multiple  inheritance
4. Hierarchical inheritance
*/

// 1. Single/ Simple inheritance:
#include <iostream>
using namespace std;
class Dad{
    protected:
        int amount;
    public:
        void input(){
            amount=20000;
        }
};
class Son: public Dad{
    public:
        void show(){
            cout<<amount;
        }
};
int main()
{
    Son obj;
    obj.input();
    obj.show();
    return 0;
}

// 2. Multilevel inheritance:
#include <iostream>
using namespace std;
class A{
    protected:
        int a,b;
    public:
        void input(){
            a=20;
            b=10;
        }
};
class B : public A{
    int c;
    public:
        void add(){
            c=a+b;
            cout<<c<<"\n";
        }
};
class C : public B{
    int d;
    public:
        void sub(){
            d=a-b;
            cout<<d<<"\n";
        }
};
int main()
{
    C obj;
    obj.input();
    obj.add();
    obj.sub();
    return 0;
}

// 3. Multiple  inheritance:
#include <iostream>
using namespace std;
int a,b;
class A{
    public:
        void input(){
            a=20;
            b=10;
        }
};
class B {
    int c;
    public:
        void add(){
            c=a+b;
            cout<<c<<"\n";
        }
};
class C : public A, public B{
    int d;
    public:
        void sub(){
            d=a-b;
            cout<<d<<"\n";
        }
};
int main()
{
    C obj;
    obj.input();
    obj.add();
    obj.sub();
    return 0;
}

// 4. Hierarchical inheritance:
#include <iostream>
using namespace std;
int a,b;
class animal{
    public:
        void category(){
            cout<<"Mammal"<<"\n";
        }
};
class cat: public animal{
    public:
        void voice(){
            cout<<"Meow meow..."<<"\n";
        }
};
class dog: public animal{
    public:
        void bark(){
            cout<<"Bhow Bhow..."<<"\n";
        }
};
int main()
{
    cat obj1;
    obj1.category();
    obj1.voice();
    dog obj2;
    obj2.category();
    obj2.bark();
    return 0;
}



