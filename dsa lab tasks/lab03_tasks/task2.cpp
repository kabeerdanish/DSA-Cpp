#include <iostream>
using namespace std;

int main()
{
    int arr[] = {55,61,67,72,78,81,80,85};
    int n = 8;

    int comparisons = 0;
    int swaps = 0;
    int passes = 0;

    for(int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for(int j = 0; j < n - 1 - i; j++)
        {
            comparisons++;

            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
                swapped = true;
            }
        }

        passes++;

        cout << "pass " << passes << ": ";

        for(int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }

        cout << endl;

        if(swapped == false)
        {
            break;
        }
    }

    cout << endl;
    cout << "passes = " << passes << endl;
    cout << "comparisons = " << comparisons << endl;
    cout << "swaps = " << swaps << endl;

    cout << "standard bubble sort passes = " << n - 1 << endl;
    cout << "standard bubble sort comparisons = " << (n * (n - 1)) / 2 << endl;

    return 0;
}