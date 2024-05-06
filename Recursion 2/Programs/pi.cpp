#include <iostream>
using namespace std;

int len(char a[]){
    int i=0;
    while (a[i]!='\0')
    {
        i++;
    }
    return i;
}
void replacePi(char input[]) {
  // Write your code here
  if (input[0] == '\0') {
    return;
  }
  if (input[0] == 'p' && input[1]=='i') {
    int i;
    for (i=(len(input)+1);i>1; i--) {
      input[i+2] = input[i];
    }
    input[0]='3';
    input[1]='.';
    input[2]='1';
    input[3]='4';
    replacePi(input);
  } else {
    replacePi(input + 1);
  }
}

int main() {
    char input[10000];
    cin>>input;
    replacePi(input);
    cout << input << endl;
}
