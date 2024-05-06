#include <iostream>
using namespace std;

// Brut Force
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	if(n==0 || maxWeight==0){
		return 0;
	}
    if (weights[0] > maxWeight) {
        return knapsack(weights+1, values+1, n - 1, maxWeight);
    }

	int a,b;
	a=values[0]+knapsack(weights+1, values+1, n - 1, maxWeight-weights[0]);
	b=knapsack(weights+1, values+1, n - 1, maxWeight);
	return max(a,b);
}


// Memoization
int helper_memo(int** arr,int* weight, int* value, int n, int maxWeight){
	if(n==0 || maxWeight==0){
		arr[maxWeight][n]=0;
		return arr[maxWeight][n];
	}

	if(arr[maxWeight][n]!=-1){
		return arr[maxWeight][n];
	}

	if(weight[0]>maxWeight){
		arr[maxWeight][n]=helper_memo(arr, weight+1, value+1,n-1,maxWeight);
		return arr[maxWeight][n];
	}

	int a=value[0]+helper_memo(arr, weight+1, value+1,n-1,maxWeight-weight[0]);
	int b=helper_memo(arr, weight+1, value+1,n-1,maxWeight);

	arr[maxWeight][n]=max(a,b);
	return arr[maxWeight][n];
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
	int **arr=new int*[maxWeight+1];
	for(int i=0;i<maxWeight+1;i++){
		arr[i]=new int[n+1];
		for(int j=0;j<n+1;j++){
			arr[i][j]=-1;
		}
	}

	return helper_memo(arr,weight,value,n,maxWeight);
}


// DP approach
int helper_DP(int** arr,int* weight, int* value, int n, int maxWeight){
	// if size of weight or value become 0 than we stop base case  and if maxweight become 0 than we stop
	for(int i=0;i<maxWeight+1;i++){
		arr[i][0]=0;
	}

	for(int i=0;i<n+1;i++){
		arr[0][i]=0;
	}

	for(int i=1;i<maxWeight+1;i++){
		for(int j=1;j<n+1;j++){
			
		}
	}
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
	int **arr=new int*[maxWeight+1];
	for(int i=0;i<maxWeight+1;i++){
		arr[i]=new int[n+1];
	}

	return helper_DP(arr,weight,value,n,maxWeight);
}

int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}