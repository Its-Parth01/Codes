#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

int cal ( int v1, int v2, char op) {
    if (op == '+') return v1 + v2;
    if (op == '-') return v1 - v2;
    if (op == '*') return pow(v1, v2);
    if (op == '/') return v1 / v2;
}

int precedence (char ch) {
    if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '^') return 3;
    else return -1;

}

int eva(string &str) {
    stack <int> num;
    stack <char> op;
    for (int i = 0; i < str.size(); i++ ) {
        if(isdigit(str[i])) {
            num.push(str[i] - '0' );
        }
        else if (str[i] == '(') {
            op.push('(');
        }
        else if (str[i] == ')') {
            while (! op.empty() && op.top() != '(') {
                char ops = op.top();
                op.pop();

            int v2 = num.top();
            num.pop();
            int v1 = num.top();
            num.pop();
            num.push(cal(v1, v2, ops));
        }
        if(! op.empty()) op.pop();
    }
        else {
            while (! op.empty() && precedence(op.top()) >= precedence(str[i])) {
                char ops = op.top();
                op.pop();

            int v2 = num.top();
            num.pop();
            int v1 = num.top();
            num.pop();
            num.push(cal(v1, v2, ops));
            }
            op.push(str[i]);
        }
    }
    while (! op.empty()) {
                char ops = op.top();
                op.pop();

            int v2 = num.top();
            num.pop();
            int v1 = num.top();
            num.pop();
            num.push(cal(v1, v2, ops));
        }
        return num.top();
}

int main () {
    string str = "1+(2*(3-1))+2";
    cout << eva(str) << endl;

}

