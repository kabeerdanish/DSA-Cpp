#include<iostream>
using namespace std;

int power(int a, int b){ // recursively
    if (b == 0) return 1;
    return a*power(a,b-1);
}

int powerI(int a, int b){ // iteratively
    int c = 1;
    if(b == 0) return 1;
    for(int i=1; i<=b; i++){
        c = c*a;
    }
    return c;
}

int powerDC(int a, int b){ // divide and conquer divide in to half size or power
    if(b == 0) return 1;
    if(b % 2 == 0) return powerDC(a, b/2) * powerDC(a, b/2);
    return a * powerDC(a, b/2) * power(a, b/2);
}





int multiply(int a, int b){
    if(a == 0 || b == 0) return 0;
    return a + multiply(a, b-1);
}

int powerWithoutOperator(int a, int b){
    if(b == 0) return 1;
    return multiply(powerWithoutOperator(a,b-1), a);
     // int result = 0;
    // result = multiply(3,3);

    // for(int i=2; i<3; i++){
    
    //     result = multiply(result,3);

    //     }
    
    // cout << result << endl;
}




int main(){
    cout << power(2, 5) << endl;
    cout << powerI(2, 5) << endl;
    cout << powerWithoutOperator(3, 3) << endl;
    

}