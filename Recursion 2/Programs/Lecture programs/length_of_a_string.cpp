#include<iostream>
using namespace std;

int len(char s[]){
    if(s[0]=='\0'){
        return 0;
    }
    int ans=len(s+1);
    return ans+1;
}
int main(){
    char s[100]="gyan dev";
    int length=len(s);
    cout<<length;
    return 0;
}