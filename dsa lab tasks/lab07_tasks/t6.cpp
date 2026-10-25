#include<iostream>
using namespace std;

void show(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl;
}

void pass(int a[],int n,int exp)
{
    int freq[10]={0},cum[10],out[7];

    for(int i=0;i<n;i++)
        freq[(a[i]/exp)%10]++;

    for(int i=0;i<10;i++)
    {
        if(i==0)
            cum[i]=freq[i];
        else
            cum[i]=cum[i-1]+freq[i];
    }

    cout<<"Frequency: ";
    show(freq,10);

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
}

int main()
{
    int a[7]={329,457,657,839,436,720,355};

    for(int e=1;e<=100;e*=10)
    {
        pass(a,7,e);

        cout<<"Copied back: ";
        show(a,7);
    }

    return 0;
}