#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10,20,30,40,5,50,60,70};
    int n = 8;

    int gap = n;
    bool swapped = true;

    while(gap != 1 || swapped)
    {
        gap = gap / 1.3;

        if(gap < 1)
            gap = 1;

        swapped = false;

        cout << "gap = " << gap << ": ";

        for(int i = 0; i + gap < n; i++)
        {
            if(arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;

                swapped = true;
            }
        }

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    cout << endl;
    cout << "sorted array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}