#include <bits/stdc++.h>	
using namespace std;	
void bubblesort(int[], int);
int main()
{
	int n, arr[100], num;
	cout << "Enter the number of elements of the array: ";
	cin >> n;
	cout << endl << "Enter the elements of the array to be sorted: " << "\n";
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	bubblesort(arr, n);
	cout << "Array after sorting is:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
void bubblesort(int arr[], int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		bool sorted = true;	
		for (int j = 0; j < n - 1 - i; j++)
		{
			//Inner for loop
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];	
				arr[j + 1] = arr[j];
				arr[j] = temp;
				sorted = false;}
		}
		if (sorted)
		{
			break;
		}
	}
}