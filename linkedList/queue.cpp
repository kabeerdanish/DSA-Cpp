#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Queue{
    Node* front;
    Node* rear;

    public:

    Queue(){
        front = rear = nullptr;
    }

    void Enqeue(int val){
        Node* newNode = new Node(val);
        if(front == nullptr){
            front = rear = newNode;
        }
        rear->next = newNode; 
        rear = newNode;
    }

    void Dequeue(){
        if(front == nullptr){
            cout << "The queue is empty!" << endl;
        }
        Node* temp = front;
        front = front->next;
        temp->next = nullptr;
        delete temp;
    }

    void printFront(){
        if(front == nullptr){
            cout << "The queue is empty!" << endl;
        }
        cout << front->data << endl;
    }

    void printRear(){
        if(front == nullptr){
            cout << "The queue is empty!" << endl;
        }
        cout << rear->data << endl;

    }

    
};