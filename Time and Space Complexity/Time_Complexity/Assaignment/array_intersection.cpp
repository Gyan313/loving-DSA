#include <iostream>
using namespace std;


/* --> my wrong code
void intersection(int *arr1, int *arr2, int n, int m) 
{
    //Write your code here
    int i=0;
    int j=0;
    int k=0;
    int *arr=new int[m+n];
    while(i<n && j<m){
        if(arr1[i]>=arr2[j]){
            arr[k]=arr2[j];
            j++;
        }
        else{
            arr[k]=arr1[i];
            i++;
        }
        k++;
    }

    while(i<n){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<m){
        arr[k]=arr2[j];
        j++;
        k++;
    }

    int t=1;
    for(int l=0;l<k;l++){
        if(arr[l]==arr[t]){
            cout<<arr[l]<<" ";
        }
        t++;
    }

} */


// the right code
void merge(int arr[], int s, int m, int l) {
  int n1 = (m - s) + 1;
  int n2 = (l - m);

  int *L = new int[n1];
  int *R = new int[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = arr[s + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[(m + 1) + j];
  }

  int i = 0;
  int j = 0;
  int k = s;
  while (i < n1 && j < n2) {
    if (L[i] >= R[j]) {
      arr[k] = R[j];
      j++;
    } else {
      arr[k] = L[i];
      i++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  delete[] L;
  delete[] R;
}
void msort(int a[], int s, int l) {
  if (s >= l) {
    return;
  }
  int mid = (s + l) / 2;
  msort(a, s, mid);
  msort(a, mid + 1, l);
  merge(a, s, mid, l);
}

void intersection(int *arr1, int *arr2, int n, int m) 
{
    //Write your code here
   msort(arr1,0, n-1);
   msort(arr2,0, m-1);
   int i=0;
   int j=0;
   while(i<n && j<m){
     if(arr1[i]>arr2[j]){
       j++;
     }
     else if(arr1[i]==arr2[j]){
       cout<<arr1[i]<<" ";
       j++;
       i++;
     }
     else{
       i++;
     }
   }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}