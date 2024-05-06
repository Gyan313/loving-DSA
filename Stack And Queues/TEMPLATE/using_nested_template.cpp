#include<iostream>
using namespace std;
#include "nested_template.cpp"

int main(){
    Pair <int,int> p1;
    p1.setX(10);
    p1.setY(12);
    Pair<Pair<int,int>,int> p2;
    p2.setX(p1);
    p2.setY(18);

    cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY();
    return 0;
}