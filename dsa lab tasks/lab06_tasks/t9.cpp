#include<iostream>
using namespace std;

int a[4][4]={
    {1,0,0,4},
    {0,4,1,0},
    {0,1,4,0},
    {4,0,0,1}
};

bool safe(int r,int c,int n)
{
    for(int i=0;i<4;i++)
    {
        if(a[r][i]==n || a[i][c]==n)
            return false;
    }

    int sr=(r/2)*2;
    int sc=(c/2)*2;

    for(int i=sr;i<sr+2;i++)
    {
        for(int j=sc;j<sc+2;j++)
        {
            if(a[i][j]==n)
                return false;
        }
    }

    return true;
}

bool solve()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(a[i][j]==0)
            {
                for(int n=1;n<=4;n++)
                {
                    if(safe(i,j,n))
                    {
                        a[i][j]=n;

                        if(solve())
                            return true;

                        a[i][j]=0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main()
{
    if(solve())
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
                cout<<a[i][j]<<" ";

            cout<<endl;
        }
    }
    else
        cout<<"No solution found";

    return 0;
}