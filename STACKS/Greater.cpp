// NEXT GREATER ELEMENT     [ 4,3,9,1,6,8,2 ]   =>    [ 9,9,-1,6,8,-1,-1 ]

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// next greater element
vector <int> nge (vector <int> &arr) {
    stack <int> s;
    int n = arr.size();
    vector <int> res(n, -1);
    s.push(0);

    for(int i=1; i<n; i++) {
        while ( ! s.empty() && arr[i] > arr[s.top()]) {
            res[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return res;
}

// next smaller element
vector <int> nse (vector <int> &arr) {
    stack <int> s;
    int n = arr.size();
    vector <int> res(n, -1);
    s.push(0);

    for(int i=1; i<n; i++) {
        while ( ! s.empty() && arr[i] < arr[s.top()]) {
            res[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
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
    vector <int> res = nge(v);
    for(int i= 0; i< res.size(); i++) {
        cout<<res[i]<<" ";
    }
}