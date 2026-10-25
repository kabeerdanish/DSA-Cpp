
#include <iostream>
using namespace std;

class CQueue {
    int a[6];
    int front, rear, cnt;

public:
    CQueue() {
        front = rear = -1;
        cnt = 0;
    }

    void enqueue(int x) {
        if (cnt == 6) {
            cout << "Queue is full\n";
            return;
        }

        if (cnt == 0)
            front = 0;

        rear = (rear + 1) % 6;
        a[rear] = x;
        cnt++;
    }

    void board() {
        if (cnt == 0) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Boarded: " << a[front] << endl;

        if (cnt == 1)
            front = rear = -1;
        else
            front = (front + 1) % 6;

        cnt--;
    }

    void display() {
        cout << "Final passengers: ";

        for (int i = 0; i < cnt; i++)
            cout << a[(front + i) % 6] << " ";

        cout << "\nFront position: " << front;
        cout << "\nRear position: " << rear << endl;
    }
};

int main() {
    CQueue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    q.board();
    q.board();
    q.board();

    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    q.board();
    q.board();

    q.enqueue(110);

    q.board();

    q.enqueue(111);
    q.enqueue(112);

    q.display();

    return 0;
}
