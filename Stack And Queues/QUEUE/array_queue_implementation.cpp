#include<iostream>
using namespace std;
#include "array_queue_class.h"

int main(){
    queue<int> q(5);

    q.Enqueue(65);
    q.Enqueue(66);
    q.Enqueue(67);
    q.Enqueue(68);
    q.Enqueue(69);
    q.Enqueue(70);
    q.Enqueue(71);

    cout<<q.front()<<endl;

    cout<<q.Dequeue()<<endl;

    cout<<q.front()<<endl;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    cout<<q.front()<<endl; //66
    q.Enqueue(1234);
    cout<<q.front()<<endl;
    cout<<q.isEmpty()<<endl;

    cout<<q.Getsize()<<endl;
    cout<<q.Dequeue()<<endl;
    return 0;
}