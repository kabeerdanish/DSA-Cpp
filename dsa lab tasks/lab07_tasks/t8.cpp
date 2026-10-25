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
    int out[8],cnt[10]={0};

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
    int a[8]={94,802,7,1234,56,321,405,18};
    int mx=a[0];

    for(int i=1;i<8;i++)
    {
        if(a[i]>mx)
            mx=a[i];
    }

    int passes=0;

    for(int e=1;mx/e>0;e*=10)
    {
        countSort(a,8,e);
        show(a,8);
        passes++;
    }

    cout<<"Total passes: "<<passes;

    return 0;
}