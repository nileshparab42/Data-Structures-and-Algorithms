Defination:
An exception is unexcepted/ unwanted/ abnormal situation that occured at runtime called exception.

Program:
int main()
{
    int a=0,b=2,c;
    try{
        if(a==0){
            throw a;
        }
        c=b/a;
        cout<<c;
    }
    catch(int x){
        cout<<"cannot divide by "<<x<<"\n"; 
    }
    cout<<"Execution ended !!!";
}