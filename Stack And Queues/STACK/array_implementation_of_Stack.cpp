#include<climits>

class stack{
    int nextIndex;
    int capacity;
    int *data;
    public:
       stack(int totalSize){
        data=new int[totalSize];
        nextIndex=0;
        capacity=totalSize;
       }

       void push(int x){
        if(nextIndex==capacity){
            cout<<"error : stack overflow "<<endl;
            return;
        }
        data[nextIndex]=x;
        nextIndex++;
       }

       bool IsEmpty(){

        // 1st way to check isEmpty
        // if(nextIndex==0){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        // 2nd way to check isEmpty
        return nextIndex==0;
       }

       void pop(){
        if(IsEmpty()){
            cout<<"stack is empty "<<endl;
            return ;
        }
        nextIndex--;
       }

       int size(){
        return nextIndex;
       }

       int top(){
        if(IsEmpty()){
            cout<<"stack is empty "<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
       }
};