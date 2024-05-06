/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;
int solution[20][20];

void allPaths(int** maze,int size,int y,int x){
	//base case
	// y=row
	// x=column
	if(x==(size-1) && y==(size-1)){
		
		solution[y][x]=1;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cout<<solution[i][j]<<" ";
			}
		}
		cout<<endl;
		solution[y][x]=0;
		return;
	}

	if(x<0 || x>=size || y<0 || y>=size || maze[y][x]==0 || solution[y][x]==1){
		return;
	}
		solution[y][x]=1;
		allPaths(maze,size,y-1,x);// top
		allPaths(maze,size,y+1,x);// bottom
		allPaths(maze,size,y,x-1);// left
		allPaths(maze,size,y,x+1);// right
		solution[y][x]=0;
}

void nPath(int **maze,int n){
	memset(solution, 0, 20*20*sizeof(int));

	allPaths(maze,n,0,0);
}

int main() {
	int n;
	cin>>n;
	int **maze=new int*[n];
	for(int i=0;i<n;i++){
		maze[i]=new int[n];
		for(int j=0;j<n;j++){
			cin>>maze[i][j];
		}
	}
	nPath(maze,n);
	return 0;
}
