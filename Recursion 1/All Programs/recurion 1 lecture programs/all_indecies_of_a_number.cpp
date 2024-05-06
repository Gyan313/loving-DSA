// Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
// Do this recursively. Indexing in the array starts from 0.
// Input Format :
//     Line 1 : An Integer N i.e. size of array
//     Line 2 : N integers which are elements of the array, separated by spaces
//     Line 3 : Integer x
// Output Format :
//     indexes where x is present in the array (separated by space)


#include<iostream>
using namespace std;

// 1st solution ---> bad
int j=0;
int k=0;
int allIndexes(int input[], int size, int x, int output[]) {
  if(size==0){
    return 0;
  }
  if(x==input[0]){
    output[j]=k;
    j++;
  }
  k++;
  int ans=allIndexes(input+1, size-1,x,output);
  if(x==input[0]){
    return ans+1;
  }
  else{
    return ans;
  }
}

// 2nd solution -----> much better done using the help of hint and by me.
int allIndexes(int input[], int size, int x, int output[]){
    if(size == 0){
        return 0;
    }
    int smalloutput = allIndexes(input+1,size - 1,x,output);
    for(int i = 0;i<smalloutput;i++){
        output[i]++;
    }
    if(*input == x){
        smalloutput++;
        for(int i=smalloutput-1;i;i--){
            output[i] = output[i-1];
        }
        output[0] = 0;
        return smalloutput;
    }
    return smalloutput;
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}