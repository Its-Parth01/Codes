/*
Given a series of N daily quotes for a stack, we need tp calculate the span of the stocks price for all N days.
The span of the stock's price for a given day is the maximum number of consecutive days,
starting from and including that day, where the price of the stock was less than or equal to that day
*/


#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

// previous greater element
vector <int> pge (vector <int> &arr) {
    int n = arr.size();

reverse(arr.begin(), arr.end());    

    vector <int> res(n, -1);
    stack <int> s;
    s.push(0);

    for(int i=1; i<n; i++) {
        while ( ! s.empty() && arr[i] > arr[s.top()]) {
            res[s.top()] = n - i - 1;   // after reverse index will change
            s.pop();
        }
        s.push(i);
    }
    reverse(res.begin(), res.end());
    reverse(arr.begin(), arr.end());   
    return res;
}

int main () {
    int n;
    cin>>n;
    vector <int> v;
    while (n--) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector <int> res = pge(v);
    for(int i= 0; i< res.size(); i++) {
        cout<< (i - res[i]) <<" ";
    }
}