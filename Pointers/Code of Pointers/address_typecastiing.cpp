#include<iostream>
using namespace std;

int main(){
    int i=65;
    // Implicit TypeCasting
    char ch=i;
    cout<<ch<<endl;
    // Explicit TypeCasting 
    int *p=&i;
    char *pc=(char*)p;
    cout<<*pc<<endl;
    cout<<*(pc+1)<<endl;
    cout<<*(pc+2)<<endl;
    cout<<*(pc+3)<<endl;
    return 0;
}