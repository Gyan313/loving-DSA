#include<iostream>
using namespace std;

void increment(int &i){    // application of reference function
    i++;
}
int main(){
    int i=0;
    // int& j;  you cant do that
    int& j=i;
    // cout<<&j<<endl;
    // cout<<&i<<endl;      // address of i and j are same
    
    increment(i);
    cout<<"hey"<<" "<<i<<endl;
    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;
    return 0;
}