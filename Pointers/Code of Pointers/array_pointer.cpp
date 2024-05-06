#include<iostream>
using namespace std;

int sum(int a[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i];
    }
    return ans;
}
int main(){
    int a[10];
    cout<<sum(a+2,10)<<endl;   // by doing a+2 we just send the part of array not whole array
    return 0;
}