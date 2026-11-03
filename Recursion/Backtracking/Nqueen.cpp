#include<iostream>
using namespace std;


// I am keeping these for our dedicated practice session:
// 1. Dry-run the entire recursion tree, including failed branches.
// 2. Identify and correct bugs in isSafe().
// 3. N = 1, 2, 3, 4 and larger boards.
// 4. Print all solutions, not just one.
// 5. Count the total number of solutions.
// 6. Understand why checking only the left side works.
// 7. Place queens row by row instead of column by column.
// 8. Given a partially filled board, determine whether a valid arrangement is possible.
// 9. Find the exact backtracking step in a given code trace.
// 10. Write the full solution from a problem statement without looking at a template.
const int N = 4;

// 0 empty cell , 1 queen placed
int board[N][N] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

bool isSafe(int r, int c){

    // Check same row on the left
    for(int i=0; i<c; i++){
        if(board[r][i]) return false;
    }

     // Check upper-left diagonal
    for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--){
        if(board[i][j]) return false;
    }

    // Check lower-left diagonal
    for(int i=r+1, j=c-1; i<N && j>=0; i++, j--){
        if(board[i][j]) return false;
    }

    return true;

}

bool solveNqueen(int c){

    // Base case: all columns are filled
    if(c >= N) return true;

    // Try every row in this column
    for(int i=0; i<N; i++){

        if(isSafe(i, c)){

            // Place queen
            board[i][c] = 1;

            // Solve the next column
            if(solveNqueen(c+1)){
                return true;
            }

            // Backtrack: remove queen
            board[i][c] = 0;
        }
    }

    // No row worked in this column
    return false;
}

void printSolution(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    if(solveNqueen(0)){
        cout << "Solution Found:\n";
        printSolution();
    }else{
        cout << "Solution does not exist.\n";
    }
}
