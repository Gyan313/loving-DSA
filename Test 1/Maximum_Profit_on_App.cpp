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

int maximumProfit(int budget[], int n) {
    // Write your code here
    msort(budget,0,n-1);
    int profit=0;
    for(int i=0;i<n;i++){
        if((n-i)*budget[i]>profit){
          profit = (n - i) * budget[i];
        }
    }
    return profit;
}


int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
