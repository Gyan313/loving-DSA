class fraction{
    int numerator;
    int denominator;
    public: 

       fraction(){}

       fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
       }

       void simplify(){
        int gcd=1; // gcd -----> (greatest common divisor)
        int min=0;

        if(this->numerator>this->denominator){
            min=this->denominator;
        }
        else{
            min=this->numerator;
        }
        for(int i=1;i<min;i++){ // i!=0 cause no. divided by 0 makes no sense
            if(this->denominator%i==0 && this->numerator%i==0){
                gcd=i;
            }
        }
        this->numerator=(this->numerator)/gcd;
        this->denominator=(this->denominator)/gcd;
       }

       void add(const fraction &obj){
        numerator=numerator*(obj.denominator)+denominator*(obj.numerator);
        denominator=denominator*(obj.denominator);

        simplify(); // or this->simplify();
       }
       
       void multiply(fraction const &M){
        this->numerator=this->numerator*(M.numerator);
        this->denominator=this->denominator*(M.denominator);
        
        this->simplify();
       }
       
       void print(){
        cout<<"new numerator = "<<numerator<<" new denominator = "<<denominator<<endl;
       }
};