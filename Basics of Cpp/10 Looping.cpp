Defination:
It is an iterative Statement which allow block of code to be execute repeatedly

Looing Statements:
1. while
2. do-while
3. for
4. nested

1. while:
int main(){
    int a=10;
    while(a!=0){
        cout<<a<<endl;
        a=a-1;
    }
    return 0;
}

2. do-while:
int main(){
    int a=10;
    do{
        cout<<a<<endl;
        a=a-1;
    }while(a!=0);
    return 0;
}

3. for:
int main(){
    int i;
    for(i=10;i>0;i--){
        cout<<i<<endl;
    }
    return 0;    
}
  