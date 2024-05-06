#include<iostream>
using namespace std;
#include "student.cpp"

int main(){
    student s1,s2(10,2000),s4;
    s2.getData();
    student s3(s2);
    s3.getData();
    s4=s2; // copy assaignment operator
    s4.getData();
    student s5=student(s4);
    s5.getData();

    student s6(10,500);
    student s7(20,1500);
    s6=s7; // copy assaignment operator
    s6.getData();
    return 0;
}