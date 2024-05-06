/* Code : Minimum Count

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/


#include <bits/stdc++.h>
using namespace std;

// Brut force way
/*
int helper_BrutForce(int x,int n){
	if(n<=0){
		return 0;
	}
	int a=helper(x,n-(pow(x,2)));
	x++;
	int b=INT_MAX;
	if(pow(x,2)<=n){
		b=helper(x,n-(pow(x,2)));
	}
	return 1+min(a,b);
}
*/

// Memoization
/*
int helper_Memoization(int* arr,int x,int n){
	if(n<=0){
		return 0;
	}
	if(arr[n]!=-1){
		return arr[n];
	}
	int a=helper(arr,x,n-(pow(x,2)));
	x++;
	int b=INT_MAX;
	if(pow(x,2)<=n){
		b=helper(arr,x,n-(pow(x,2)));
	}
	arr[n]=1+min(a,b);
	return arr[n];
}
*/

// DP
int helper_DP(int* arr,int x,int n){
	if(n<=3){
		return n;
	}
	
	arr[0]=0;
	arr[1]=1;
	arr[2]=2;
	arr[3]=3;
	for(int i=4;i<n+1;i++){
		x=1;
		int a=INT_MAX;
		while((x*x)<=i){
			int p=x*x;
			a=min(a,arr[i-p]);
			x++;
		}
		arr[i]=1+a;
	}
	return arr[n];
}

int minCount(int n)
{
	//Write your code here
	int *arr=new int[n+1];
	for(int i=0;i<n+1;i++){
		arr[i]=-1;
	}
	return helper_DP(arr,1,n);
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}