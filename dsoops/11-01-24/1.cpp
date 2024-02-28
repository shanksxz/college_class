#include<iostream>
using namespace std;


int searchEle(int arr[], int ele, int n){
    for(int i=0; i<n; i++){
        if(arr[i] == ele){
            return i;
        }
    }
    return -1;
}

int addEle(int arr[], int ele, int n){
    if(n >= 100){
        return n;
    }
    arr[n] = ele;
    return n+1;
}


int addEleAtPos(int arr[], int ele, int pos, int n){
    if(n >= 100){
        return n;
    }
    for(int i=n; i>=pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos-1] = ele;
    return n+1;
}

int deleteEle(int arr[], int ele, int n){
    int pos = searchEle(arr, ele, n);
    if(pos == -1){
        return n;
    }
    for(int i=pos; i<n; i++){
        arr[i] = arr[i+1];
    }
    return n-1;
}



void reverseArr(int arr[], int n){
    for(int i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

int main(){

    // int arr[3] = {1,2,3,4,5};
    // int ele = 3;
    // int n = sizeof(arr)/sizeof(arr[0]);

    // reverseArr(arr, n);


    // for(int i = 0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }


    int arr1[2][2];
    int n1 = 2;

    //input
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n1; j++){
            cin >> arr1[i][j];
        }
    }

    int arr2[2][2];
    int n2 = 2;

    for(int i = 0; i<n2; i++){
        for(int j = 0; j<n2; j++){
            cin >> arr2[i][j];
        }
    }


    int add[2][2];

    //addition
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            add[i][j] = arr1[i][j] + arr2[j][i];
        }
    }

    cout << "Addition of two matrices is: " << endl;

    //printing
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            cout<<add[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}