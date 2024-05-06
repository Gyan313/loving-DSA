#include<queue>

vector<int> kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<k;i++){
        minHeap.push(input[i]);
    }

    for(int i=k;i<n;i++){
        if(input[i]>minHeap.top()){
            minHeap.pop();
            minHeap.push(input[i]);
        }
    }

    vector<int> output;
    while(!minHeap.empty()){
        output.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return output;
}

