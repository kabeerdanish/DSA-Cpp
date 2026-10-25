#include<iostream>
#include<string>
using namespace std;

int g[4][4]={
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,1},
    {0,1,1,0}
};

int col[4]={0};
string names[3]={"Red","Green","Blue"};
char ver[4]={'A','B','C','D'};

bool safe(int v,int c)
{
    for(int i=0;i<4;i++)
    {
        if(g[v][i] && col[i]==c)
            return false;
    }
    return true;
}

bool solve(int v)
{
    if(v==4)
        return true;

    for(int c=1;c<=3;c++)
    {
        if(safe(v,c))
        {
            col[v]=c;

            if(solve(v+1))
                return true;

            col[v]=0;
        }
    }

    return false;
}

int main()
{
    if(solve(0))
    {
        for(int i=0;i<4;i++)
            cout<<ver[i]<<" : "<<names[col[i]-1]<<endl;
    }
    else
        cout<<"No valid coloring";

    return 0;
}