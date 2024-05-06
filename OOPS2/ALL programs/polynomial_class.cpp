// My solution

class Polynomial {
    int capacity;
    int nextIndex;
    
    public:
    int *degCoeff;      // Name of your array (Don't change this)

       Polynomial(){
           capacity=5;
           degCoeff=new int[capacity];
           for(int i=0;i<capacity;i++){
               degCoeff[i]=0;
           }
           nextIndex=0;
       }

       void setCoefficient(int degree,int coeff){
           if(degree>=capacity){
                capacity=2*capacity;
                int *newDegcoeff=new int[capacity];
                for(int i=0;i<capacity;i++){
                    newDegcoeff[i]=degCoeff[i];
                }
                delete [] degCoeff;
                degCoeff=newDegcoeff;
           }
           degCoeff[degree]=coeff;
           if(degree>=nextIndex){
            nextIndex=degree+1;
           }
       }       

       Polynomial(const Polynomial &p){
        this->capacity=p.capacity;
        this->degCoeff=new int[p.capacity];
        for(int i=0;i<p.nextIndex;i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
        this->nextIndex=p.nextIndex;
       }

       void operator=(const Polynomial &p){
        this->capacity=p.capacity;
        this->degCoeff=new int[p.capacity];
        for(int i=0;i<p.nextIndex;i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
        this->nextIndex=p.nextIndex;
       }


       Polynomial operator+(const Polynomial &p){
        Polynomial p1;
        int j=0;
        if(this->nextIndex>p.nextIndex){
            j=this->nextIndex;
        }
        else{
            j=p.nextIndex;
        }
        for(int i=0;i<j;i++){
            p1.setCoefficient(i,(p.degCoeff[i]+this->degCoeff[i]));
        }
        return p1; 
       }

       Polynomial operator-(const Polynomial &p){
        Polynomial p1;
        int j=0;
        if(this->nextIndex>p.nextIndex){
            j=this->nextIndex;
        }
        else{
            j=p.nextIndex;
        }
        for(int i=0;i<j;i++){
            p1.setCoefficient(i,(p.degCoeff[i]-this->degCoeff[i]));
        }
        return p1; 
       }

       Polynomial operator*(const Polynomial &p){
        Polynomial p1;
        int len=this->nextIndex+p.nextIndex+1;
        int *a=new int[len];
        for(int i=0;i<len;i++){
            a[i]=0;
        }
        for(int i=0;i<this->nextIndex;i++){
            for(int j=0;j<p.nextIndex;j++){
                a[i+j]+=this->degCoeff[i]*p.degCoeff[j];
            }
        }
        for(int i=0;i<len;i++){
            p1.setCoefficient(i,a[i]);
        }

        return p1;
       }

       void print(){
        for(int i=0;i<nextIndex;i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
       }
};



// My submitted soln 

/* class Polynomial {
    int capacity;
    int nextIndex;
    
    public:
    int *degCoeff;      // Name of your array (Don't change this)

       Polynomial(){
           degCoeff=new int[5];
           capacity=5;
           for(int i=0;i<capacity;i++){
               degCoeff[i]=0;
           }
           nextIndex=0;
       }
       
       Polynomial(int capacity){
        degCoeff = new int[capacity];
        this -> capacity = capacity;
        for(int i = 0; i < this -> capacity; i++){
            degCoeff[i] = 0;
        }
       }
       Polynomial(const Polynomial &p){
        this->capacity=p.capacity;
        this->degCoeff=new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
        this->nextIndex=p.nextIndex;
       }


       void setCoefficient(int degree,int coeff){
           if(degree>=capacity){
                int *newDegcoeff=new int[2*degree];
                for(int i=0;i<2*degree;i++){
                    newDegcoeff[i]=0;
                }
                for(int i=0;i<nextIndex;i++){
                    newDegcoeff[i]=degCoeff[i];
                }
                delete [] degCoeff;
                degCoeff=newDegcoeff;
                capacity=2*degree;
           }
           degCoeff[degree]=coeff;
           if(degree>=nextIndex){
            nextIndex=degree+1;
           }
       }       

       void operator=(const Polynomial &p){
        this->capacity=p.capacity;
        this->degCoeff=new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
        this->nextIndex=p.nextIndex;
       }

       Polynomial operator+( Polynomial &p2) {
        int Max=max(capacity,p2.capacity);

       //setting value 0 at remaining index of smaller array
       if(Max==capacity)
       {
           for(int i=p2.capacity;i<capacity;i++)
           {
               p2.setCoefficient(i,0);                        
           }
       }
       if(Max==p2.capacity)
       {
        for(int i=capacity;i<p2.capacity;i++)
           {
               setCoefficient(i,0);
           }
       }
       Polynomial p3;
        for(int i=0;i<Max;i++)
        {
            p3.setCoefficient(i,degCoeff[i] + p2.degCoeff[i]);  
        }
        return p3;
       }

       Polynomial operator-( Polynomial &p2) {
        //  int maxcap = 0;
        // if (this->capacity > p.capacity) {
        //   maxcap = this->capacity;
        // } else {
        //   maxcap = p.capacity;
        // }
        // Polynomial p1(maxcap);
        // for (int i = 0; i < maxcap; i++) {
        //   if(i<this->capacity && i<p.capacity){
        //       p1.degCoeff[i]=this->degCoeff[i]-p.degCoeff[i];
        //   }
        //   else if(i<this->capacity){
        //       p1.degCoeff[i]=this->degCoeff[i];
        //   }
        //   else{
        //       p1.degCoeff[i]=-1*(p.degCoeff[i]);
        //   }
        // }
        // return p1; 
        int Max=max(capacity,p2.capacity);

       //setting value 0 at remaining index of smaller array
       if(Max==capacity)
       {
           for(int i=p2.capacity;i<capacity;i++)
           {
               p2.setCoefficient(i,0);                          
           }
       }
       if(Max==p2.capacity)
       {
        for(int i=capacity;i<p2.capacity;i++)
           {
               setCoefficient(i,0);
           }
       }
       Polynomial p3;
        for(int i=0;i<Max;i++)
        {
            p3.setCoefficient(i,degCoeff[i] - p2.degCoeff[i]);  
        }
        return p3;
       }

       Polynomial operator*(const Polynomial &p){
        Polynomial p1;
        int len=(this->nextIndex+p.nextIndex)+1;
        int *a=new int[len];
        for(int i=0;i<len;i++){
            a[i]=0;
        }
        for(int i=0;i<this->nextIndex;i++){
            for(int j=0;j<p.nextIndex;j++){
                a[i+j]+=this->degCoeff[i]*p.degCoeff[j];
            }
        }
        for(int i=0;i<len;i++){
            p1.setCoefficient(i,a[i]);
        }

        return p1;
       }

       void print() const{
        for(int i=0;i<nextIndex;i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
       }
};
 */