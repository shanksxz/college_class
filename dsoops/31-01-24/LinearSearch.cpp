#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[0] == key)
    {
        return 0;
    }

    int restArray = linearSearch(arr + 1, n - 1, key);

    if (restArray == -1)
    {
        return -1;
    }

    return restArray + 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int key = 4;
    cout << linearSearch(arr, 5, key);
    return 0;
}