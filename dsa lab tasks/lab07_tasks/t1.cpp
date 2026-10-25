#include<iostream>
using namespace std;

int cnt=0;

void show(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl;
}

void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1,n2=r-m;
    int *x=new int[n1];
    int *y=new int[n2];

    for(int i=0;i<n1;i++)
        x[i]=a[l+i];

    for(int j=0;j<n2;j++)
        y[j]=a[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(x[i]<=y[j])
            a[k++]=x[i++];
        else
            a[k++]=y[j++];
    }

    while(i<n1)
        a[k++]=x[i++];

    while(j<n2)
        a[k++]=y[j++];

    cnt++;
    show(a,8);

    delete[] x;
    delete[] y;
}

void mergeSort(int a[],int l,int r)
{
    if(l>=r)
        return;

    int m=(l+r)/2;

    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
}

int main()
{
    int a[8]={78,45,92,63,45,88,51,70};

    mergeSort(a,0,7);

    cout<<"Sorted: ";
    show(a,8);

    cout<<"Merge operations: "<<cnt;

    return 0;
}