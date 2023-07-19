#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    cout<<q.empty()<<"\n";

    cout<<q.size()<<"\n";

    cout<<q.front()<<"\n";

    cout<<q.back()<<"\n";

    q.pop();

    cout<<q.empty()<<"\n";

    cout<<q.size()<<"\n";

    cout<<q.front()<<"\n";

    cout<<q.back()<<"\n";

    q.push(50);

    cout<<q.empty()<<"\n";

    cout<<q.size()<<"\n";

    cout<<q.front()<<"\n";

    cout<<q.back()<<"\n";

    return 0;
}