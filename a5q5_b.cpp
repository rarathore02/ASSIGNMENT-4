#include <iostream>
#include <queue>
using namespace std;

class Stack1Q {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) { cout << "Empty\n"; return; }
        cout << "Popped: " << q.front() << "\n";
        q.pop();
    }
    void top() { cout << (q.empty() ? -1 : q.front()) << "\n"; }
};

int main() {
    Stack1Q st;
    st.push(5); st.push(15);
    st.top();   // 15
    st.pop();   // pop 15
    st.top();   // 5
}
