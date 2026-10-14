// Write a C++ class OneDArray that represents a dynamically allocated one-dimensional integer array.

// The class should:

// Store the number of elements and a dynamically allocated integer array.
// Provide:
// A default constructor
// A parameterized constructor that creates an array of the given size
// A destructor that properly releases the dynamic memory
// Implement a function to input elements into the array.
// Implement a function to display elements.
// Overload the [] operator to access elements with bounds checking.
// Implement a deep copy constructor.
// Implement a copy assignment operator with:
// self-assignment checking
// proper deletion of existing memory
// deep copying
// In main():
// Create two arrays of different sizes.
// Input and display their values.
// Assign one object to the other using =.
// Display the copied object.
// Change the original object's values.
// Display the copied object again to prove that deep copy was performed.


#include<iostream>
#include <cstdlib>
using namespace std;



// Store the number of elements and a dynamically allocated integer array.
class oneDarray{
    public:
    int ncols;  // no of elements
    int *arr;
    static int count;
    int arrayNumber;

    public:
    oneDarray(){ // default constructor
        ncols = 0;
        arr = nullptr;
    }

    // A parameterized constructor that creates an array of the given size
    oneDarray(int n){ 
        ncols = n;
        arr = new int[ncols];

        count++;
        arrayNumber = count;
    }

    // A destructor that properly releases the dynamic memory
    ~oneDarray(){   // destructor
        cout << "Destructor called\n";
        delete[] arr;
        arr = NULL;
    }

    // Implement a function to input elements into the array.
    void input(){ 
        cout << "Enter elements for array " << arrayNumber << ":\n";
        for(int i=0; i<ncols; i++){
            int value;
            cout << "Enter the element  " << i+1 << ": "; 
            cin >> value;
            arr[i] = value;
        }
    }

    // Implement a function to display elements.
    void display(){ 
        cout << "The elements in the array " << arrayNumber << ": ";
        for(int i=0; i<ncols; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

   // Overload the [] operator to access elements with bounds checking.
   int &operator[](int idx){
        if(idx<0 || idx>ncols-1){
            cout << "Index out of bound!" << endl;
            exit(1);
        }
        return arr[idx];
   }

   // Implement a deep copy constructor.
   oneDarray(const oneDarray& other){
    ncols = other.ncols;
    arr = new int[other.ncols];  //memcpy(arr,other.arr,sizeof(int)*ncols);
    //you can also use for loop to copy the contents
    for(int i=0; i<ncols; i++){
        arr[i] = other.arr[i];
    }
   }
   
   // Implement a copy assignment operator with:
   oneDarray& operator= (const oneDarray& other){
        // self-assignment checking
        if(this==&other) return *this;
        
        // proper deletion of existing memory
        delete[] arr; 
        arr = NULL;

        // deep copying
        ncols = other.ncols;
        arr = new int[ncols];  //memcpy(arr,other.arr,sizeof(int)*ncols);

        for(int i=0; i<ncols; i++){
            arr[i] = other.arr[i];
        }

        return *this;
   }
};
int oneDarray::count = 0;

// void input(oneDarray &obj){
//     for(int i=0; i<obj.ncols; i++){
//         cout << "Enter the element  " << i+1 << ": "; 
//         cin >> obj.arr[i];
//     }

int main(){

    // Create two arrays of different sizes.
    oneDarray a1(3);
    oneDarray a2(2);
    

    // Input and display their values.
    a1.input();
    a2.input();

    cout << "\n************************\n";

    a1.display();
    a2.display();

    cout << "************************\n";

    cout << "\nAssigning obj1 to obj2..." << endl;

    cout << "************************\n";
    // Assign one object to the other using =.
    a2 = a1;

    // Display the copied object.
    a1.display();
    a2.display();

    cout << "************************\n";


    cout << "\nChange the values of obj1:" << endl;

    cout << "************************\n";
    // Change the original object's values --> Prove it's a DEEP copy
    a1.input();

    // Display the copied object again to prove that deep copy was performed.
    a1.display();
    a2.display();
    
    cout << "************************\n";

     return 0;
}