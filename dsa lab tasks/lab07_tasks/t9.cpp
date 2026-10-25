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
    int cnt[10]={0},cum[10],out[12];

    for(int i=0;i<n;i++)
        cnt[(a[i]/exp)%10]++;

    for(int i=0;i<10;i++)
    {
        if(i==0)
            cum[i]=cnt[i];
        else
            cum[i]=cum[i-1]+cnt[i];
    }

    cout<<"Frequency: ";
    show(cnt,10);

    cout<<"Cumulative: ";
    show(cum,10);

    for(int i=n-1;i>=0;i--)
    {
        int d=(a[i]/exp)%10;
        out[--cum[d]]=a[i];
    }

    cout<<"Output: ";
    show(out,n);

    for(int i=0;i<n;i++)
        a[i]=out[i];

    cout<<"Copied back: ";
    show(a,n);
}

int main()
{
    int a[12]={4721,305,472,89,3005,721,1000,305,9999,42,870,100};

    cout<<"Original: ";
    show(a,12);

    int mx=a[0];

    for(int i=1;i<12;i++)
    {
        if(a[i]>mx)
            mx=a[i];
    }

    for(int e=1;mx/e>0;e*=10)
    {
        cout<<"Pass exp "<<e<<endl;
        countSort(a,12,e);
    }

    cout<<"Sorted: ";
    show(a,12);

    return 0;
}