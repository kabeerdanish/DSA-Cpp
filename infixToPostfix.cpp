#include<iostream>
#include<stack>
#include<cctype>
#include<algorithm>
#include<cmath>
using namespace std;

int priority(char op){
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op){
    return op == '^';
}

string infixToPostfix(string s){
    stack<char> st;
    string post = "";
    int n = s.length();
    int i=0;

    while (i < n){
        if (isalnum(s[i])){
            post += s[i];
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                post += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(  !st.empty() && st.top() != '(' &&
                    (priority(st.top()) > priority(s[i]) ||
                    (priority(st.top()) == priority(s[i]) && isRightAssociative(s[i]))) //! for postfiz
                ){
                post += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while (!st.empty()){
        post += st.top();
        st.pop();
    }

    return post;

}

string infixToPrefix(string s){
    // reverse(s.begin(), s.end());
    string reversedS = "";
    for(int i=(s.length()-1); i>=0; i--){
        if (s[i] == '('){
             s[i] = ')';
        }
        else if (s[i] == ')') s[i] = '(';
        reversedS += s[i];
    }
    s = reversedS;
    cout << s << endl;
    string postFix = infixToPostfix(s);
    cout << postFix << endl;
    reverse(postFix.begin(), postFix.end());
    return postFix; // its actually prefix
}


int evaluatePostFix(string s){
    stack<int> st;
    int i=0;
    int n = s.length();

    while(i < n){
        if(isdigit(s[i])){
            st.push(s[i] - '0'); // convert char to digit
        }else{
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();

            switch(s[i]){
                case '+' : st.push(val1 + val2); break;
                case '-' : st.push(val1 - val2); break;
                case '*' : st.push(val1 * val2); break;
                case '/' : st.push(val1 / val2); break;
                case '^' : st.push((int)pow(val1, val2)); break;
            }
        }
        i++;
    }

    return st.top();
}
int main(){
    // string infix = "A+B*C-(D/E^F)";
    // string ifx = "a+b*(c^d-e)";
    // string c = "a^b^c";
    // string d = "a+b*c-d";
    // string e = "(A+B)*C-D+F";
    // string postFix = infixToPostfix(e);
    // string preFix = infixToPrefix(e);
    // cout << "Infix : " << e << endl;
    // // cout << "PostFix : " << postFix << endl;
    // cout << "PreFix : " << preFix << endl; 

    string c = "231*+9-";
    int evalutedPf = evaluatePostFix(c);
    cout << c << " = " << evalutedPf << endl;
}