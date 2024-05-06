#include<iostream>
using namespace std;

// My solution but wrong due to time complexity exceeds
int findUnique(int *arr,int n){
    if(n==1){
        return arr[0];
    }
    int count=0,k;
    for(int i=1;i<n;i++){
        if(arr[0]==arr[i]){
            k=i;
            count++;
        }
    }
    if(count==0){
        return arr[0];
    }
    else{
        for(int i=k;i<n;i++){
            arr[i]=arr[i+1];
        }
        findUnique(arr+1,n-1);
    }
}

// coding ninjas code.
int findUnique(int *arr, int n) {
    // Write your code here
    int x;
    for(int i=0;i<n;i++){
        x=x^arr[i];
    }
    return x;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}