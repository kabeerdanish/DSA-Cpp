// Write a C++ program that:

// Creates an integer array of size 10.
// Takes 10 elements from the user.
// Displays all elements of the array.
// Calculates and displays the total/sum of all elements.
// Calculates and displays the average of the elements.
// Finds and displays the highest element in the array.


// #include<iostream>
// using namespace std;
// int main(){
//     int arr[10];
//     int sum = 0;
//     int length = sizeof(arr)/sizeof(int);
//     cout << "The length of array is : " << length << endl;
//     cout << "Enter elements for the array(Integers): " << endl; 
//     int highest;
//     for(int i=0; i<length; i++){
//         cout << "Enter elements " << i+1 << " at index (" << i << "): ";
//         cin >> arr[i];
//         sum += arr[i];
//         if(i==0 || arr[i] > highest) highest = arr[i];

//     }
//     cout << "The elements in the array of integers are: ";
//     for(int value : arr){
//         cout << value << " ";
//     }

//     cout << "\nThe sum of all values in the array is: " << sum << endl;
//     double avg = double(sum/length);
//     cout << "The average of these values is: " << avg << endl;
//     cout << "The highest element in the array is: " << highest << endl;
//}

// Write a C++ program to maintain the attendance record of 4 students over 5 days using a two-dimensional array.

// The program should:

// Accept attendance data where 1 represents Present and 0 represents Absent.
// Display the complete attendance record for all students.
// Calculate and display the number of days each student was present.

#include<iostream>
using namespace std;


int main(){
    int Attendance[4][5];
    int rows = sizeof(Attendance)/sizeof(Attendance[0]);
    int cols = sizeof(Attendance[0])/sizeof(Attendance[0][0]);

    cout << "***Enter attendance for 4 students for 5 days:***" << endl;
    cout << "***Enter 1 for Present and 0 for Absent***" << endl;

    for(int i=0; i<rows; i++){
        cout << "Student " << i+1 << ": "<< endl;
        for(int j=0; j<cols; j++){
            do{
            cout << "Day " << j+1 << ": ";
            cin >> Attendance[i][j];

            if(Attendance[i][j] !=0 && Attendance[i][j] != 1){
                 cout << "Invalid input! Please enter only 1 or 0.\n";
            }

            }while (Attendance[i][j] !=0 && Attendance[i][j] != 1);
            
        }
    }

    cout << "\nAttendance Record:";
    cout << "\n**********************************\n";
    cout << "           ";
    for(int j=0; j<cols; j++){
        cout << "Day " << j+1 << "  |  ";
    }

    for(int i=0; i<rows; i++){
        cout << "\nStudent " << i+1 << "    " ;
        for(int j=0; j<cols; j++){
            cout << Attendance[i][j] << "  " << "  |    ";
        }
    }
    cout << "\n**********************************\n";


    for(int i=0; i<rows; i++){
        int present = 0;
        for(int j=0; j<cols; j++){
            if(Attendance[i][j] == 1) present++;
        }
        cout << "Student " << i + 1 << ": " << present << " days" << endl;
    }
}