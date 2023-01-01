/*
Question:
Write a program to find out whether the Triangle is valid or not
*/

#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if((a+b)>c){
        if((b+c)>a){
            if((a+c)>b){
                cout<<"Triangle is Valid";        
    }else{
        cout<<"Triangle is not Valid";  
    }
    }else{
        cout<<"Triangle is not Valid";  
    }
    }else{
        cout<<"Triangle is not Valid";  
    }
    return 0;
}
