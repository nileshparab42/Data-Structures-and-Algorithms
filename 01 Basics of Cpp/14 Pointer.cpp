Defination:
Pointer is a variable that able to hold address of another variable.

Note:
While working with Pointer we need two unary operator i.e.
1. & -> address hold operator.
2. * -> value at address operator.

Program:
#include <iostream.h>  
#include <conio.h> 
int main(){
    int *a;
    int b=10;
    a=&b;
    cout<<a<<"\n";
    cout<<*a;
    return 0;
}