#include<vector>

class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

    vector<int> upHeapify(vector<int> pq,int size){
        if(size<=1){
            return pq;
        }
        int i=size-1;
        if(pq.at((i-1)/2) < pq.at(i)){
            swap(pq.at((i-1)/2),pq.at(i));
        }
        return upHeapify(pq,((i-1)/2)+1);
    }

    vector<int> down_heapify(vector<int> pq,int start){
       if(2*(start)+1>=pq.size()){
           return pq;
       }
       int i=start;
       int child1=((2*i)+1);
       int child2=((2*i)+2);
       int n=0;
       if(child1>=pq.size()){
            n=child2;
       }
       else if(child2>=pq.size()){
            n=child1;
       }
       else if(child2>=pq.size() && child1>=pq.size()){
           return pq;
       }
       else if(pq.at(child1) < pq.at(child2)){
           n=child2;
       }
       else{
            n=child1;
       }

       if(pq.at(start)<pq.at(n)){
           swap(pq.at(start),pq.at(n));
       }
       return down_heapify(pq,n);
   }

   public:
    PriorityQueue() {}

    /**************** Implement all the public functions here ***************/

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty()){
            return 0;
        }
        return pq.at(0);
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        pq=upHeapify(pq,pq.size());
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()){
            return 0;
        }
        int n=pq.size()-1;
        int element=pq.at(0);
        pq.at(0)=pq.at(n);
        pq.pop_back();
        pq=down_heapify(pq,0);
        return element;
    }


};