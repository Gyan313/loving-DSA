#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    int sum1=0;
    int sum2=(n-2)*(n-1)/2;   // sum of numbers from 0 to n-2 from n ele
    for(int i=0;i<n;i++){
        sum1+=arr[i]; // sum of all the numbers inside array
    }
    return (sum1-sum2);
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}