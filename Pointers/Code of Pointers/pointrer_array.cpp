#include<iostream>
using namespace std;

int main(){
    int a[10]={1,2,3,4,5};
    cout<<2[a]<<endl;  // same as a[2]
    cout<<sizeof(a)<<endl;
    cout<<sizeof(&a[0])<<endl;
    cout<<a<<endl;
    cout<<&a<<endl;
    return 0;
}