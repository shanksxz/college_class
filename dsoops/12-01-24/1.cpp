#include<iostream>
using namespace std;


void selectionSort(int arr[], int n){

    // arr[] = {5,4,3,2,1}
    for(int i=0; i<n-1; i++){ // 0 to 3
        int min = i; // min = 0
        for(int j=i+1; j<n; j++){ // 1 to 4
            if(arr[j] < arr[min]){ // 4 < 5
                min = j; // min = 4
            }
        }
        int temp = arr[i]; // temp = 5
        arr[i] = arr[min]; // arr[0] = 1
        arr[min] = temp; // arr[4] = 5
    }

    // time complexity: O(n^2)

}

void insertionSort(int arr[], int n){

    // arr[] = {5,4,3,2,1}
    int pass = 0;
    for(int i=1; i<n; i++){ // 1 to 4
        pass++;
        int key = arr[i]; // key = 4
        int j = i-1; // j = 0 
        while(j>=0 && arr[j] > key){ // 0 >= 0 && 5 > 4
            arr[j+1] = arr[j]; // arr[1] = 5 
            j--; // j = -1
        }
        arr[j+1] = key; // arr[0] = 4
    }

    cout<<"Passes: "<<pass<<endl;
    // time complexity: O(n^2)
}

 void bubbleSort(int arr[], int n){

    // arr[] = {5,4,3,2,1} 
    int pass = 0;
    for(int i=0; i<n-1; i++){ // 0 to 3
        bool swapped = false;
        pass++;
        for(int j=0; j<n-i-1; j++){ // 0 to 3
            if(arr[j] > arr[j+1]){ // 5 > 4
                swapped = true; 
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(!swapped){
            break;
        }
    }

    cout<<"Passes: "<<pass<<endl;
    // time complexity: O(n^2)
}


int main() {

    int arr[5] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    // selectionSort(arr, n);
    insertionSort(arr, n);
    // bubbleSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}