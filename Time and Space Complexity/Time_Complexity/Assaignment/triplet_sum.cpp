#include <iostream>
#include<algorithm>
using namespace std;

// My solution but time limit exceed.
void merge(int arr[], int s, int m, int l)
{
    int n1 = (m - s) + 1;
    int n2 = (l - m);

    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[s + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[(m + 1) + j];
    }

    int i = 0;
    int j = 0;
    int k = s;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            arr[k] = R[j];
            j++;
        }
        else
        {
            arr[k] = L[i];
            i++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}
void msort(int a[], int s, int l)
{
    if (s >= l)
    {
        return;
    }
    int mid = (s + l) / 2;
    msort(a, s, mid);
    msort(a, mid + 1, l);
    merge(a, s, mid, l);
}

int tripletSum(int *arr, int n, int num)
{
    // Write your code here
    msort(arr, 0, n - 1);
    int j = n - 1, count = 0, i = 0;
    while (i < j)
    {
        if ((arr[i] + arr[j]) + arr[j - 1] > num)
        {
            for (int k = j - 1; k > i; k--)
            {
                if ((arr[i] + arr[j])+arr[k-1]==num && (k - 1) != i)
                {
                    count++;
                    break;
                }
            }
            j--;
        }
        else if ((arr[i] + arr[j]) + arr[j - 1] == num)
        {
            count++;
            for (int k = j - 1; k > i; k--)
            {
                if (arr[k] == arr[k - 1] && (k - 1) != i)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            i++;
        }
        else
        {
            i++;
        }
    }
    return count;
}

// the time complexity vice right code
int pairSum(int *arr, int n, int num) {
  int startIndex = 0;
  int endIndex = n - 1;
  int count = 0;
  while (startIndex < endIndex) {
    if (arr[startIndex] + arr[endIndex] < num) {
      startIndex++;
    }

    else if (arr[startIndex] + arr[endIndex] > num) {
      endIndex--;
    } else {
      int elementAtStart = arr[startIndex];
      int elementAtEnd = arr[endIndex];
      if (elementAtStart == elementAtEnd) {
        int elementFromStartToEnd = endIndex - startIndex + 1;
        count += (elementFromStartToEnd * (elementFromStartToEnd - 1) / 2);
        return count;
      }
      int tempStartIndex = startIndex + 1;
      int tempEndIndex = endIndex - 1;
      while (tempStartIndex <= tempEndIndex &&
             arr[tempStartIndex] == elementAtStart) {
        tempStartIndex++;
      }
      while (tempEndIndex >= tempStartIndex &&
             arr[tempEndIndex] == elementAtEnd) {
        tempEndIndex--;
      }
      int elementFromStart = tempStartIndex - startIndex;
      int elementFromEnd = endIndex - tempEndIndex;
      count += (elementFromStart * elementFromEnd);
      startIndex = tempStartIndex;
      endIndex = tempEndIndex;
    }
  }
  return count;
}

int tripletSum(int *arr, int n, int num) {
  sort(arr, arr + n);
  int count = 0;
  for (int i = 0; i < n - 2; i++) {
    int x = pairSum(arr + i + 1, n - i - 1, num - arr[i]);
    count += x;
  }

  return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

        cout << tripletSum(input, size, x) << endl;

        delete[] input;
    }

    return 0;
}