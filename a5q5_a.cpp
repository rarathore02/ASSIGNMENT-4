#include <iostream>
#include <queue>
using namespace std;

class Stack2Q {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) { cout << "Empty\n"; return; }
        cout << "Popped: " << q1.front() << "\n";
        q1.pop();
    }
    void top() { cout << (q1.empty() ? -1 : q1.front()) << "\n"; }
};

int main() {
    Stack2Q st;
    st.push(10); st.push(20);
    st.top();    // 20
    st.pop();    // pop 20
    st.top();    // 10
}
