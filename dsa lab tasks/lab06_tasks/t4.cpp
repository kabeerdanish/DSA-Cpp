#include<iostream>
using namespace std;

int money(int n)
{
    if(n==1)
        return 10;

    return 2*money(n-1);
}

int main()
{
    int n;
    cin>>n;

    if(n<1)
        cout<<"Invalid day";
    else
        cout<<"Rs. "<<money(n);

    return 0;
}