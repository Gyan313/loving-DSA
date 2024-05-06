#include<iostream>
using namespace std;
#include "fraction_class.cpp"

int main(){
    fraction f1(10,2),f2(15,4);
    f1.add(f2);
    cout<<"sum of fraction f1 and f2 "<<endl;
    f1.print();
    fraction f3(1,2),f4(4,5);
    f3.multiply(f4);
    cout<<"multiply of fraction f1 and f2 "<<endl;
    f3.print();
    return 0;   
}