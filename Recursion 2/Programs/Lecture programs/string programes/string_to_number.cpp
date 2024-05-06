#include <iostream>
using namespace std;

int len(char input[]){
    int i=0;
    while(input[0]!='\0'){
        i++;
    }
    return i;
}

int stringToNumber(char input[]) {
    // Write your code here
    if (input[1]) {
        return input[0]-'0';
    }
    int t=stringToNumber(input + 1);
    int a=(input[0]-'0');
    for(int i=1;i<len(input);i++){
        a=a*10;
    }
    return t+a;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
    return 0;
}
