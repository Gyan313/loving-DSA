#include <iostream>
#include <climits>
#include <vector>
using namespace std;


class PriorityQueue {
    vector<int> pq;
   
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
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
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
};

int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}