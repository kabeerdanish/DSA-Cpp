
#include <iostream>
using namespace std;

class Stack {
    int a[8];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 7) {
            cout << "Stack is full\n";
            return;
        }
        a[++top] = x;
        show();
    }

    void undo() {
        if (top == -1) {
            cout << "Stack is empty, nothing to undo\n";
        } else {
            top--;
        }
        show();
    }

    void show() {
        if (top == -1)
            cout << "Current top: Empty\n";
        else
            cout << "Current top: " << a[top] << endl;
    }

    void display() {
        cout << "Stack from top to bottom: ";
        for (int i = top; i >= 0; i--)
            cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(12);
    s.push(25);
    s.push(17);
    s.push(31);
    s.push(44);
    s.push(19);

    s.undo();
    s.undo();
    s.undo();

    s.push(52);

    s.undo();
    s.undo();

    s.display();

    Stack s2;
    cout << "\nTesting undo on an empty stack:\n";
    s2.undo();

    return 0;
}
