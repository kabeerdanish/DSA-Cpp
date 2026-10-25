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
    int cnt[10]={0},out[10];

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
    int a[10]={7314,314,731,34,3147,147,47,7314,4,314};

    cout<<"Original: ";
    show(a,10);

    int mx=a[0];

    for(int i=1;i<10;i++)
    {
        if(a[i]>mx)
            mx=a[i];
    }

    int passes=0;

    for(int e=1;mx/e>0;e*=10)
    {
        countSort(a,10,e);

        cout<<"After pass "<<passes+1<<": ";
        show(a,10);

        passes++;
    }

    cout<<"Maximum digit passes: "<<passes<<endl;
    cout<<"Sorted: ";
    show(a,10);

    return 0;
}