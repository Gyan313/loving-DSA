#include<iostream>
using namespace std;

void print_subsequences(string input,string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    print_subsequences(input.substr(1),output);
    print_subsequences(input.substr(1),output+input[0]);
}

int main(){
    string input="gyan";
    string output;
    // output is empty...
    print_subsequences(input,output);
    return 0;
}