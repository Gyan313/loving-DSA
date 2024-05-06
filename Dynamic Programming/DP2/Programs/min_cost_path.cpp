// Without dynamic programming

/* 
#include <bits/stdc++.h>
using namespace std;

pair<int,int> minBox(int **input, int m, int n,int row,int col){
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if(n+1<col){
        a=input[m][n+1];
    }
    if(m+1<row){
        b=input[m+1][n];
    }
    if(n+1<col && m+1<row){
        c=input[m+1][n+1];
    }
    int ans=min(a,min(b,c));
    pair<int,int> p;
    if(ans==a){
        p.first=m;
        p.second=n+1;
    }
    else if(ans==b){
        p.first=m+1;
        p.second=n;
    }
    else{
        p.first=m+1;
        p.second=n+1;
    }
    return p;
}

int helper(int **input, int m, int n,int row,int col){
    if(m==(row-1) && n==(col-1)){
        return input[m][n];
    }
    pair<int,int> p=minBox(input,m,n,row,col);
    int ans=helper(input,p.first,p.second,row,col);
    return ans+input[m][n];
}

int minCostPath(int **input, int m, int n){
    return helper(input,0,0,m,n);
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
} 
*/



// With using Dynamic Programming
#include <bits/stdc++.h>
#include<climits>
using namespace std;

// Brut force

// int helper(int **input, int m, int n,int row,int col){
//     if(m+1==(row) && n+1==(col)){
//         return input[m][n];
//     }
//     int x=INT_MAX,y=INT_MAX,z=INT_MAX;
//     if((n+1)!=col){
//         x=helper(input,m,n+1,row,col);
//     }
//     if((m+1)!=row){
//         y=helper(input,m+1,n,row,col);
//     }
//     if((m+1)!=row && (n+1)!=col){
//         z=helper(input,m+1,n+1,row,col);
//     }

//     return min(x,min(y,z))+input[m][n];
// }

// int minCostPath(int **input, int m, int n){
//     return helper(input,0,0,m,n);
// }


// Memoization
/* int helper(int **input,int **output, int m, int n,int row,int col){
    if(m+1==(row) && n+1==(col)){
        return input[m][n];
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }
    int x=INT_MAX,y=INT_MAX,z=INT_MAX;
    if((n+1)!=col){
        x=helper(input,output,m,n+1,row,col);
    }
    if((m+1)!=row){
        y=helper(input,output,m+1,n,row,col);
    }
    if((m+1)!=row && (n+1)!=col){
        z=helper(input,output,m+1,n+1,row,col);
    }

    output[m][n]=min(x,min(y,z))+input[m][n];
    return output[m][n];
}

int minCostPath(int **input, int m, int n){
    int **output=new int*[m]; // making the a matrix exactly same as input but it just gonna store the min cost of every index,
    for(int i=0;i<m;i++){
        output[i]=new int[n];
        for(int j=0;j<n;j++){
            output[i][j]=-1;
        }
    }
    return helper(input,output,0,0,m,n);
} */

// DP
int helper(int **input,int **output,int m,int n){
    output[m-1][n-1]=input[m-1][n-1];

    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==m-1 && j==n-1){
                continue;
            }
            int x=INT_MAX,y=INT_MAX,z=INT_MAX;
            if((j+1)!=n){
                x=output[i][j+1];
            }
            if((i+1)!=m){
                y=output[i+1][j];
            }
            if((i+1)!=m && (j+1)!=n){
                z=output[i+1][j+1];
            }
            output[i][j]=min(x,min(y,z))+input[i][j];
        }
    }

    return output[0][0];
}

int minCostPath(int **input, int m, int n){
    int **output=new int*[m]; 
    for(int i=0;i<m;i++){
        output[i]=new int[n];
        for(int j=0;j<n;j++){
            output[i][j]=INT_MAX;
        }
    }
    return helper(input,output,m,n);
}


int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
} 