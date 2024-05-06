/* 
Code : No. of balanced BTs using DP

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).

Input Format :The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.

Output Format :The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.

Constraints :
1 <= h <= 10^6
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

// SOLUTION

#include <bits/stdc++.h>
using namespace std;

// Brut Force Approach

/* int balancedBTs(int h) {
    // Write your code here
    if(h<=1){
        return 1;
    }

    int x=balancedBTs(h-1);
    int y=balancedBTs(h-2);
    int mod=(int)pow(10,9)+7;

    int temp1=(long(x)*x)%mod;
    int temp2=(2*long(x)*y)%mod;
    int ans=(temp1+temp2)%mod;

    return ans;
} */






// Memoization
/* 
int helper(int n,int* arr){
    if(n<=1){
        arr[n]=n;
        return 1;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int x=helper(n-1, arr);
    int y=helper(n-2, arr);
    int mod=(int)pow(10,9)+7;

    int temp1=(long(x) * x)%mod;
    int temp2=(2*long(x) *y)%mod;

    arr[n]=(temp2+temp1)%mod;
    return arr[n];
}

int balancedBTs(int n){
    int* arr=new int[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=-1;
    }
    return helper(n, arr);
}
*/

// DP
int balancedBTs(int n) {
    // Write your code here
    int* arr=new int[n+1];
    arr[1]=1;
    arr[2]=3;
    int mod=(int)pow(10,9)+7;

    for(int i=3;i<n+1;i++){
        int temp1=(long(arr[i-1]) * arr[i-1])%mod;
        int temp2=(2*long(arr[i-1]) * arr[i-2])%mod;
        arr[i]=(temp1+temp2)%mod;
    }
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}