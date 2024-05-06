// Given the number 'n', find out and return the number of digits present in a number recursively.

int count(int n)
{
    // write your code here
    if (n == 0)
    {
        return 1;
    }
    int small = count(n / 10);
    return (small + 1);
}
