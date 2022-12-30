Defination:
Array is a derived datatype which is constructed by the help of primitive datatype
It stores multiple values in single variable with continuous memory location

1D Array:
int main(){
    int a[5]={10,20,30,40,50};    
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
    return 0;    
}

2D Array:
int main(){
    int a[2][2]={{10,20},{30,40}};    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;    
}
