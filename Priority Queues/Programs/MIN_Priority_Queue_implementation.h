#include<vector>
using namespace std;

class PriorityQueue{
    vector<int> pq;

    vector<int> upHeapify(vector<int> pq,int size){
        if(size<=1){
            return pq;
        }
        int i=size-1;
        if(pq.at((i-1)/2) > pq.at(i)){
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
       if(child2>=pq.size() && child1>=pq.size()){
           return pq;
       }
       else if(child2>=pq.size()){
            n=child1;
       }
       else if(pq.at(child1) < pq.at(child2)){
           n=child1;
       }
       else{
            n=child2;
       }

       if(pq.at(start)>pq.at(n)){
           swap(pq.at(start),pq.at(n));
       }
       return down_heapify(pq,n);
   }

    public:
        PriorityQueue(){}

        int getSize(){
            return pq.size();
        }

        int isEmpty(){
            return getSize()==0;
        }

        int getMin(){
            if(isEmpty()){
                return 0;
            }
            return pq[0];
        }

        void insert(int data){
            pq.push_back(data);
            pq=upHeapify(pq,pq.size());
        }

        int removeMin() {
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

        void print(){
            for(int i=0;i<pq.size();i++){
                cout<<pq.at(i)<<" ";
            }
            cout<<endl;
        }
};