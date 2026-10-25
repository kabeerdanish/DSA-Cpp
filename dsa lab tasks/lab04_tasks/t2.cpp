#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertEnd(Node*& head, int d)
{
    Node* n = new Node(d);

    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
}

void insertBeginning(Node*& head, int d)
{
    Node* n = new Node(d);

    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    n->next = head;
    temp->next = n;
    head = n;
}

void insertPosition(Node*& head, int d, int pos)
{
    if (pos <= 1)
    {
        insertBeginning(head, d);
        return;
    }

    if (head == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            cout << "Invalid position" << endl;
            return;
        }
    }

    Node* n = new Node(d);
    n->next = temp->next;
    temp->next = n;
}

void deleteNode(Node*& head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (pos <= 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
    {
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        Node* del = head;
        head = head->next;
        temp->next = head;

        delete del;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            cout << "Invalid position" << endl;
            return;
        }
    }

    if (temp->next == head)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;

    delete del;
}

void display(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;

    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    while (temp != head);

    cout << "HEAD" << endl;
}

int main()
{
    Node* head = NULL;
    int choice, x, pos;

    do
    {
        cout << "\n1. Insert at end";
        cout << "\n2. Insert at beginning";
        cout << "\n3. Insert at position";
        cout << "\n4. Delete node";
        cout << "\n5. Print list";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> x;
            insertEnd(head, x);
        }
        else if (choice == 2)
        {
            cout << "Enter value: ";
            cin >> x;
            insertBeginning(head, x);
        }
        else if (choice == 3)
        {
            cout << "Enter value: ";
            cin >> x;
            cout << "Enter position: ";
            cin >> pos;
            insertPosition(head, x, pos);
        }
        else if (choice == 4)
        {
            cout << "Enter position: ";
            cin >> pos;
            deleteNode(head, pos);
        }
        else if (choice == 5)
        {
            display(head);
        }

    }
    while (choice != 6);

    return 0;
}