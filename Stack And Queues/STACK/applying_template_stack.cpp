#include<iostream>
using namespace std;
#include "stack_using_template.cpp"

int main(){
    stack<char> s(4);
    s.push(97);
    s.push(34);
    s.push(192);
    s.push(282);
    s.push(97);
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}