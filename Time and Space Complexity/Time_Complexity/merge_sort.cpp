// Calculating time taken by merge sort code to run from input size 10 to 1000000(million)

#include<iostream>
#include<sys/time.h>
using namespace std;

long getTimeInMicroSecond(){
    struct timeval start;
    gettimeofday(&start,NULL);
    return start.tv_sec*1000000+start.tv_usec;
}
void merge(int arr[],int s,int m,int l){
	int n1=(m-s)+1;
	int n2=(l-m);

    int *L=new int[n1];
    int *R=new int[n2];
	for(int i=0;i<n1;i++){
		L[i]=arr[s+i];
	}
	for(int j=0;j<n2;j++){
		R[j]=arr[(m+1)+j];
	}

	int i=0;
	int j=0;
	int k=s;
	while(i<n1 && j<n2){
		if(L[i]>=R[j]){
			arr[k]=R[j];
			j++;
		}
		else{
			arr[k]=L[i];
			i++;
		}
		k++;
	}

	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}
	
	delete [] L;
	delete [] R;
}
void msort(int a[],int s,int l){
	if(s>=l){
		return;
	}
	int mid=(s+l)/2;
	msort(a,s,mid);
	msort(a,mid+1,l);
	merge(a,s,mid,l);
}
void mergeSort(int input[], int size){
    msort(input,0,size-1);
}
int main()
{
    for(int n=10;n<=1000000;n=n*10){
        int startTime,endTime;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=n-i;
        }
        startTime=getTimeInMicroSecond();
        mergeSort(arr,n);
        endTime=getTimeInMicroSecond();
        cout<<"merge sort n= "<<n<<" time = "<<endTime-startTime<<endl;
    }
    return 0;
}