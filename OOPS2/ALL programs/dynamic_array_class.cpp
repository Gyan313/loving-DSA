class dynamicArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    // default constructor
    dynamicArray()
    {
        data = new int[5];
        for (int i = 0; i < 5; i++)
        {
            data[i] = 0;
        }
        nextIndex = 0;
        capacity = 5;
    }

    void add(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = 2 * capacity;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    
    // as inbuilt constructor do shallow copy thats why we made our own copy construtor
    dynamicArray(const dynamicArray &d){
        // deep copy 
        this->data=new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++){
            this->data[i]=d.data[i];
        }
        this->nextIndex=d.nextIndex;
        this->capacity=d.capacity;
    }
    
    // copy assaignment operator
    void operator=(const dynamicArray &d){
        this->data=new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++){
            this->data[i]=d.data[i];
        }
        this->nextIndex=d.nextIndex;
        this->capacity=d.capacity;
    }

    int get(int i) const{
        if(i<nextIndex){
            return data[i];
        }
        else{
            return -1;
        }
    }

    void add(int index,int element){
        if(index<nextIndex){
            data[index]=element;
        }
        else if(index==nextIndex){
            add(element);
        }
        else{
            return;
        }
    }

    void print() const{
        for(int i=0;i<nextIndex;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};