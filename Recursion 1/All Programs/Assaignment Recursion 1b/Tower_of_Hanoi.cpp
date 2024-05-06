#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

void towerOfHanoi(int n,char a,char b,char c){
    // a ---> source, b ----> auxilary, c ----> destination
    if(n < 1){
        return;
    }
    cout<<n<<" "<<a<<" "<<b<<" "<<c<<endl;
    towerOfHanoi(n-1,a,c,b);
    cout<<a<<" "<<c<<endl;
    towerOfHanoi(n-1,b,a,c);
}

int main() {
   int n;
   cin>>n;
   towerOfHanoi(n,'a','b','c');
   return 0;
}

/* How output for n=3 is generated?
Ans) 
    3
    3 a b c
    2 a c b
    1 a b c
    a c
    a b
    1 c a b
    c b
    a c
    2 b a c
    1 b c a
    b a
    b c
    1 a b c
    a c

    Fascinating as fuck man...
*/