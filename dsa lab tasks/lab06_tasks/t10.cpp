#include<iostream>
#include<string>
using namespace std;

char grid[3][3]={
    {'C','A','T'},
    {'X','A','X'},
    {'X','X','X'}
};

bool vis[3][3]={false};
string word="CAT";

bool search(int r,int c,int i)
{
    if(i==(int)word.length())
        return true;

    if(r<0 || c<0 || r>=3 || c>=3)
        return false;

    if(vis[r][c] || grid[r][c]!=word[i])
        return false;

    vis[r][c]=true;

    if(search(r+1,c,i+1) ||
       search(r-1,c,i+1) ||
       search(r,c+1,i+1) ||
       search(r,c-1,i+1))
        return true;

    vis[r][c]=false;
    return false;
}

int main()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(search(i,j,0))
            {
                cout<<"Word found";
                return 0;
            }
        }
    }

    cout<<"Word not found";
    return 0;
}