#include<iostream>
using namespace std;


int sumOfArr(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int restArray = sumOfArr(arr + 1, n - 1);
    return (arr[0] + restArray);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << sumOfArr(arr, 5);
    return 0;
}