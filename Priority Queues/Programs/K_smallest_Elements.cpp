#include<queue>

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> maxheap;
    for(int i=0;i<k;i++){
        maxheap.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        if(arr[i]<maxheap.top()){
            maxheap.pop();
            maxheap.push(arr[i]);
        }
    }

    vector<int> output;
    while(!maxheap.empty()){
        output.push_back(maxheap.top());
        maxheap.pop();
    }
    
    return output;
}
