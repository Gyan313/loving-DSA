#include<climits>
template <typename T>

class stack{
    T* data;
    int  nextIndex;
    int  capacity;
    public:
       stack(int  TotalSize){
        data=new T[TotalSize];
        nextIndex=0;
        capacity=nextIndex;
       }
       void push(T x){
        if(capacity==nextIndex){
            T* data1=new T[2*capacity];
            for(int i=0;i<nextIndex;i++){
                data1[i]=data[i];
            }
            delete [] data;
            data=data1;
            capacity*=2;
        }
        data[nextIndex]=x;
        nextIndex++;
       }
       bool isEmpty(){
        return nextIndex==0;
       }

       T pop(){
        if(isEmpty()){
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
       }

       int size(){
        return nextIndex;
       }

       T top(){
        if(isEmpty()){
            return 0;
        }
        return data[nextIndex-1];
       }
};