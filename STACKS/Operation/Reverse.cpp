
// reversse stack in original stack
#include<iostream>
#include<stack>
using namespace std;

void reverse (stack<int> &s) {
    stack<int> t1, t2;
    while (! s.empty()) {
        int curr = s.top();
        s.pop();
        t1.push(curr);
    }
    while (! t1.empty()) {
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }
    while (! t2.empty()) {
        int curr = t2.top();
        t2.pop();
        s.push(curr);
    }
}


void insert_at_bottom (stack <int> &s, int x) {
    stack <int> temp;
    while (! s.empty())
    {
        int curr = s.top();
        s.pop();
        temp.push(curr);
    }
    s.push(x);  // this is the point where x got inserted at bottom

    while (! temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}

// 2 way of insert at bottom
void insert_bottom (stack <int> &s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }
    int topele = s.top();
    s.pop();
    insert_bottom(s, x);
    s.push(topele);
}


void recur(stack<int> &s) {
    if (s.empty()) return;
    int curr = s.top();
    s.pop();
    recur(s);
    insert_at_bottom(s, curr);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    reverse(s);

    while (! s.empty())
    {
        int curr = s.top();
        s.pop();
        cout << curr << endl;
    }
}



/*
// reverse sentence
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverse (string s) {

    stack <string> s;

    for (int i = 0; i<s.length(); i++) {
        string word = "";
        while (s[i] != ' ' && i < s.length()) {
            word += s[i];
            i++;
        }
        s.push(word);
    } 
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main () {
    string str = "Hello jiii, World!";
    reverse(str); 
}
*/



/*
// reverse sentence
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseSentence(const string& s) {
    stack<string> words;

    size_t start = 0;
    while (start < s.length()) {
        size_t end = s.find(' ', start);
        if (end == string::npos) {
            end = s.length();
        }
        string word = s.substr(start, end - start);
        words.push(word);
        start = end + 1;
    }

    while (!words.empty()) {
        cout << words.top() << " ";
        words.pop();
    }
}

int main() {
    string str = "Hello jiii, World!";
    reverseSentence(str);
    return 0;
}
*/