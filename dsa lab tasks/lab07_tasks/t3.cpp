#include<iostream>
using namespace std;

long long calls=0,merges=0,cmp=0;
int *tmp;

void merge(int a[],int l,int m,int r)
{
    int i=l,j=m+1,k=l;

    while(i<=m && j<=r)
    {
        cmp++;

        if(a[i]<=a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++]=a[j++];
    }

    while(i<=m)
        tmp[k++]=a[i++];

    while(j<=r)
        tmp[k++]=a[j++];

    for(i=l;i<=r;i++)
        a[i]=tmp[i];

    merges++;
}

void mergeSort(int a[],int l,int r)
{
    calls++;

    if(l>=r)
        return;

    int m=(l+r)/2;

    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
}

int main()
{
    int n;
    cin>>n;

    if(n<=0)
    {
        cout<<"Invalid size";
        return 0;
    }

    int *a=new int[n];
    tmp=new int[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    mergeSort(a,0,n-1);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl<<"Recursive calls: "<<calls;
    cout<<endl<<"Merge operations: "<<merges;
    cout<<endl<<"Comparisons: "<<cmp;

    delete[] a;
    delete[] tmp;

    return 0;
}