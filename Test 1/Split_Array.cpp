#include <iostream>
using namespace std;

bool helper(int *arr, int n, int lsum, int rsum)
{

    if (n == 0)
        return lsum == rsum;

    if (arr[0] % 5 == 0)
        lsum += arr[0];

    else if (arr[0] % 3 == 0)
        rsum += arr[0];

    else
        return helper(arr + 1, n - 1, lsum + arr[0], rsum) || helper(arr + 1, n - 1, lsum, rsum + arr[0]);

    return helper(arr + 1, n - 1, lsum, rsum);
}

bool splitArray(int *input, int size)
{
    return helper(input, size, 0, 0);
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    if (splitArray(input, size))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}