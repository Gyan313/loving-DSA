#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(int *arr, int n, int index, int k)
{
    if (index == n)
    {
        if (k == 0)
        {
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (k - arr[index] >= 0)
    {
        count += countSubsetSum(arr, n, index + 1, k - arr[index]);
    }
    count += countSubsetSum(arr, n, index + 1, k);

    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << countSubsetSum(arr, n, 0, k) << endl;
        delete[] arr;
    }
    return 0;
}