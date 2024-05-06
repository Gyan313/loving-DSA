// Given the number 'n', write a code to print numbers from 1 to n in increasing order recursively.
#include <iostream>
using namespace std;

int print(int n)
{
    // write your code here
    if (n == 0)
    {
        return 1;
    }
    int ans = print(n - 1);
    cout << n << " ";
}

int main()
{
    int n = 4;
    print(n);
    return 0;
}
