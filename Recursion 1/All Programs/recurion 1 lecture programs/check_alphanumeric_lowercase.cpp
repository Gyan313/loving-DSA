#include<iostream>
#include<string.h>
#include<algorithm>
#include<cctype>
using namespace std;

bool isNotAlnum(char c) {
    return isalnum(c) == 0;
}

int main(){
    string s = "1234:,,,,/////...    alsgGHB   ";
    // removed non-alphanumeric
    s.erase(remove_if(s.begin(), s.end(), isNotAlnum), s.end());
    // uppercase char to lowercase char...
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout<<s<<endl;
    return 0;
}