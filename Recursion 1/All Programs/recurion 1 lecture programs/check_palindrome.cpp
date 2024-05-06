// Check whether a given String S is a palindrome using recursion. Return true or false.



#include <iostream>
using namespace std;

bool helper(char a[],int start,int end){
    if(end-start==1 || end==start){
        return true;
    }
    if(a[start]==a[end]){
        bool ans=helper(a,start+1,end-1);
        return ans;
    }
    else{
        return false;
    }
}

bool checkPalindrome(char input[]) {
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return helper(input,0,i-1);
}
int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}