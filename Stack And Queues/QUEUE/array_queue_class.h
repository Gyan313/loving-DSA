template <typename T>

class queue{
    T* data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    
    public:
       queue(int TotalSize){
        data=new T[TotalSize];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        capacity=TotalSize;
       }

       void Enqueue(T d){
        if(capacity==size){
            T *data2=new T[2*capacity];
            int f=firstIndex;
            for(int i=0;i<capacity;i++){
                data2[i]=data[f];
                f=(f+1)%capacity;
            }
            delete [] data;
            data=data2;
            capacity*=2;
            firstIndex=0;
            nextIndex=size;
        }
        data[nextIndex]=d;
        nextIndex=(nextIndex+1)%capacity;
        if(firstIndex==-1){
            firstIndex=0;
        }
        size++;
       }
    
       bool isEmpty(){
        return size==0;
       }

       T Dequeue(){
        if(isEmpty()){
            nextIndex=0;
            firstIndex=-1;
            return 0;
        }
        else if(size==1){
            T d=data[firstIndex];
            firstIndex=-1;
            nextIndex=0;
            size--;
            return d;
        }
        else{
            T d=data[firstIndex];
            firstIndex=(firstIndex+1)%capacity;
            size--;
            return d;
        }
       }

       T front(){
        if(isEmpty()){
            return 0;
        }
        return data[firstIndex];
       }

       int Getsize(){
        return size;
       }
};