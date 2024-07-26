/*
// N SUM
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int sum (int n) {
    if (n == 0) return 0;
    return n + sum(n-1);
}

int main () {
    int n;
    cin >> n;
    cout << sum(n);
}
*/





/*
// N SUM WITH ALTERNATE SIGN (1-2+3-4.....)
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int sum (int n) {
    if (n == 0) return 0;
    return sum(n-1) + ((n%2 == 0) ? (-n) : n);
}

int main () {
    int n;
    cin >> n;
    cout << sum(n);
}
*/





/*
// sum of digits
#include<iostream>
using namespace std;

int sum(int n) {
    if (n <= 9 and n >= 0) return n;
    return (n/10) + (n%10);
}

int main () {
    int n;
    cin>>n;
    cout<<sum(n);
}
*/






/*
// N RAISSED TO P
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int power(int n, int p) {
    if (p == 0) return 1;
    return n * power(n, p-1);
}

// int power(int n, int p) {
//     if(p==0) return 1;
//     if(p==1) return n;

//     int ans = power(a, b/2);
//     if(b%2==0) return ans*ans;  // p is even
//     else return ans*ans*n;  // p is odd
// }

int main () {
    int n, p;
    cin >> n >> p;
    cout << power(n, p);
}
*/






/*
// FACTORIAL
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n-1);
}

int main () {
    int n;
    cin >> n;
    cout<<fact(n);

}
*/






/*
//FIBONACCI
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int fib(int n) {
    if(n == 0 || n == 1)  return n;
    return fib(n-1) + fib(n-2);
}

int main (){
    int n;
    cin >> n;
    cout << fib(n);
}
*/




/*
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

 int fib(int n) {
        if (n == 0 || n == 1) return n;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

int main (){
    int n;
    cin >> n;
    cout << fib(n);
}

// PRINT NUMBER TILL N
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void num(int n) {
    if(n==0) return;
    cout<<n<<" ";
    num(n-1);
    cout<<n<<" ";
}

int main (){
    int n;
    cin>>n;
    num(n);
}
*/





/*
// K MULTIPLES OF N
#include<iostream>
using namespace std;

void f(int num, int k) {
    if (k == 0) return;
    f(num, k-1);
    cout<<num*k<<" ";
}
int main (){
    f(8,5);
}
*/






/*
// GCD
#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if(b>a) return gcd(b,a);
    if(b==0) return a;
    return gcd(b, a%b);
}
int main (){
    cout<<gcd(40,48);
}
*/






/*
// ARMSTRONG
#include<iostream>
using namespace std;

int power(int n, int p) {
    if (p == 0) return 1;
    return n * power(n, p-1);
}
int f(int n, int d) {
    if(n == 0) return 0;
    return power(n%10, d) + f(n/10, d);
}

int main (){
    int n;
    cin>>n;

    int no_of_digits = 0;
    int temp = n;
    while(temp > 0) {
        temp /= 10;
        no_of_digits++;
    }
    int result = f(n, no_of_digits);
    if(result == n) cout<<"yes";
    else cout<<"no";
}
*/