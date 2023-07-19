#include<iostream>
using namespace std;

class heap{
    public:
    int* arr;
    int size;
    int len;
    heap(){

    }
    heap(int size){
        this->size=size;
        arr = new int[size];
        len=0;
    }
    void printheap(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    void insert(int data){
        len++;
        arr[len]=data;

        int index=len;
        int parentindex=index/2;

        while(index>1){
            parentindex=index/2;
            if(arr[parentindex]<arr[index]){
                swap(arr[parentindex],arr[index]);
                index=parentindex;
            }
            else{
                break;
            }
        }
    }

    void del(){
        arr[1]=arr[len];
        arr[len]=-1;
        len--;
        int index=1;

        while(index<=len){
            int left=index*2;
            int right=(index*2)+1;
            int largeindex = index;

            if(left<=len && arr[left]>arr[largeindex]){
                largeindex=left;
            }
            if(right<=len && arr[right]>arr[largeindex]){
                largeindex=right;
            }
            if(largeindex!=index){
                swap(arr[largeindex],arr[index]);
                index=largeindex;
                cout<<"NN\n";
            }
            else{
                break;
            }

        }
    }

    void recdel(int index){
        if(index>len){
            return;
        }
        if(index==1){
            arr[index]=arr[len];
            arr[len]=-1;
            len--;
        }
        int left=index*2;
        int right=(index*2)+1;
        int largeindex = index;
        if(left<=len && arr[left]>arr[largeindex]){
            largeindex=left;
        }
        if(right<=len && arr[right]>arr[largeindex]){
            largeindex=right;
        }
        if(largeindex!=index){
            swap(arr[largeindex],arr[index]);
            recdel(largeindex);
        }
        else{
            return;
        }
    }
    

};

void heapify(int arr[],int& len,int index){
        if(index>len){
            return;
        }
        int left=index*2;
        int right=(index*2)+1;
        int largeindex = index;
        if(left<=len && arr[left]>arr[largeindex]){
            largeindex=left;
        }
        if(right<=len && arr[right]>arr[largeindex]){
            largeindex=right;
        }
        if(largeindex!=index){
            swap(arr[largeindex],arr[index]);
            heapify(arr,len,largeindex);
        }
        else{
            return;
        }
    }

void buildHeap(int arr[],int& n){
    int startindex = n/2;
    for(int i=startindex;i>0;i--){
        heapify(arr,n,i);
    }
}


int main(){
    heap h(20);
    h.insert(100);
    h.insert(50);
    h.insert(60);
    h.insert(40);
    h.insert(45);
    h.insert(53);
    h.insert(52);
    // h.del();
    h.recdel(1);
    // h.printheap();

    int arr[13]={-1,12,56,43,6,78,87,5,44,3,23,32};
    int len=12;
    buildHeap(arr,len);

    for(int i=1;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}