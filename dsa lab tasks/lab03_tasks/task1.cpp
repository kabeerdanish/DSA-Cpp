#include <iostream>
using namespace std;

int main()
{
    int arr[] = {45, 12, 78, 34, 23, 90};
    int n = 6;

    int comparisons = 0;
    int swaps = 0;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            comparisons++;

            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
            }
        }

        cout << "pass " << i + 1 << ": ";

        for(int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }

        cout << endl;
    }

    cout << endl;
    cout << "total passes = " << n - 1 << endl;
    cout << "total comparisons = " << comparisons << endl;
    cout << "total swaps = " << swaps << endl;

    return 0;
}