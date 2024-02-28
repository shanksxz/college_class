#include<iostream>
using namespace std;


void bubbleSort(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }
    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }
    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    bubbleSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}