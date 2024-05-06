#include<iostream>
#include<cstring>
using namespace std;
#include "student_class_2.cpp"

int main(){
    char name[]="gyan";
    student s1;
    s1=student(20,name);
    s1.display();

    name[4]='y';
    name[5]='\0';
    student s2(11,name);
    s2.display();

    s1.display();
    return 0;
}