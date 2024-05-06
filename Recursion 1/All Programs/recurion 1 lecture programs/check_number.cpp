// Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
// Do this recursively.
// Input Format :
//     Line 1 : An Integer N i.e. size of array
//     Line 2 : N integers which are elements of the array, separated by spaces
//     Line 3 : Integer x
// Output Format :
//     'true' or 'false'



#include<iostream>
using namespace std;
bool checkNumber(int input[], int n, int x) {
  if(n==0){
    return false;
  }
  bool ans=checkNumber(input+1,n-1,x);
  if(x==(*input)){
    return true;
  }
  return ans;
}

int main(){
    int a[10]={1,2,3,4,5};
    cout<<checkNumber(a,5,20938);
    return 0;
}