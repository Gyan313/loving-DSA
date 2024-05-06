#include <iostream>
#include <cstring>
using namespace std;

// Brut Force
/* 
int editDistance(string s1, string s2) {
	// Write your code here
	if(s1.empty() && s2.empty()){
		return 0;
	}
	if(s1[0]==s2[0]){
		return editDistance(s1.substr(1),s2.substr(1));
	}

	int a,b,c;
	a=b=c=INT_MAX;
	if(!s1.empty()){
		a=1+editDistance(s1.substr(1),s2); // insertion
	}
	if(!s2.empty()){
		b=1+editDistance(s1,s2.substr(1)); // deletion
	}
	if(!s1.empty() && !s2.empty()){
		c=1+editDistance(s1.substr(1),s2.substr(1));// update
	}

	return min(a,min(b,c));
} 
*/

// Memoization
/* int helper(int** arr,string s1,string s2){
	int m=s1.size();
	int n=s2.size();

	if(s1.empty() && s2.empty()){
		return 0;
	}

	if( arr[m][n]!=-1){
		return arr[m][n];
	}

	if(s1[0]==s2[0]){
		arr[m][n]=helper(arr, s1.substr(1), s2.substr(1));
		return arr[m][n];
	}

	int a,b,c;
	a=b=c=INT_MAX;
	if(!s1.empty()){
		a=1+helper(arr,s1.substr(1),s2); // insertion
	}
	if(!s2.empty()){
		b=1+helper(arr,s1,s2.substr(1)); // deletion
	}
	if(!s1.empty() && !s2.empty()){
		c=1+helper(arr,s1.substr(1),s2.substr(1));// update
	}

	arr[m][n]=min(a,min(b,c));
	return arr[m][n];
}

int editDistance(string s1, string s2)
{
	//Write your code here
	int m=s1.size();
	int n=s2.size();
	int** arr=new int*[m+1];
	for(int i=0;i<m+1;i++){
		arr[i]=new int[n+1];
		for(int j=0;j<n+1;j++){
			arr[i][j]=-1;
		}
	}

	return  helper(arr,s1,s2);
} */

 
// DP Approach
int helper(int** arr,string s1,string s2){
	int m=s1.size();
	int n=s2.size();

	for(int i=1;i<m+1;i++){
		arr[i][0]=i;
	}
	for(int j=1;j<n+1;j++){
		arr[0][j]=j;
	}

	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(s1[m-i]==s2[n-j]){
				arr[i][j]=arr[i-1][j-1];
			}
			else{
				int a,b,c;
				a=1+arr[i-1][j]; // insertion
				b=1+arr[i][j-1]; // deletion
				c=1+arr[i-1][j-1];// update
				arr[i][j]=min(a,min(b,c));
			}
		}
	}

	int ans=arr[m][n];
	for(int i=0;i<m+1;i++){
		delete arr[i];
	}
	delete arr;
	return ans;
}

int editDistance(string s1, string s2)
{
	//Write your code here
	int m=s1.size();
	int n=s2.size();
	int** arr=new int*[m+1];
	for(int i=0;i<m+1;i++){
		arr[i]=new int[n+1];
	}

	return helper(arr,s1,s2);
}



int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}