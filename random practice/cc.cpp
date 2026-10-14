#include<iostream>
using namespace std;
class Student{
    public:
    int* age;

    Student(){
        age = nullptr;
        cout << "Default Constructor Called\n";
    }

    Student(int a){
        age = new int(a);
        cout << "paramatrized Constructor Called\n";
    }

    // for deep copy constructor
    Student(const Student& other){
        age = new int(*other.age);
    }


     ~Student(){
        delete age;
        cout << "Destructor called\n";
    }


};
int main(){
    Student s1; //default constructor called
    Student s2(20); // paramaterized called 
    // cout << s1.age << endl;
    // cout << *(s1.age) << endl;
    // Student s2 = s1;
    // cout << s2.age << endl;
    // cout << *(s2.age) << endl;
    // *(s1.age) = 50;
    // cout << *(s1.age) << endl;
    // cout << *(s2.age) << endl;
    Student* s4 = new Student(); // default constructor called
    cout << "Inside Main\n";
    delete s4; // s4 destroyed here



} // s1 and s2 are destroyed here
// Destructor called