#include<iostream>
using namespace std;

int countZeros(int n) {
    if(n>=1 && n<10){
        return 0;
    }
    if(n%10==0 || n==0){
        return 1;
    }
    int ans=countZeros(n/10);
    // if(n%10==0){
    //     return ans+1;
    // }
    // else{
    //     return ans;
    // }
    return ans+1;
}
int main(){
    cout<<countZeros(40001);
    return 0;
}