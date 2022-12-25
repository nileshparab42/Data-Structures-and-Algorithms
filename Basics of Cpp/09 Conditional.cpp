Conditional Statements:
1. if
2. if-else
3. nested if-else
4. if-else ladder
5. switch Statement

if Statement:
It test Condition,if Condition is true then if block code will be executed otherwise no action taken

1. if:
if(con){
    // code
}

2. if-else:
if(con){
    // code
}
else{
    // code 
}

3. nested if-else:
if(con){
    if(con){
        // code 
    }
}

4. if-else ladder:
if(con){
    // code 
}
else if(con){
    // code 
}

5. switch Statement:
switch(ch){
    case 1: Statement 1;
            break;
    default: Statement n;
}

Program:
#include <iostream.h>  
#include <conio.h> 
int main(){
    const int a=20; 
    if(a==20){
        cout<<"Its 20";
    }   
    else{
        cout<<"Its not 20";
    }  
    return 0;
}

