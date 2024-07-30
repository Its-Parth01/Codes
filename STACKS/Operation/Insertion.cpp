#include <iostream>
#include <stack>
using namespace std;

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

/*
// RECURSION
void recur(stack <int> &s, stack <int> x) {
    if (s.empty()) {
       s.push(x);
        return;
    }
    int curr = s.top();
    s.pop();
    recur(s, x);
    s.push(curr);
}
*/

void remove_at_bottom (stack <int> &s) {
    stack <int> temp;
    while (s.size() != 1)   
    {
        int curr = s.top();
        s.pop();
        temp.push(curr);
    }
    s.pop();  // this is the point where x got inserted at bottom

    while (! temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}

/*
// RECURSION
void recur(stack <int> &s) {
    if (s.size() == 1) {
       s.pop();
        return;
    }
    int curr = s.top();
    s.pop();
    recur(s);
    s.push(curr);
}
*/


void insert_at_index (stack <int> &s, int x, int idx) {
    stack <int> temp;
    int n = s.size();
    int count = 0;

    while (count < n - idx) 
    {
        count++;
        int curr = s.top();
        s.pop();
        temp.push(curr);
    }
    s.push(x);  // this is the point where x got inserted at index

    while (! temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}


int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40); // top

    insert_at_bottom (s,100);
    // recur(s, 100);

    cout << "Stack after inserting 100 at bottom: ";
    while (! s.empty())
    {
        int curr = s.top();
        s.pop();
        cout << curr << endl;
    }

    insert_at_index (s,200, 3);

    cout << "Stack after inserting 200 at index 3: ";
    while (! s.empty())
    {
        int curr = s.top();
        s.pop();
        cout << curr << endl;
    }

} 