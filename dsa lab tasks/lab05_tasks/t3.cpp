
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

using Queue = queue<string>;

void reverseFirstK(Queue &q, int k) {
    if (k <= 0 || k > (int)q.size())
        return;

    stack<string> s;
    int n = q.size();

    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    Queue q;

    for (int i = 1; i <= 7; i++)
        q.push("J" + to_string(i));

    reverseFirstK(q, 3);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
