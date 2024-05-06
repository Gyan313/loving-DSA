/* Code : Staircase using Dp
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
Constraints :
1 <= T < = 10
1 <= N <= 10^5
Sample input 1
2
2
3
Sample output 1
2
4
Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)
Sample input 2:
2
5
10
Sample output 2:
13
274 */

#include<bits/stdc++.h>
using namespace std;


// brut force way
/*
int helper(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int a=helper(n-1)%(1000000007);
    int b=helper(n-2)%(1000000007);
    int c=helper(n-3)%(1000000007);
    return (a+b+c)%(1000000007);
}
*/



// Memoization
/*
int helper(int *arr,int n){
    if(n==0){
        arr[0]=0;
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int a=helper(n-1)%(1000000007);
    int b=helper(n-2)%(1000000007);
    int c=helper(n-3)%(1000000007);
    arr[n]=(a+b+c)%(1000000007);;
    return arr[n];
}
*/

// long int NumSteps(int n){
//     long int* arr=new long int[n+1];
//     // for(int i=0;i<n+1;i++){
//     //     arr[i]=-1;
//     // }
//     return helper(arr,n);
// }

// DP
long staircase(int n)
{
    if (n <= 2)
    {
        return n;
    }

    long *dp = new long[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1]% (1000000007) + dp[i - 2]% (1000000007) + dp[i - 3]% (1000000007);
    }
    return dp[n] % (1000000007);
}


int main(){
    int t;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<(staircase(n))<<endl;
    }
    return 0;
}