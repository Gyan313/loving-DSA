class student{
    int age;
    int rollNo;
    public: 
       student(){cout<<"this = "<<this<<endl;}
        student(int a,int b){
            cout<<"constructor called "<<endl;
            age=a;
            rollNo=b;
        }
        student(const student &o){
            cout<<"copy constructor"<<endl;  
            age=o.age;
            rollNo=o.rollNo;
        }
        ~student(){
            cout<<"Destructor is called "<<endl;
        }
        void getData(){
            cout<<age<<" "<<rollNo<<endl;
        }
};