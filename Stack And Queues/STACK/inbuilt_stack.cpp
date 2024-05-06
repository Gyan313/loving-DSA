#include<iostream>
using namespace std;
#include<stack>  // this is how we import c++ inbuilt stack library

int main(){
    stack<int> s1;
    stack<int> s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s2.push(10);
    s2.push(20);
    s2.push(30);
    s2.push(40);
    s1.emplace(12);// do the 100% same thing as push(x)
    // swaping one stack values from other
    // 1st way
    // swap(s1,s2);
    
    // 2nd way
    s1.swap(s2);
    cout<<s1.top()<<endl;
    
    cout<<" s1 = ";
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<" s2 = ";
    while(!s2.empty()){
        cout<<s2.top()<<" ";
        s2.pop();
    }
    return 0;
}