class fraction{
    int numerator;
    int denominator;
    public: 

       fraction(){}

       fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
       }
       

       int getnumerator() const {
        return this->numerator;
       }
       int getDenominator() const {
        return this->denominator;
       }

       void simplify(){
        int gcd=1; // gcd -----> (greatest common divisor)
        int min=0;

        if(this->numerator > this->denominator){
            min=this->denominator;
        }
        else{
            min=this->numerator;
        }
        for(int i=1;i<=min;i++){ // i!=0 cause no. divided by 0 makes no sense
            if(this->denominator%i==0 && this->numerator%i==0){
                gcd=i;
            }
        }
        this->numerator=(this->numerator)/gcd;
        this->denominator=(this->denominator)/gcd;
        // this fucntion cannot be constant
       }

       fraction add(const fraction &obj){
        int numi=numerator*(obj.denominator)+denominator*(obj.numerator);
        int denomi=denominator*(obj.denominator);
        
        fraction f(numi,denomi);
        f.simplify(); 
        return f;
       }

       fraction operator+(const fraction &obj) const {
        int numi=numerator*(obj.denominator)+denominator*(obj.numerator);
        int denomi=denominator*(obj.denominator);
        
        fraction f(numi,denomi);
        f.simplify(); 
        return f;
       }
       
       void multiply(fraction const &M){
        this->numerator=this->numerator*(M.numerator);
        this->denominator=this->denominator*(M.denominator);
        
        this->simplify();
       }

       fraction operator*(fraction const &M) const {
        int n=this->numerator*(M.numerator);
        int d=this->denominator*(M.denominator);
        
        fraction f(n,d);
        f.simplify();
        return f;
       }
       
       bool operator==(const fraction &obj) const {
        return (this->numerator==obj.numerator && this->denominator==obj.denominator);
       }

       // pre-increment
       fraction& operator++(){
        this->numerator=this->numerator+this->denominator;
        
        simplify();
        return *this;
       }

        // post-increment
       fraction operator++(int){
        fraction f(this->numerator,this->denominator);
        this->numerator=this->numerator+this->denominator;
        simplify();
        f.simplify();
        return f;
       }

       fraction& operator+=(const fraction &obj){
        this->numerator=this->numerator*obj.denominator+this->denominator*obj.numerator;
        this->denominator=this->denominator*obj.denominator;
        simplify();
        return *this;
       }

       void print(){
        simplify();
        cout<<numerator<<"/"<<denominator<<endl;
       }
};