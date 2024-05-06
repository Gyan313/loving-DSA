#include<iostream>
using namespace std;

// bool is_sorted(int a[],int size){
//     if(size==0 || size==1){
//         return true;
//     }
//     if(a[0]>a[1]){
//         return false;
//     }
//     bool smallOutput=is_sorted(a+1,size-1);
//     return smallOutput;
// }
bool is_sorted(int a[],int size){
    if(size==0 || size==1){
        return true;
    }
    bool smallOutput=is_sorted(a+1,size-1);
    if(!smallOutput){
        return false;
    }
    if(a[0]>a[1]){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    int a[10]={1,2,10,4,5,6};
    bool s=is_sorted(a,6);
    cout<<s<<endl;
    return 0;
}