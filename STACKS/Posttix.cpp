
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int cal ( int v1, int v2, char op) {
    if (op == '+') return v1 + v2;
    if (op == '-') return v1 - v2;
    if (op == '*') return pow(v1, v2);
    if (op == '/') return v1 / v2;
}

int eva (string &str) {
    stack<int> s;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if(isdigit(ch)) {       // (s[i] >= '0' && s[i] <= '9')
            s.push(ch - '0');
        }
        else {
            int v2 = s.top();
            s.pop();
            int v1 = s.top();
            s.pop();
            s.push(cal(v1, v2, ch));
        }
    }
    return s.top();
}

int main (){
    string str = "231*+9-";
    cout<<eva(str);

}



/*
// INFIX TO POSTFIX
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int precedence (char ch) {
    if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '^') return 3;
    else return -1;

}

int cal ( int v1, int v2, char op) {
    if (op == '+') return v1 + v2;
    if (op == '-') return v1 - v2;
    if (op == '*') return pow(v1, v2);
    if (op == '/') return v1 / v2;
}

string eva (string s) {
    stack<char> s;
    string res;
    for(int i = 0; i < s.length(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {    
            res +=s[i];
        }
        else if (s[i] == '(') {
            s.push(s[i]);
        }
        else if (s[i] == ')') {
            while(! s.empty() && s.top() != '(') {
                res += s.top();
                s.pop();
            }
            if(! s.empty()) {
                s.pop();
            }
        }
        else {
            while(! s.empty() && precedence(s.top()) >= precedence(s[i])) {
                res += s.top();
                s.pop();
            }
            s.push(s[i]);
        }
    }
    while(! s.empty()) {
        res += s.top();
        s.pop();
        }
    return res;;
}

int main (){
    cout<<eva("(a-b/c)*(a/k-l)");

}
*/