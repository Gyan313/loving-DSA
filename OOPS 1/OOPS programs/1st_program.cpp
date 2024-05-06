#include<iostream>
using namespace std;
#include "student.cpp" // we used student.cpp file code here . What it will do was   take all of the code from the student.cpp file and paste it here.

int main(){
    student s1;
    cout<<"s1 address = "<<&s1<<endl;  // you can that s1 address and 'this' keyword has same value
    return 0;
}