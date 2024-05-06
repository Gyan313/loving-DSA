#include<iostream>
#include<unordered_map>
using namespace std;

//by using maps
unordered_map<int,int> helper(unordered_map<int,int> map,int n){
    if(n<1){
        map[n]=n;
        return map;
    }
    // calculate
    unordered_map<int,int> output=helper(map,n-1);
    if(n==1){
        map[n]=n;
        return map;
    }
    int ans=output[n-1]+output[n-2];
    output[n]=ans;
    return output;
}

//by using array
int helper2(int* arr,int n){
    if(n<=1){
        return n;
    }

    if(arr[n]!=-1){
        return arr[n];
    }

    int a=helper2(arr,n-1);
    int b=helper2(arr,n-2);

    arr[n]=a+b;
    return arr[n];
}

int fib(int n){
    // using maps
    // unordered_map<int,int> map;
    // return helper(map,n)[n];

    //using array
    int* arr=new int[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=-1;
    }
    return helper2(arr,n);
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}