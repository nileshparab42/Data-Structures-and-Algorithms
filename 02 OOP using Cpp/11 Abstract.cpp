/*Defination:
Abstract class are such classes that you are defined to inherit only by other classes. The purpose of abstract classes os to provide a structure to other classes is to provide a structure to other classes which you can inherit.
Note:
1. We can't create object for abstract class.
2. A class which contain at least one pure virtual function called abstract class.
*/

// Program:
#include <iostream>
using namespace std;
class animal{
    virtual void sound()=0;
};
class dog: public animal{
    public:
    void sound(){
        cout<<"Woof Woof...";
    }
};
int main()
{
    dog obj;
    obj.sound();
    return 0;
}