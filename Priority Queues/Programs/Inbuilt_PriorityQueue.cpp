#include<iostream>
using namespace std;
#include<queue>

int main(){
    priority_queue<int> pq; // by default max-priorityQueue

    for(int i=0;i<8;i++){
        int n=0;
        cin>>n;
        pq.push(n);
    }

    cout<<pq.top()<<endl;

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}