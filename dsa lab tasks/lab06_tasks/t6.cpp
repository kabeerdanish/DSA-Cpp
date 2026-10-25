#include<iostream>
using namespace std;

int maze[4][4]={
    {1,1,0,0},
    {0,1,1,0},
    {0,0,1,1},
    {0,0,0,1}
};

int path[4][4]={0};

bool solve(int r,int c)
{
    if(r<0 || c<0 || r>=4 || c>=4 || maze[r][c]==0)
        return false;

    path[r][c]=1;

    if(r==3 && c==3)
        return true;

    if(solve(r,c+1))
        return true;

    if(solve(r+1,c))
        return true;

    path[r][c]=0;
    return false;
}

int main()
{
    if(solve(0,0))
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
                cout<<path[i][j]<<" ";

            cout<<endl;
        }
    }
    else
        cout<<"No path found";

    return 0;
}