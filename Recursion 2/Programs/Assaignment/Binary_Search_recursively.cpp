#include <iostream>
using namespace std;

// input - input array
// size - length of input array
// element - value to be searched

int binarysearchhelp(int input[], int start, int end, int x) {
  if (start > end)
    return -1;
  int mid = (start + end) / 2;

  if (input[mid] == x)
    return mid;
  if (x > input[mid])
    return binarysearchhelp(input, mid + 1, end, x);
  if (x < input[mid])
    return binarysearchhelp(input, start, mid - 1, x);
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
    binarysearchhelp(input, 0, size - 1, element);
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
