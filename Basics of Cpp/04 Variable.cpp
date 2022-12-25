Defination:
Variable is the name of memory location where we store value

Note:
1. Variables are case-sensitive in cpp.
2. In cpp variable must be starts with either (a-z,A-Z) or "_" Underscore.
3. We cannot give extra spaces between the Variables.  

#include <iostream.h>  
#include <conio.h> 
int b=20;      //Global variable
int main(){
    int a=10;      //Local variable
    static int c=30;   //Static variable
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}

