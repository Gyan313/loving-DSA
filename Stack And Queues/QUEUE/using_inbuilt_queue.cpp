#include<iostream>
using namespace std;
#include<queue>

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    cout<<q.size();
    q.pop();
    cout<<q.front()<<endl;
    return 0;
}