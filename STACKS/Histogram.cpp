/*
given a array of integers heights representing the histogram bar height,
where the width of each bar is 1, return the area of the largest rectangle in the histogram.
*/


#include<iostream>
#include<climits>
#include<stack>
#include<vector>
using namespace std;

// next smaller element
int histogram (vector <int> &arr) {
    stack <int> s;
    int n = arr.size();

    int ans = INT_MIN;

    s.push(0);

    for(int i=1; i<n; i++) {
        while ( ! s.empty() && arr[i] < arr[s.top()]) {
            int ele = arr[s.top()];
            s.pop();
            int nsi = i;
            int psi = (s.empty()) ? -1 : s.top();
            ans = max(ans, ele * (nsi - psi - 1));
        }
        s.push(i);
    }

    while (!s.empty()) {
        int ele = arr[s.top()];
        int nsi = n;
        int psi = (s.empty()) ? (-1) : s.top();
        ans = max(ans, ele * (nsi - psi - 1));
        s.pop();
    }

    return ans;
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
    int ans = histogram(v);
    cout<<ans<<"\n";
}