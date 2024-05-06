#include<iostream>
using namespace std;

int helper(int*arr,int n){
    for(int i=0;i<(n+1);i++){
        if(i<=1){
            arr[i]=i;
            continue;
        }
        // if(arr[i]!=-1){
        //     continue;      //no need
        // }
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int fib(int n){
    int* arr=new int[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=-1;
    }
    return helper(arr,n);
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}