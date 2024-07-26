/*
// PRINT ELEMENTS OF ARRAY
#include<iostream>
using namespace std;

void print(int *arr, int idx, int n) {
    if (idx == n) return;
    cout << arr[idx] << " ";
    print(arr, idx + 1, n);
}

int main (){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    print(arr, 0, n);
    return 0;
}
*/





/*
// MAX VALAUE
#include<iostream>
using namespace std;

int m( int *arr, int idx, int n) {
    if (idx == n-1) return arr[idx];
    return max(arr[idx],m(arr, idx + 1, n));
}
int main ()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout<<m(arr,0,n);

}
*/






/*
// SUM OF ARRAY ELEMENT
#include<iostream>
using namespace std;

int SUM( int *arr, int idx, int n) {
    if (idx == n-1) return arr[idx];
    return arr[idx] + SUM(arr, idx + 1, n);
}
int main ()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout<<SUM(arr,0,n);
}
*/






/*
// FIND ELEMENT
#include<iostream>
using namespace std;
bool find(int *arr, int n, int i, int x) {
    if(i == n) {
        return false;
    }
    if(arr[i] == x) return true;
    return find(arr, n, i+1, x);

    // return (arr[i] == x) || find(arr, n, i+1, x);
}
int main () {
    int arr[] = {5,4,7,9,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    bool result = find(arr, n, 0, x);
    cout<<result;
}
*/






/*
// ARRAY SORTED OR NOT
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sorted(int arr[], int n) {
    if(n==1) return true;
    if(arr[0] > arr[1]) return false;
    return sorted(arr+1, n-1);
}

int main (){
    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<sorted(arr,n);
}
*/






/*
// FIRST AND LAST UCCURENCE OF NUMBER IN THE ARRAY
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int focc(int arr[], int n, int i, int key) {
    if(i==n) return -1; // if key not found
        if(arr[i]==key) return i;
        return focc(arr, n, i+1, key);
}

int locc(int arr[], int n, int i, int key) {
     if(i==n) return -1;
    int restarray = locc(arr, n, i+1, key);
    if(restarray != -1) return restarray;
    if(arr[i]==key) return i;
    return -1;
}

int main () {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<focc(arr, n, 0, 2)<<endl;
    cout<<locc(arr, n, 0, 2)<<endl;
}
*/






/*
// SAY DIGITS
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void saydigits(int n, string arr[]) {
    if(n==0) return;

     int digit = n % 10;
     n = n/10;

    saydigits(n,arr);
    cout<<arr[digit] << " ";

}

int amin (){

    string arr[10] = {"one","two","three","four","five","six","seven","eight","nine","ten"};

    int n;
    cin>>n;

    saydigits(n, arr);
}
*/






/*
// PERMUTAION OF A DIGITS  (distint)
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a, int idx) {
    if(idx == a.size()) {
        ans.push_back(a);
        return;
    }
    for(int i = idx; i<a.size(); i++) {
        swap(a[i], a[idx]);
        permute(a,idx+1);
        swap(a[i], a[idx]);
    }
    return;
}
int main (){
    int n;
    cin>>n;
    vector<int> a(n);
    for( auto &i : a)
    cin>>i;
    permute(a,0);
    for(auto v : ans) {
        for(auto i : v) {
            cout<<i<<" "<<endl;
        }
    }
}
*/


// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>

// using namespace std;;

// int main (){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for( auto &i : a)
//     cin>>i;
//     sort(a.begin(), a.end());
//     do{
//         ans.push_back(a);
//     } while (next_permutation(a.begin(),a.end()));
//     for(auto v : ans) {
//         for(auto i : v) {
//             cout<<i<<" "<<endl;
//         }
//     }
// }





/*
// PERMUTAION OF A DIGITS  (duplicates)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;;

void helper(vector<int> &a, vector<vector<int>> &ans, int idx) {
    if(idx == a.size()) {
        ans.push_back(a);
        return;
    }
    for(int i = idx; i<a.size(); i++) {
        if(i != idx and a[i] == a[idx])  continue;
        swap(a[i], a[idx]);
        helper(a,ans,idx+1);
    }
    return;
}

vector<vector<int>> permute(vector<int> nums) {

    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
        helper(nums,ans,0);
    return ans;
}
int main (){
    int n;
    cin>>n;
    vector<int> a(n);
    for( auto &i : a)
    cin>>i;
    vector<vector<int>> res = permute(a);
    for(auto v : res) {
        for(auto i : v) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
*/






/*
// PRINT SUM OF SUBSETS
#include<iostream>
#include<vector>
using namespace std;

void f(int *arr, int n, int i, int sum, vector<int> &result) {
    if(i == n) {
        result.push_back(sum);
        return;
    }
    f(arr, n, i+1, sum + arr[i], result);       // pick ith element
    f(arr, n, i+1, sum, result);        // not pick ith element
}
int main (){
    int arr[] = {2, 4, 5};
    int n = 3;
    vector<int> result;
    f(arr, n, 0, 0, result);
    for(auto i : result) {
        cout<<i<<" ";
    }

    // for(int i = 0; i<result.size(); i++) {
    //     cout<<result[i]<<" ";
    // }
}
*/