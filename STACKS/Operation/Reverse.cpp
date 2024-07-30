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