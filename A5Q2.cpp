#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear, count;
public:
    CircularQueue() : front(0), rear(-1), count(0) {}

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Dequeued: " << arr[front] << "\n";
        front = (front + 1) % SIZE;
        count--;
    }

    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Queue: ";
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % SIZE] << " ";
        cout << "\n";
    }
};

int main() {
    CircularQueue q;
    int ch, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.isEmpty 4.isFull 5.Display 6.Peek 0.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << (q.isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 4: cout << (q.isFull()  ? "Full\n"  : "Not Full\n"); break;
            case 5: q.display(); break;
            case 6: q.peek(); break;
        }
    } while (ch != 0);
}
