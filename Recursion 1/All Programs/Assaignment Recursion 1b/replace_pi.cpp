#include<iostream>
using namespace std;
#include<string.h>

int j=0;
void replace(char a[],int n){
	if(n<=1){
		return;
	}
	replace(a+1,n-1);
    j++;
    if(a[0]=='p' && a[1]=='i'){
        for(int i=n+1;i>=2;i--){
            a[i+2]=a[i];
        }
        a[0]='3';
        a[1]='.';
        a[2]='1';
        a[3]='4';
    }
    else{
        return;
    }
}
void replacePi(char input[]) {
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
	replace(input,i);
}

   
int main(){
    char a[100];
    cin>>a;
    replacePi(a);
    cout<<a<<endl;
    return 0;
}



// Code i did on coding ninjas

/* #include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print anything

int len(char a[]) {
  int i = 0;
  while (a[i] != '\0') {
    i++;
  }
  return i;
}
void replacePi(char input[]) {
  // Write your code here
  if (input[0] == '\0') {
    return;
  }
  if (input[0] == 'p' && input[1] == 'i') {
    int i;
    for (i = (len(input) + 1); i > 1; i--) {
      input[i + 2] = input[i];
    }
    input[0] = '3';
    input[1] = '.';
    input[2] = '1';
    input[3] = '4';
    replacePi(input);
  } else {
    replacePi(input + 1);
  }
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
 */