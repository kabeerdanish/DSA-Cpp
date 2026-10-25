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

void insert(Node*& head, int d)
{
    Node* n = new Node(d);

    if (head == NULL)
    {
        head = n;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

void modify(Node*& head)
{
    Node* eh = NULL;
    Node* et = NULL;
    Node* oh = NULL;
    Node* ot = NULL;
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (eh == NULL)
            {
                eh = temp;
                et = temp;
            }
            else
            {
                et->next = temp;
                et = temp;
            }
        }
        else
        {
            if (oh == NULL)
            {
                oh = temp;
                ot = temp;
            }
            else
            {
                ot->next = temp;
                ot = temp;
            }
        }

        temp = temp->next;
    }

    if (eh == NULL)
        head = oh;
    else
    {
        head = eh;
        et->next = oh;
    }

    if (ot != NULL)
        ot->next = NULL;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(head, x);
    }

    cout << "Input: ";
    display(head);

    modify(head);

    cout << "Output: ";
    display(head);

    return 0;
}