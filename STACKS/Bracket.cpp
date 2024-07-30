// check whether a given bracket sequence is balanced or not 

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isvalid  (string str) {
    stack<char> s;
    for(int i=0;i<str.length();i++) {
    char ch = str[i];   // current char 
        if(str[i]=='(' || str[i]=='{' || str[i]=='[') {
            s.push(ch);
        }
        else {
            if (ch == ')' && ! s.empty() && s.top() == '(' ) {
                s.pop();
            }
            else if (ch == '}' && ! s.empty() && s.top() == '{') {
                s.pop();
            }
            else if (ch == ']' && ! s.empty() && s.top() == '[') {
                s.pop();
            }
            else {
                return false;
            }
        }
    }
    return s.empty();
}

int main () {
    string str = "({}(){})([])";
    cout<<isvalid(str)<<endl;
}