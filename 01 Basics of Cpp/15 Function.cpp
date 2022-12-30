Defination:
Function is block of code that runs only when it is called.

Types:
1. Pre-defined
2. User-defined

Program:
#include <iostream.h>  
#include <conio.h> 
int add(int a, int b){
    int c=a+b;
    return c;
}
int main(){
    cout<<add(10,20);
    return 0;
}