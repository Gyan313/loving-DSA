class student{
    int age;
    public: 
    char *name;
       student(){}
        student(int age,char* name){
            cout<<"constructor called "<<endl;
            this->age=age; 

            // shallow copy
            // this->name=name; 
            
            // deep copy
            this->name=new char[strlen(name)+1];
            strcpy(this->name,name);
        }
        student(const student &obj){
            this->age=obj.age;
            this->name=new char[strlen(obj.name)+1];
            strcpy(this->name,obj.name);
        }
        void display(){
            cout<<age<<" "<<name<<endl;
        }
};