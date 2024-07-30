#include <iostream>
#include <stack>
using namespace std;

stack<int> copystack(stack<int> &input)
{
    stack<int> temp;
    while (!input.empty())
    {
        // do the process till the time input stack doesn't empty
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }

    stack<int> result;
    while (!temp.empty())
    {
        // do the process till the time input stack doesn't empty
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

// RECURSION
void recur(stack <int> &s, stack <int> &result) {
    if (s.empty()) {
        return;
    }
    int curr = s.top();
    s.pop();
    recur(s, result);
    result.push(curr);
}

int main()
{

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // stack<int> res = copystack(s);
    stack<int> res;
    recur(s, res);

    // PRINT STACK
    while (!res.empty())
    {
        int curr = res.top();
        res.pop();
        cout << curr << endl;
    }
}