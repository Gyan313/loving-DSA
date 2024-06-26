#include <iostream>
using namespace std;

/**********
 
Following is the main function we are using internally.
Refer this for completing the ComplexNumbers class.
 
 
int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}
 
 ************/


class ComplexNumbers {
    // Complete this class
    int real;
    int img;
    public:
      ComplexNumbers(){
          real=0;img=0;
      }
      ComplexNumbers(int a,int b){
          real=a;
          img=b;
      }
       void plus(const ComplexNumbers &o){
           real=real+o.real;
           img=img+o.img;
       }
       void multiply(const ComplexNumbers &o){
           int temp=real;
           real=real*(o.real)-(img*(o.img));
           img=temp*(o.img)+img*(o.real);
       }
       void print(){
           cout<<real<<" + i"<<img<<endl;
       }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}