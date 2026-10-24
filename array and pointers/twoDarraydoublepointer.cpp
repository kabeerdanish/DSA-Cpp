// Question

// Implement a safe dynamic 2D integer array class named atype using a double pointer (int**).

// Your class should support the following:

// Create a default constructor that initializes an empty array safely.

// Create a parameterized constructor that receives:

// number of rows
// number of columns

// and dynamically allocates the required 2D array.

// Create a destructor that correctly releases all dynamically allocated memory.
// Implement a member function:
// void fillArray()

// to input values into the 2D array.

// Overload the () operator so that an element can be accessed using:
// obj(row, column)

// The operator must perform bounds checking and report an error if an invalid index is supplied.

// Implement a copy constructor that performs a deep copy of another atype object.
// Overload the assignment operator = so that assignment between two objects performs a deep copy and handles self-assignment safely.
// In main():
// Take rows and columns from the user.
// Create one object using the parameterized constructor.
// Fill it with values.
// Create another object using the copy constructor.
// Create a third object with different dimensions and fill it.
// Access elements using the overloaded () operator.
// Test the bounds checking.


#include<iostream>
#include<cstring>
using namespace std;

class atype{
    private:
    int rows;
    int cols;
    int **arr;

    public:
    // Default constructor
    atype(){
        rows = 0;
        cols = 0;
        arr = nullptr;
    }

    // Parameterized constructor
    atype(int r, int c){
        rows = r;
        cols = c;
        arr = new int*[rows];
        for(int i=0; i<rows ; i++){
            arr[i] = new int[cols];
        }
    }
    
    // Destructor
    ~atype(){
        if(arr != nullptr){
            for(int i=0; i<rows; i++){
                delete [] arr[i];
            }
        delete[] arr;
        }
        arr = nullptr;
    }


    // Input
    void fillArray(){
        cout << "Enter elements for 2D array:"<<endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> arr[i][j];
            }
        }
    }

    
    // Operator () with bounds checking
    int &operator()(int r, int c){
        if(r<0 || r>=rows || c<0 || c>=cols){
            cout << "Index out of bound";
            exit(1);
        }
        return arr[r][c];
    }

    // Copy constructor - Deep Copy
    atype(const atype& other){
        rows = other.rows;
        cols = other.cols;
        arr = new int*[rows];
        for(int i=0; i<rows; i++){
            arr[i] = new int[cols];
            //memcpy(arr[i], other.arr[i], sizeof(int) * cols);
        }

        for(int i=0; i<rows; i++){ 
            for(int j=0; j<cols; j++){
                arr[i][j] = other.arr[i][j]; 
            }
        }

    }
    
    // Assignment operator - Deep Copy
    atype &operator=(const atype &other){
        if(this == &other){
            return *this;
        }

        for(int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;

        rows = other.rows;
        cols = other.cols;

        arr = new int*[rows];
        for(int i=0; i<rows; i++){
            arr[i] = new int[cols];
            memcpy(arr[i], other.arr[i], sizeof(int) * cols);
        }

        // for(int i=0; i<rows; i++){
        //     for(int j=0; j<cols; j++){
        //         arr[i][j] = other.arr[i][j];
        //     }
        // }

        return *this;

    }

};

int main(){
    int rows, cols;

    cout << "Enter rows and cols for 2D matrix or array: ";
    cin >> rows >> cols;

    atype a1(rows, cols);
    a1.fillArray();

    // Copy constructor
    atype obj2 = a1;

    // Third object with different dimensions
    atype a3(3, 3);
    a3.fillArray();

    // Valid access
    cout << a3(2,2) << endl;

    // Bounds checking
    cout << a3(3,3) << endl;

    return 0;
}
