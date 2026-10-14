#include<iostream>
using namespace std;
int main(){
    int n = 986;
    int nu = n;
    int c = 0;
    for(int i=0; n>0; i++){
        c++;
        n = n/10;
    }
    cout << c << endl;






    int div = 1;
   
    for(int i = 0; i<c-1 ; i++){
        div = div * 10;
    }
    cout << div << endl;
    cout << nu/div;

}