#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    string course;
    string script;

    Student(){
        name = course = script = "0";
    }

    Student(string n, string c, string s){
        name = n;
        course = c;
        script = s;
    }
};

class Node{

    public:
    Student s1;
    Node* next;

    Node(Student s){
        s1 = s;
        next = nullptr;
    }
};

class stack{
    private:
    Node* top;

    public:
    stack(){
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    // void push(Student s) {

    //     Node* newNode = new Node(s);

    //     // New node becomes top
    //     newNode->next = top;
    //     top = newNode;
    // }

    void push(Node* &temp){
        if(top == nullptr){
            top = temp;
            return;
        }
        temp->next = top;
        top = temp;

    }

    // Student pop() {

    //     if (top == nullptr) {
    //         cout << "Stack Underflow!" << endl;
    //         return Student();
    //     }

    //     Node* temp = top;

    //     Student removedStudent = temp->s1;

    //     top = top->next;

    //     delete temp;

    //     return removedStudent;
    // }


    void display() {

        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;

        while (temp != nullptr) {

            cout << "Name: " << temp->s1.name << endl;
            cout << "Course: " << temp->s1.course << endl;
            cout << "Script: " << temp->s1.script << endl;
            cout << "-------------------" << endl;

            temp = temp->next;
        }
    }


};

class queue{
    private:
    Node* front;
    Node* rear;

    public:

    queue(){
        rear = front = nullptr;
    }

     bool isEmpty() {
        return front == nullptr;
    }

    void Enqeue(Student s){
        Node* newNode = new Node(s);
        if (front == nullptr){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void Deqeue(stack &ds, stack &coal, stack &das){
        if(front == nullptr){
            cout << "Underflow!" << endl;
            return;
        }
        Node* temp = front;
        // Save student before deleting node
        // Student removedStudent = temp->s1;
        front = front->next;
        temp->next = nullptr;

        

        if(temp->s1.course == "DS"){
            ds.push(temp);
        }else if (temp->s1.course == "COAL")
        {
            coal.push(temp);
        }else{
            das.push(temp);
        }

        if (front == nullptr) {
            rear = nullptr;
        }
        //  return removedStudent;
        

    }


    void display() {

    if(front == nullptr){
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;

    while(temp != nullptr){

        cout << "Name: " << temp->s1.name << endl;
        cout << "Course: " << temp->s1.course << endl;
        cout << "Script: " << temp->s1.script << endl;
        cout << "-------------------" << endl;

        temp = temp->next;
    }
}
};



    

int main(){

    // int n;
    // cout << "Enter number of students:";
    // cin >> n;

    queue q1;

    stack dsStack;
    stack coalStack;
    stack dataScienceStack;

    // for(int  i=0; i<n; i++){
    //     Student s;
    //     cout << "\nEnter student " << i+1 << " name :";
    //     cin >> s.name;
    //     cout << "Enter student " << i+1 << " course :";
    //     cin >> s.course;
    //     cout << "Enter student " << i+1 << " answer script :";
    //     cin >> s.script;
    //     q1.Enqeue(s);
    // }

    q1.Enqeue(Student("Ali", "DS", "DS_Script_1"));
    q1.Enqeue(Student("Ahmed", "DSCI", "DSCI_Script_1"));
    q1.Enqeue(Student("Hassan", "COAL", "COAL_Script_1")); 
    q1.Enqeue(Student("Usman", "DS", "DS_Script_2"));
    q1.Enqeue(Student("Bilal", "COAL", "COAL_Script_2"));
    q1.Enqeue(Student("Hamza", "DSCI", "DSCI_Script_2"));

    cout << "\n\n========== QUEUE ==========\n";
    q1.display(); 

    while(!q1.isEmpty()){
        q1.Deqeue(dsStack, coalStack, dataScienceStack);
    }
    cout << "\n\n========== DS STACK ==========\n";
    dsStack.display();

    cout << "\n\n========== COAL STACK ==========\n";
    coalStack.display();

    cout << "\n\n========== DATA SCIENCE STACK ==========\n";
    dataScienceStack.display();

    //   while (!q1.isEmpty()) {

    //     Student s = q1.dequeue();


    //     if (s.course == "DS") {

    //         dsStack.push(s);

    //     }
    //     else if (s.course == "COAL") {

    //         coalStack.push(s);

    //     }
    //     else if (s.course == "DSCI") {

    //         dataScienceStack.push(s);

    //     }
    //     else {

    //         cout << "Invalid course for "
    //              << s.name << endl;
    //     }
    // }

    
    
   
}

