#include<iostream>
using namespace std;


/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/
#include <iostream>
using namespace std;

int partition(int a[],int s,int e){
    int n=a[s];
    int count=0;
    for(int i=s+1;i<(e+1);i++){
        if(n>=a[i]){                    
            count++;
        }
    }
    int c=s+count;
    int temp=a[c];
    a[c]=n;
    a[s]=temp;
    int i=s,j=e;
    while(i<c && j>c){
       if(a[i]<=n){
           i++;
       }
        else if (a[j] > n) {
            j--;
        }
        else{
            int t=a[j];
            a[j]=a[i];
            a[i]=t;
            i++;
            j--;
        }
    }
    return c;
}
void quickSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int c=partition(a,s,e);
    quickSort(a,s,c-1);
    quickSort(a,c+1,e);
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
   quickSort(input,0,size-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;
    return 0;
}