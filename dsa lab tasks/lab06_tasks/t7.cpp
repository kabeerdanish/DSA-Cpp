#include<iostream>
using namespace std;

int a[5]={2,3,5,6,8};
int sub[5];
bool found=false;

void solve(int i,int s,int cnt)
{
    if(s==9)
    {
        found=true;

        for(int j=0;j<cnt;j++)
            cout<<sub[j]<<" ";

        cout<<endl;
        return;
    }

    if(i==5 || s>9)
        return;

    sub[cnt]=a[i];
    solve(i+1,s+a[i],cnt+1);

    solve(i+1,s,cnt);
}

int main()
{
    solve(0,0,0);

    if(!found)
        cout<<"No subset found";

    return 0;
}