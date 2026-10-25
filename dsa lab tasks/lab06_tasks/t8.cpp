#include<iostream>
using namespace std;

char a[4]={'A','B','C','D'};
char ans[4];
bool used[4]={false};

void perm(int pos)
{
    if(pos==4)
    {
        for(int i=0;i<4;i++)
            cout<<ans[i];

        cout<<endl;
        return;
    }

    for(int i=0;i<4;i++)
    {
        if(!used[i])
        {
            used[i]=true;
            ans[pos]=a[i];

            perm(pos+1);

            used[i]=false;
        }
    }
}

int main()
{
    perm(0);
    return 0;
}