#include<iostream>
using namespace std;

class student{
       int age;
       int const rollNo;
    public: 
        // initialization list
        student(int r,int age):rollNo(r),age(age){
        }
        void print(){
            cout<<rollNo<<" "<<age<<endl;
        }
};
int main(){
    student s1(10,1);
    s1.print();
    return 0;
}