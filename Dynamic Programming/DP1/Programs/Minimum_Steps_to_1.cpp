#include <bits/stdc++.h>
using namespace std;

// Brut force
int countStepsToOne(int n)
{
	
	if(n==1){
		return 0;
	}
	int a=countMinStepsToOne(n-1);
	int b,c;
	if(n%2==0){
		b=countMinStepsToOne(n/2);
	}
	else{
		b=INT_MAX;
	}
	if(n%3==0){
		c=countMinStepsToOne(n/3);
	}
	else{
		c=INT_MAX;
	}
	return 1+min(a,min(b,c));
	

}



// Memoization
int helper(int* arr,int n){
	if(n==1){
		arr[n]=0;
		return 0;
	}
	if(arr[n]!=-1){
		return arr[n];
	}
	int a=helper(arr,n-1);
	int b=INT_MAX,c=INT_MAX;
	if(n%2==0){
		b=helper(arr,n/2);
	}
	if(n%3==0){
		c=helper(arr,n/3);
	}
	else{
		c=INT_MAX;
	}

	arr[n]=1+min(a,min(b,c));
	return arr[n];
}

int countMinStepsToOne(int n){
	int* arr=new int[n+1];
	for(int i=0;i<n+1;i++){
		arr[i]=-1;
	}
	return helper(arr,n);
}


// DP approach
int helper_DP(int n){
	int* arr=new int[n+1];
	arr[1]=0;
	for(int i=2;i<n+1;i++){
		int a=arr[i-1];
		int b=INT_MAX,c=INT_MAX;
		if(i%2==0){
			b=arr[i/2];
		}
		if(i%3==0){
			c=arr[i/3];
		}
		arr[i]=1+min(a,min(b,c));
	}
	return arr[n];
}

int countStepsToOne(int n)
{
	//Write your code here
	return helper_DP(n);
}



int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}