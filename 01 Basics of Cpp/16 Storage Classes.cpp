
Storage     Memory      Default     Scope       Life
Class                   Value                   Time
-------------------------------------------------------------
1. Auto     RAM         Garbage     Within      Still Block
(Local)                             Block       is active

2. Static   RAM         0           Within      Termination 
                                    Block       of program

3. External RAM         0           Anywhere    Termination
                                                of program

4. Register Register    Garbage     Within      Still Block
(Local)                             Block       is active


Program:
#include <iostream.h>  
#include <conio.h> 
int a=10;       //Global Variable
int main(){
    int b=20;   //Local Variable
    static int c=30;    //Static Variable
    register int d=40;  //Register Variable
    cout<<a<<"\n";
    cout<<b<<"\n";
    cout<<c<<"\n";
    cout<<d<<"\n";
    return 0;
}