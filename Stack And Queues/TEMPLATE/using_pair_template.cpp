#include<iostream>
using namespace std;
#include "template_in_c++.cpp"

int main(){
    Pair<int,double> p1;
    p1.setX(10);
    p1.setY(12);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;
    Pair<double,int> p2;
    p2.setX(100.22);
    p2.setY(106.22);
    cout<<p2.getX()<<" "<<p2.getY()<<endl;
    return 0;
}