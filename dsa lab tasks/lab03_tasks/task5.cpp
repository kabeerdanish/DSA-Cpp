#include <iostream>
using namespace std;

int main()
{
    int n;

    while(true)
    {
        cout << "enter number of students (5-15): ";
        cin >> n;

        if(n >= 5 && n <= 15)
        {
            break;
        }

        cout << "invalid number. enter a value between 5 and 15." << endl;
    }

    int marks[15];

    for(int i = 0; i < n; i++)
    {
        while(true)
        {
            cout << "enter marks for student " << i + 1 << " (0-100): ";
            cin >> marks[i];

            if(marks[i] >= 0 && marks[i] <= 100)
            {
                break;
            }

            cout << "invalid marks. enter marks between 0 and 100." << endl;
        }
    }

    int comparisons = 0;
    int shifts = 0;

    for(int i = 1; i < n; i++)
    {
        int key = marks[i];
        int j = i - 1;

        while(j >= 0)
        {
            comparisons++;

            if(marks[j] < key)
            {
                marks[j + 1] = marks[j];
                shifts++;
                j--;
            }
            else
            {
                break;
            }
        }

        marks[j + 1] = key;
    }

    int highest = marks[0];
    int lowest = marks[n - 1];

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += marks[i];
    }

    double average = (double)sum / n;

    cout << endl;
    cout << "total comparisons = " << comparisons << endl;
    cout << "total shifts = " << shifts << endl;

    cout << "highest marks = " << highest << endl;
    cout << "lowest marks = " << lowest << endl;
    cout << "average marks = " << average << endl;

    cout << "sorted marks: ";

    for(int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;

    bool highAchiever = false;

    for(int i = 0; i < n; i++)
    {
        if(marks[i] >= 90)
        {
            highAchiever = true;
            break;
        }
    }

    if(highAchiever)
    {
        cout << "High Achiever(s) Present" << endl;
    }
    else
    {
        cout << "No High Achiever" << endl;
    }

    return 0;
}

