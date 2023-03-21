#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int top() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

    int size() {
        int count = 0;
        Node* temp = front;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    bool isEmpty() {
        if (front == NULL) {
            cout << "Yes" << endl;
            return true;
        } else {
            cout << "No" << endl;
            return false;
        }
    }

};

int main() {
    Queue q;

    q.enqueue(18);
    q.enqueue(20);
    q.enqueue(39);
    q.enqueue(34);
    q.enqueue(27);

    q.display();

    cout << "Top element: " << q.top() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is empty: " << q.isEmpty() << endl;

    q.dequeue();
    q.dequeue();

    q.display();

    cout << "Top element: " << q.top() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is empty: " << q.isEmpty() << endl;

  return 0 ;
}