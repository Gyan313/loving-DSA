#include<iostream>
using namespace std;
#include "fraction_class.cpp"

int main(){
    fraction f1(10,2),f2(10,5),f3;
    f3=f1.add(f2);
    f1.print();
    f2.print();
    f3.print();


    cout<<"add operator"<<endl;
    fraction f4=f1+f2;
    f4.print();

    fraction f5=f1.operator*(f2);  // so basically operator* is function name
    f5.print();
    

    cout<<"multiply operator "<<endl;
    fraction f6=f1*f2;
    f6.print();
    

    cout<<"== operator "<<endl;
    if(f5==f6){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"oh no "<<endl;
    }
    

    // pre-increment
    fraction f7=++(++f1);
    cout<<"pre-increment "<<endl;
    f7.print();
    f1.print();
    
    // post-increment
    fraction f8=f2++;
    cout<<"post-increment "<<endl;
    f8.print();
    f2.print();


    // += operator
    fraction f9(2,3),f10(3,4);
    fraction f11=(f9+=f10);

    (f11+=f10)+=f9; // bracet vala part pehle calculate hoga
    cout<<"+= operator"<<endl;
    f11.print();
    f9.print();
    return 0;
}