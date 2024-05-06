#include<iostream>
using namespace std;

int main(){

    //  3 different type const and pointer relations
    
    // const int i=0;
    // int *p=&i;
    // cout<<*p<<endl;

    // const int i=0;
    // const int *p=&i;
    // cout<<*p<<endl;

    int i=0;
    const int *p=&i;
    cout<<*p<<endl;
    return 0;
}