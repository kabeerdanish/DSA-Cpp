// 1. 2D Array using a single pointer

// Write a C++ class that represents a dynamically allocated 2D integer array using one int* pointer.

// It should include:

// Number of rows and columns
// Dynamic allocation using new
// Destructor
// Input and display functions
// Overloaded () operator for array(row, column) access with bounds checking
// Deep copy constructor
// Copy assignment operator with self-assignment checking
// Store the 2D data in contiguous 1D memory and calculate the offset for (row, column)

#include<iostream>
#include<cstdlib>
using namespace std;

class twoDarray{
    private:
    int rows;
    int cols;
    int* parr;
    static int count;

    public:

    twoDarray(){
        rows = 0;
        cols = 0;
        parr = nullptr; 
    }

    twoDarray(int r, int c){
        rows = r;
        cols = c;
        parr = new int[rows*cols];
    }


    ~twoDarray(){
        delete[] parr;
        parr = NULL;
    }

    void input(){
        cout << "Enter elements for integer array: \n";
        for(int i=0; i<rows*cols; i++){
            cout << "Enter element " << i+1 << ": ";
            cin >> parr[i];
        }
    }

    void display(){
        int temp = cols;
        cout << "The elements in the given array are: \n";
        for(int i=0; i<rows*cols; i++){
             cout << parr[i] << " ";
             if(i == (temp-1)){
                 cout << endl;
                 temp += cols;
             }
        
        }
    }

    // operator()  overloading
    int &operator()(int r, int c){
        if(r<0 && r>=rows && c<0 && c>=cols){ // miss used rows-1 and also for cols-1
            cout << "Index out of bound!" <<endl;
            exit(1);
        }
        int idx = r*cols+ c; 
        return parr[idx];

    }

    
    // copy constructor deep copy
    twoDarray(const twoDarray& other){
        this->rows = other.rows;
        this->cols = other.cols;
        this->parr = new int[rows*cols];

        // memcpy(dynamicarray,ob.dynamicarray,sizeof(int)*nrows*ncols);
         for(int i=0; i<rows*cols; i++){ 
            this->parr[i] = other.parr[i] ;  
         }

    }
    
    // copy assignment operator
    twoDarray& operator = (const twoDarray &other){

         if(this==&other) return *this;
        
        // proper deletion of existing memory
        delete[] parr; 
        parr = NULL;

        // deep copying
        rows = other.rows;
        cols = other.cols;
        parr = new int[rows*cols];  //memcpy(arr,other.arr,sizeof(int)*ncols);

        for(int i=0; i<rows*cols; i++){
            parr[i] = other.parr[i];
        }

        return *this;
        

    }

};
int twoDarray::count = 0;

int main(){
    twoDarray a1(3,4);
    a1.input();
    a1.display();
    
}