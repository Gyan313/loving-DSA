#include<iostream>
using namespace std;
#include "dynamic_array_class.cpp"

int main(){
    dynamicArray d1,d2;
    d1.add(1);
    d1.add(8);
    d1.add(1);
    d1.add(7);
    d1.add(8);
    d1.add(10);
    d1.print();
    d2=d1;
    d1.add(1,200); // ----> to show deep copy by copy assaignment operator
    d1.print();
    d2.print();
    return 0;
}