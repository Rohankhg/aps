#include <iostream>
using namespace std;

int random(int min, int max) 
{
    int range = max - min + 1;
    int num = min + (rand() % range);
    return num;
}
int partition(int arr[], int p, int r) 
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1]; 
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}
int randomizedPartition(int arr[], int p, int r) 
{
    int i = random(p, r);
    int temp = arr[r];
    arr[r] = arr[i];
    arr[i] = temp;
    return partition(arr, p, r);
}
int randomizedSelect(int arr[], int p, int r, int i)
{
    if (p == r) 
        return arr[p];
    int q = randomizedPartition(arr, p, r);
    int k = q - p + 1;
    // The pivot value is the answer
    if (i == k) 
        return arr[q];
    else if (i < k) 
        return randomizedSelect(arr, p, q - 1, i);
    else
        return randomizedSelect(arr, q + 1, r, i - k);
}

int main()
{
    int n, i;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Enter i: ";
    cin >> i;
    cout << randomizedSelect(A, 0, n - 1, i) << endl;
    return 0;
}