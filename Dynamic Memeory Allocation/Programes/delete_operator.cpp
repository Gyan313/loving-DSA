#include <iostream>
using namespace std;

int main()
{

    // while(true){
    //     int i=10;
    // }
    // while(true){
    //     int *p=new int(10);
    // }

    // In case of variable

    // int *p=new int(10);
    // cout<<*p<<endl;
    // delete p;
    // cout<<*p<<endl;

    // In case of array

    int *p = new int[10];
    p[0] = 9;
    cout << *p << endl;
    delete[] p; // this is how we delete in case of array
    cout << *p << endl;
    return 0;
}