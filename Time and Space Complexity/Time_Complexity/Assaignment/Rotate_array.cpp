#include <iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    //Write your code here
    int *ptr=new int[n];
    int k=0;
   for(int i=0;i<n;i++){
       if(i<(n-d)){
           ptr[i]=input[i+d];
       }
       else{
           ptr[i]=input[k];
           k++;
       }
   }
   for(int i=0;i<n;i++){
       input[i]=ptr[i];
   }
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}