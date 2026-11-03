#include<iostream>
using namespace std;


// Maze with only Right and Down allowed.

// Maze with four directions and multiple possible paths.

// Print all possible paths rather than just the first.

// Count the number of paths.

// Find the shortest path.

// Maze with a different start and destination.

// Maze with larger dimensions and obstacles.

// Debug a faulty backtracking implementation.

const int n = 4;

int maze[n][n] = {
    {1, 0, 0, 0}, 
    {1, 1, 0, 1}, 
    {0, 1, 0, 0},
    {1, 1, 1, 1}
};

int path[n][n] = {0};
int visited[n][n] = {0};

void printPath(){
    cout << "Path:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int r, int c){

    // check boundaries
    if(r<0 || r>=n || c<0 || c>=n ) return false;

    // Check blocked cell
    if(maze[r][c] == 0) return false;

    // check previously visited cell
    if(visited[r][c] == 1) return false;

    return true;
}

bool solveMaze(int r, int c){

    // 1. Check whether this cell is valid
    if(!isSafe(r, c)) return false;

    // 2. Destination reached
    if(r == n-1 && c == n-1){
        path[r][c] = 1;
        return true;
    }

    // 3. Mark current cell
    path[r][c] = 1;
    visited[r][c] = 1;

    // 4. Try RIGHT
    if(solveMaze(r, c+1)) return true;

    // 5. Try DOWN
    if(solveMaze(r+1, c)) return true;

    // 6. Try LEFT
    if (solveMaze(r, c-1)) return true;

    // 7. Try UP
    if (solveMaze(r-1, c)) return true;

    // 8. No direction worked: backtrack
    path[r][c] = 0;
    return false;
}

int main(){
    if(solveMaze(0, 0)){
        cout << "Path Found!:\n";
        printPath();
    }else{
        cout << "No path exists.\n";
    }

}









