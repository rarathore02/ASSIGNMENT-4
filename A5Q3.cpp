#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    int half = n / 2;
    queue<int> firstHalf;

    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); firstHalf.pop();
        q.push(q.front()); q.pop();
    }
}

int main() {
    queue<int> q;
    int x;
    cout << "Enter even number of elements (end with -1): ";
    while (cin >> x && x != -1) q.push(x);

    interleave(q);
    cout << "Interleaved Queue: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << "\n";
}
