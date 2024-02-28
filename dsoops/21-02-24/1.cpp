// sum using operator overloading

#include <iostream>
using namespace std;

class Sum {
    int sum;
    public:

    void get() {
        cout << "Enter number: ";
        cin >> sum;
    }

    void display() {
        cout << "Sum: " << sum << endl;
    }

    Sum operator+(Sum s) {
        Sum temp;
        temp.sum = sum + s.sum;
        return temp;
    }
};

int main() {
    Sum s1, s2, s3;
    s1.get();
    s2.get();
    s3 = s1 + s2;
    s3.display();
    return 0;
}