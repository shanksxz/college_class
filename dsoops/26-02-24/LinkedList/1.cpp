#include<iostream>
using namespace std;


class Node {
    public:
    int data;
    Node* next; // what is the type of next? It is a pointer to Node class.

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node*head, int data) {
    Node* temp = new Node(data);

    if(head == NULL) {
        head = temp;
    } else {
        Node* temp1 = head;
        while(temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }

}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}  


int main() {

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->next = second;
    second->next = third;
    third->next = NULL;

    cout << "Linked List : " << endl;
    print(first);

    return 0;
}