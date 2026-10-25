
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> in, out;

public:
    void enqueue(int x) {
        in.push(x);
    }

    int dequeue() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        if (out.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int x = out.top();
        out.pop();
        return x;
    }
};

int main() {
    MyQueue q;

    q.enqueue(1);
    q.enqueue(2);

    cout << char('A' + q.dequeue() - 1) << endl;

    q.enqueue(3);

    cout << char('A' + q.dequeue() - 1) << endl;
    cout << char('A' + q.dequeue() - 1) << endl;

    return 0;
}
