#include <iostream>
using namespace std;
class QueueArray {
    int arr[100];
    int front, rear;
public:
    QueueArray() {
        front = rear = -1;
    }
    void enqueue(int val) {
        if (rear == 99) {
            cout << "Array Queue is Full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
    }
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Array Queue is Empty\n";
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
    }
    void display() {
        if (front == -1 || front > rear) {
            cout << "Array Queue is Empty\n";
            return;
        }
        cout << "Queue (Array): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
struct Node {
    int data;
    Node* next;
};
class QueueLinkedList {
    Node* front;
    Node* rear;
public:
    QueueLinkedList() {
        front = rear = NULL;
    }
    void enqueue(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Linked List Queue is Empty\n";
            return;
        }
        cout << "Dequeued: " << front->data << endl;
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }
    void display() {
        if (front == NULL) {
            cout << "Linked List Queue is Empty\n";
            return;
        }
        cout << "Queue (Linked List): ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
    int main() {
    QueueArray qa;
    QueueLinkedList ql;
    qa.enqueue(1);
    qa.enqueue(2);
    qa.display();
    qa.dequeue();
    qa.display();
   cout << endl;
    ql.enqueue(10);
    ql.enqueue(20);
    ql.display();
    ql.dequeue();
    ql.display();

    return 0;
}

