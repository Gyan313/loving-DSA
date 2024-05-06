#include<iostream>
#include<cstring>
using namespace std;
#include "student_class_2.cpp"

int main(){
    char name[]="gyan";
    student s1;
    s1=student(20,name);
    s1.display();
    
    // with inbuilt copy constructor we can only made shallow copy
    // to make deep copy on one object in other make copy constructor explicitly
    student s2(s1);    
    s2.name[0]='y';   // i made name public for some time

    s1.display();
    s2.display();
    return 0;
}