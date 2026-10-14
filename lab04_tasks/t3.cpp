#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void insertEnd(Node*& head, int x)
{
    Node* n = new Node(x);

    if (head == NULL)
    {
        head = n;
        n->next = head;
        n->prev = head;
        return;
    }

    Node* last = head->prev;

    n->next = head;
    n->prev = last;
    last->next = n;
    head->prev = n;
}

void insertBegin(Node*& head, int x)
{
    Node* n = new Node(x);

    if (head == NULL)
    {
        head = n;
        n->next = head;
        n->prev = head;
        return;
    }

    Node* last = head->prev;

    n->next = head;
    n->prev = last;
    last->next = n;
    head->prev = n;
    head = n;
}

void insertPos(Node*& head, int x, int pos)
{
    if (pos <= 1)
    {
        insertBegin(head, x);
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

    Node* n = new Node(x);
    Node* next = temp->next;

    n->prev = temp;
    n->next = next;
    temp->next = n;
    next->prev = n;
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

    Node* temp = head;

    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            cout << "Invalid position" << endl;
            return;
        }
    }

    if (temp->next == head && temp->prev == head)
    {
        delete temp;
        head = NULL;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == head)
        head = temp->next;

    delete temp;
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
        cout << temp->data << "<->";
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
            insertBegin(head, x);
        }
        else if (choice == 3)
        {
            cout << "Enter value: ";
            cin >> x;
            cout << "Enter position: ";
            cin >> pos;
            insertPos(head, x, pos);
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