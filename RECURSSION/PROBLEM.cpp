/*
// TOWER OF HANIO
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void tower(int n, int start, int helper, int end) {
    if (n == 0) return;
    tower(n-1,start, end, helper);
    cout << "Move disk " << n << " from " << start << " to " <<end<<endl;
    tower(n-1, helper, start, end);
}

int main (){
    int n;
    cin>>n;
    tower(n,1,2,3);
}
*/






/*
// CLILMB STAIRS
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int stairs(int n) {
    if(n==0 || n==1 ){
        return 1;
    }
    return stairs(n-1)+stairs(n-2);
}
int main (){
    int n;
    cin>>n;
    cout<<stairs(n);
}
*/







/*
// FROG JUMOS
#include<iostream>
using namespace std;

int f(int *h, int n, int i) {
    if(i == n-1) return 0;
    if(i == n-2) return f(h, n, i+1) + abs(h[i] - h[i+1]);

    return min(f(h, n, i+1) + abs(h[i] - h[i+1]), f(h, n, i+2) + abs(h[i] - h[i+2]));
}

int main () {
    int arr[] = {10, 30, 40, 20};
    int n = 4;
    cout<<f(arr, n, 0);
}
*/







/*
// POSSIBLE PATH FROM START TO END (DICE)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countpath(int s, int e) {
    if (s == e) return 1;
    if (s > e) return 0;

    int count = 0;
    for (int i = 1; i <= 6; i++) {    // dice no from 1 to 6
        count += countpath(s+i, e);
    }
    return count;
}

int main (){
    cout<<countpath(0,3);
}
*/







/*
// MAZE count path (right or down)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countpath(int n, int i, int j) {
    if (i == n-1 && j == n-1) return 1;
    if (i > n-1 || j > n-1) return 0;
    return countpath(n, i+1, j) + countpath(n, i, j+1);
}

int main (){
    cout<<countpath(3,0,0);
}
*/


/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countpath(int n, int m, int i, int j) {
    if (i == n-1 && j == m-1) return 1;
    if (i > n-1 || j > m-1) return 0;
    return countpath(n, m, i+1, j) + countpath(n, m, i, j+1);
}

int main (){
    cout<<countpath(3,3,0,0);
}
*/






/*
// TILING (2x4 board && 2x1 tile)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int tilingways(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return tilingways(n-1) + tilingways(n-2); // vertically + horizontal
}
int main (){
    cout<<tilingways(4);
}
*/





/*
// FRIENDS PAIRING
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int friendspairing(int n) {
    if(n == 0 ||n == 1 || n == 2) return n;
    return friendspairing(n-1) + (n-2)*(n-1);

}
int main (){
    cout<<friendspairing(4);
}
*/






/*
// 0-1 KNAPSWAP
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int knapsack(int val[], int wt[], int n, int W) {
    if (n == 0 || W == 0) return 0;
    if (wt[n-1] > W) return knapsack(val, wt, n-1, W);
// (if n means item include ), (if item not include)
    return max(knapsack(val, wt, n-1, W-wt[n-1])+val[n-1], knapsack(val, wt, n-1, W));
}

int main (){
    int wt[] = {10,20,30};
    int val[] = {100,50,150};
    int W = 50;
    cout<<knapsack(val, wt, 3, W);
}
*/







/*
// RAT IN A MAZE
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1         1 -> RAT CAN MOVE & 0 -> CAN'T MOVE

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool issafe(int** arr, int x, int y, int n) {
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}
bool rat(int** arr, int x, int y, int n, int** solarr) {
    if(x==n-1 && y==n-1) {
        solarr[x][y] = 1;
        return true;
    }
    if(issafe(arr, x, y, n)) {
        solarr[x][y] = 1;
        if(rat(arr, x+1, y, n, solarr)) {
            return true;
        }
        if(rat(arr, x, y+1, n, solarr)) {
            return true;
        }
        solarr[x][y] = 0;   // wapas ake backtrack kar diya; backtracking
        return false;
    }
    return false;
}

int main (){
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i=0; i<n; i++) {
        arr[i] = new int[n];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    } cout<<endl;

    int** solarr = new int*[n];
    for(int i=0; i<n; i++) {
        solarr[i] = new int[n];
        for(int j=0; j<n; j++) {
            solarr[i][j]=0;
        }
    }
    if(rat(arr, 0, 0, n, solarr)) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<solarr[i][j]<<" ";
            } cout<<endl;
        }
    }
    return 0;
}
*/







/*
// N QUEEN
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool issafe(int ** arr, int x, int y, int n) {
    for(int row = 0; row , x; row ++) {
        if(arr[row][y] == 1) return false;
    }
    int row = x;
    int col = y;
    while(row>=0 && col>=0) {
        if(arr[row][col] == 1) return false;
        row--;
        col--;
    }
    row = x;
    col = y;
    while(row>=0 && col<n) {
        if(arr[row][col] == 1) return false;
        row--;
        col++;
    }
    return true;
}

bool queen(int** arr, int x, int n) {
    if(x >= n) return true;
    for(int col = 0;col<n; col ++) {
        if(issafe(arr, x, col, n)) {
            arr[x][col] = 1;

            if(queen(arr,x+1,n)) return true;
            arr[x][col] = 0; // o
        }
    }
    return false;
}

int main ()
{
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i = 0; i<n; i++) {
        arr[i] = new int[n];
        for(int j=0;j<n;j++) {
            arr[i][j] = 0;
        }
    }
    if(queen(arr,0,n)) {
        for(int i = 0; i<n; i++) {

        for(int j=0;j<n;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    }
}
*/