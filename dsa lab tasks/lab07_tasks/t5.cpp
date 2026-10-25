#include<iostream>
using namespace std;

int cmp=0;

void show(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl;
}

int partition(int a[],int l,int r)
{
    int p=a[l],i=l+1,j=r;

    cout<<"Pivot: "<<p<<endl;

    while(true)
    {
        while(i<=r)
        {
            cmp++;

            if(a[i]>p)
                break;

            i++;
        }

        while(j>l)
        {
            cmp++;

            if(a[j]<=p)
                break;

            j--;
        }

        if(i>=j)
            break;

        int t=a[i];
        a[i]=a[j];
        a[j]=t;

        i++;
        j--;
    }

    int t=a[l];
    a[l]=a[j];
    a[j]=t;

    show(a,7);

    return j;
}

void quickSort(int a[],int l,int r)
{
    if(l<r)
    {
        int p=partition(a,l,r);

        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}

int main()
{
    int a[7]={55,25,75,15,65,35,45};

    quickSort(a,0,6);

    cout<<"Sorted: ";
    show(a,7);

    cout<<"Comparisons: "<<cmp;

    return 0;
}