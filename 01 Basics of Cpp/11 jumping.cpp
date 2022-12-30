break:
int main(){
    int i;
    for(i=10;i>0;i--){
        if(i==5){
            break;
        }
        cout<<i<<endl;
    }
    return 0;    
}

continue:
int main(){
    int i;
    for(i=10;i>0;i--){
        if(i==5){
            continue;
        }
        cout<<i<<endl;
    }
    return 0;    
}

goto:
int main(){
    int age=20;
    if(age>=18){
        goto vote;
    }
    else{
        goto notvote;
    }
    vote:{
        cout<<"Eligible";
        return 0; 
    }
    notvote:{
        cout<<"Not Eligible";
        return 0; 
    }
    return 0;    
}

Exit:
int main(){
    int i;
    for(i=10;i>0;i--){
        if(i==5){
            exit(0);
        }
        cout<<i<<endl;
    }
    return 0;    
}