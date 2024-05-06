#include<iostream>
using namespace std;
#include "student.cpp"

int main(){
    student s1(10,200);
    student s2;
    s2=s1;
    student *s3=new student;
    *s3=s2;
    // if we do not write delete s3 than destructor will not called for s3
    // for explation see the notebook
    
    delete s3;
    return 0;
}