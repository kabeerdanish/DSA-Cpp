#include<iostream>
using namespace std;

void show(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl;
}

void countSort(int a[],int n,int exp)
{
    int out[7],cnt[10]={0};

    for(int i=0;i<n;i++)
        cnt[(a[i]/exp)%10]++;

    for(int i=1;i<10;i++)
        cnt[i]+=cnt[i-1];

    for(int i=n-1;i>=0;i--)
    {
        int d=(a[i]/exp)%10;
        out[--cnt[d]]=a[i];
    }

    for(int i=0;i<n;i++)
        a[i]=out[i];
}

int main()
{
    int a[7]={91,8,1024,56,305,7,120};
    int mx=a[0];

    for(int i=1;i<7;i++)
    {
        if(a[i]>mx)
            mx=a[i];
    }

    for(int e=1;mx/e>0;e*=10)
    {
        countSort(a,7,e);
        show(a,7);
    }

    return 0;
}