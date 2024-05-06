#include<iostream>
using namespace std;

int main(){

    // 2 ways to declare a variable dynamically

    // int *p=new int;
    // *p=18;

    //  // OR

    // int *p=new int(18);

    // int *p=new int[10];

    // creating a variable sized array
    int n;
    cin>>n;
    int *p=new int[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(p[i]>max){
            max=p[i];
        }
    }
    cout<<max<<endl;
    return 0;
}