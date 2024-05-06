#include<iostream>
using namespace std;

void g(const int &j){
    j++;
}
void f(const int*p){
    (*p)++;
}
int main(){
    int i=1;
    int *p1=&i;
    f(p1);
    int j=2;
    g(j);
    return 0;
}