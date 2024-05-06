#include <iostream>
using namespace std;

int len(char a[]){
  int i=0;
  while(a[i]!='\0'){
    i++;
  }
  return i;
}
int stringToNumber(char input[]) {
    // Write your code here
    if(len(input)==1){
      return (input[0]-'0');
    }
    int ans=stringToNumber(input+1);
    int a=input[0]-'0';
    for(int i=0;i<(len(input)-1);i++){
      a=a*10;
    }
    return ans+a;
}



int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
