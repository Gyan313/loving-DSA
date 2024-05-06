#include <iostream>
using namespace std;

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

int pairSum(int *arr, int n, int num)
{
	//Write your code here
	msort(arr, 0, n-1);
	int j=n-1,count=0,i=0;
  while(i<j){
		if((arr[i]+arr[j])>num){
			j--;
		}
		else if((arr[i]+arr[j])==num){
			count++;
            for(int k=j;k>i;k--){
                if(arr[k]==arr[k-1] && (k-1)!=i){
                    count++;
                }
                else{
                    break;
                }
            }
			i++;
		}
		else{
			i++;
		}
	}
  return count;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}