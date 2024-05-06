#include<iostream>
using namespace std;

int main(){
    int i=0;
    int j=2;
    
    int const  *p=&i;
    p=&j; // can do this 
    // (*p)++;   but can't do this
    cout<<*p<<endl;

    int * const p1=&i;
    // p1=&j;   can't do this 
    (*p1)++; // can do this 
    cout<<*p1<<endl;

    int const * const p2=&i;
    // p2=&j;   can't do this 
    // (*p2)++;    cannot do this as well
    cout<<*p2<<endl;

    return 0;
}
    // if did'nt understand any of the above than mofo go to the notes revise bastard
   
   
   
   
   
   
   