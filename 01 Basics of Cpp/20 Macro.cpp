Macro is a peice of code in a program which is given some name, Whenever the name is used, it is replaced by the content of Macro.

Note:
Macro is defined vy the help of #define

Type:
1. Object like Macro:
#define num 10
int main()
{
    cout<<num;
    return 0;
}

2. Function like Macro:
#define max(a,b) ((a>b)?a:b)
int main()
{
    cout<<max(10,20);
    return 0;
}



