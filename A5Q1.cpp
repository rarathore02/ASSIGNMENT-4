#include <iostream>
using namespace std;

#define SIZE 5

class SimpleQueue {
    int arr[SIZE];
    int front, rear;
public:
    SimpleQueue() : front(-1), rear(-1) {}

    bool isEmpty() { return front == -1; }
    bool isFull()  { return (rear + 1) % SIZE == front; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue is Full\n"; return; }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is Empty\n"; return; }
        cout << "Dequeued: " << arr[front] << "\n";
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) { cout << "Queue is Empty\n"; return; }
        cout << "Queue: ";
        for (int i = front; i != rear; i = (i + 1) % SIZE)
            cout << arr[i] << " ";
        cout << arr[rear] << "\n";
    }
};

int main() {
    SimpleQueue q;
    int choice, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.isEmpty 4.isFull 5.Display 6.Peek 0.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << (q.isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 4: cout << (q.isFull()  ? "Full\n"  : "Not Full\n"); break;
            case 5: q.display(); break;
            case 6: q.peek(); break;
        }
    } while (choice != 0);
}
