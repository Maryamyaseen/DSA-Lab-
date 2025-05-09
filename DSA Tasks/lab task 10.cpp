#include <iostream>
using namespace std;
class StackArray {
    int arr[100];
    int top;
public:
    StackArray() {
        top = -1;
    }
    void push(int val) {
        if (top == 99) {
            cout << "Array Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }
    void pop() {
        if (top == -1) {
            cout << "Array Stack Underflow\n";
            return;
        }
        cout << "Popped from Array: " << arr[top--] << endl;
    }
   void display() {
        if (top == -1) {
            cout << "Array Stack is empty\n";
            return;
        }
        cout << "Array Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
struct Node {
    int data;
    Node* next;
};
class StackLinkedList {
    Node* top;

public:
    StackLinkedList() {
        top = NULL;
    }
    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (top == NULL) {
            cout << "Linked List Stack Underflow\n";
            return;
        }
        cout << "Popped from Linked List: " << top->data << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    void display() {
        if (top == NULL) {
            cout << "Linked List Stack is empty\n";
            return;
        }
        cout << "Linked List Stack: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    StackArray sa;
    StackLinkedList sl;
    sa.push(1);
    sa.push(2);
    sa.display();
    sa.pop();
    sa.display();
    cout << endl;
    sl.push(10);
    sl.push(20);
    sl.display();
    sl.pop();
    sl.display();
    return 0;
}

