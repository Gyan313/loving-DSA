
using namespace std;
void upheapify(int arr[],int Lind){
    int parentIndex=0;
    while(Lind>0){
        parentIndex=(Lind-1)/2;
        if(arr[parentIndex]>arr[Lind]){
            swap(arr[parentIndex] , arr[Lind]);
        }
        else{
            break;
        }
        Lind=parentIndex;
    }
}

void insert(int arr[],int size){
    for(int i=0;i<size;i++){
        upheapify(arr,i);
    }
}

void downHeapify(int arr[],int start,int size){
    int leftChild=(2*start)+1;
    int rightChild=(2*start)+2;
    int n=0;

    while(leftChild<size){
        if(rightChild>=size){
            n=leftChild;
        }
        else if(arr[rightChild]>arr[leftChild]){
            n=leftChild;
        }
        else{
            n=rightChild;
        }

        if(arr[n]<arr[start]){
            swap(arr[n],arr[start]);
        }
        else{
            break;
        }
        start=n;
        leftChild=(2*start)+1;
        rightChild=(2*start)+2;
    }
}

void removeMin(int arr[],int size){
    for(int i=0;i<size;i++){
        swap(arr[0],arr[size-i-1]);
        downHeapify(arr,0,size-i-1);
    }
}

void heapSort(int arr[], int n) {
    // Write your code
    if(n==0){
        return;
    }
    insert(arr,n);
    removeMin(arr,n);
}