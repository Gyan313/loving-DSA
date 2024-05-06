#include<iostream>
using namespace std;

int main(){
    int a[10]={1,2,3,4,5};
    char b[10]="gyan dev";
    cout<<a<<endl;
    cout<<&b<<endl;
    cout<<&b[2]<<endl;
    char str[12]="bro";
    // quiz question
    char c='a';
    char *chr=&c;
    chr++;
    cout<<*chr<<endl;
    return 0;
}