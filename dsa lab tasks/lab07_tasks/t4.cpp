#include<iostream>
using namespace std;

int parts=0;

void show(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl;
}

int partition(int a[],int l,int r)
{
    int p=a[r],i=l-1;

    cout<<"Pivot "<<p<<", bounds "<<l<<" to "<<r<<endl;

    for(int j=l;j<r;j++)
    {
        if(a[j]<=p)
        {
            i++;

            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }

    int t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;

    parts++;
    show(a,7);

    return i+1;
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
    int a[7]={40,20,70,10,60,30,50};

    quickSort(a,0,6);

    cout<<"Partition operations: "<<parts;

    return 0;
}