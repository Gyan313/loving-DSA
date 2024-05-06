// Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
// First index means, the index of first occurrence of x in the input array.
// Do this recursively. Indexing in the array starts from 0.
// Input Format :
//      Line 1 : An Integer N i.e. size of array
//      Line 2 : N integers which are elements of the array, separated by spaces
//      Line 3 : Integer x
// Output Format :
//      first index or -1



#include<iostream>
using namespace std;

int firstIndex(int input[],int size,int x){
  if(size==0){
    return -1;
  }
  int ans=firstIndex(input+1, size-1,  x);
  if(x==(*input)){
    return ans+1;
  }
  if(ans==(-1)){
    return ans;
  }
  return ans+1;
  
}

int main(){
    int a[10]={0,1,2,3,5};
    cout<<firstIndex(a,5,4);
    return 0;
}