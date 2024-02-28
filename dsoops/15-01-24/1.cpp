#include<iostream>
using namespace std;


int Arr(){
    cout << "Hello World" << endl;
}


int main() {
    
    int arr[5] = {1, 2, 3, 4, 5};

    int *ptr = arr;

    cout << *ptr << endl;

    Arr();

    return 0;

}