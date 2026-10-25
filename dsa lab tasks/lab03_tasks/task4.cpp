#include <iostream>
using namespace std;

int main()
{
    int arr[] = {90,20,80,30,70,40,60,50,10};
    int n = 9;

    int totalComparisons = 0;
    int totalShifts = 0;

    for(int gap = n / 2; gap >= 1; gap = gap / 2)
    {
        int comparisons = 0;
        int shifts = 0;

        for(int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while(j >= gap)
            {
                comparisons++;

                if(arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                    shifts++;
                    j = j - gap;
                }
                else
                {
                    break;
                }
            }

            arr[j] = temp;
        }

        totalComparisons += comparisons;
        totalShifts += shifts;

        cout << "gap = " << gap << endl;

        cout << "array: ";
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
        cout << "comparisons = " << comparisons << endl;
        cout << "shifts = " << shifts << endl;
        cout << endl;
    }

    cout << "total comparisons = " << totalComparisons << endl;
    cout << "total shifts = " << totalShifts << endl;

    return 0;
}
