#include<iostream>
#include<string>
using namespace std;

void rev(string s,int i)
{
    if(i<0)
        return;

    cout<<s[i];
    rev(s,i-1);
}

int main()
{
    string s;
    getline(cin,s);

    if(!s.empty())
        rev(s,(int)s.length()-1);

    return 0;
}