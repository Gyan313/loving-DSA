#include<iostream>
using namespace std;

int sum(int a[],int size){
    if(size==1){
        return *a;
    }
    return *a+sum(a+1,size-1);
}
int main(){
    int a[10]={1,2,3,4,5};
    cout<<sum(a,5);
    return 0;
}