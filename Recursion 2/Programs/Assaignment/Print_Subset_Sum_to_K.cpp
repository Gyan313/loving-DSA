#include <iostream>
using namespace std;

// Online C++ compiler to run C++ program online
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void subsetSumToK(int input[], int n, int output[], int m, int k) {
  if (n == 0) {
    if (k == 0) {
      printArray(output, m);
    }
    return;
  }
  subsetSumToK(input + 1, n - 1, output, m, k);
  int i;
  int out[10000];
  for (i = 0; i < m; i++) {
    out[i] = output[i];
  }
  out[i] = input[0];
  subsetSumToK(input + 1, n - 1, out, m + 1, k - input[0]);
}
void printSubsetSumToK(int input[], int size, int k) {
  int output[1000];
  subsetSumToK(input, size, output, 0, k);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
