/*
// REVERSE 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(string s) {
    if(s.length() == 0) return;

    string restofstring = s.substr(1); // binod --> inod
    reverse(restofstring);
    cout << s[0];
}

int main (){
    reverse("binod");
}
*/


// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// void reverse(string& str, int i, int j) {

//     if(i>j) return;
//     swap(str[i], str[j]);
//     i++;
//     j--;
//     reverse(str, i, j);
// }

// int main (){
//     string s = "binod";
//     reverse(s, 0, s.length()-1);
//     cout<<s;
// } 
 





/*
// REMOVE THE OCCURENCE OF 'A';
#include<iostream>
using namespace std;

string f(string &s, int idx, int n) {
    if(idx == n) return "";
    string curr = "";
    curr += s[idx];
return ((s[idx] == 'a') ? "" : curr) + f(s, idx + 1, n);
}

int main () {
    string s = "abababab";
    cout<<f(s, 0, s.length());
}
*/





/*
// REPLACE PI WITH 3.14 IN STRING
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void replace(string s){
    if(s.length() == 0) return;

    if(s[0] == 'p' && s[1] == 'i') {
        cout<<"3.14";
        replace(s.substr(2));
    } 
    else {
        cout<<s[0];
        replace(s.substr(1));
    }
}
int main (){
    replace("pipxxppixiipi");
} 
*/







/*
// REMOVE DUPLICATES
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void remove(string s) {
    if(s.length() == 0) return;
    if(s[0] == s[1]) {
        remove(s.substr(1));
        }
        else {
            cout<<s[0];
            remove(s.substr(1));
            }
}

// string remove(string s) {
//     if(s.length() == 0) {
//         return s; //empty string
//     }
//     char ch = s[0];
//     string ans = remove(s.substr(1));

//     if(ch == ans[0]) { 
//         return ans;
//     }
//     return (ch + ans);

// }
int main () {
    cout<<remove("aaabbccd");
}
*/







/*
// MOVE ALL X TO THE END
#include<iostream>
#include<string>
using namespace std;
string moveX(string s) {
    if(s.length() == 0) return s;
        char ch = s[0];
        string ans = moveX(s.substr(1));
        if(ch == 'x') {
            return ans + ch;
        }
        return ch + ans;
    }

int main () {
    cout<<moveX("axlxmxnx");
    return 0;
}
*/







/*
// GENERATE ALL SUBSTRINGS
#include<iostream>
#include<string>
using namespace std;

void substring(string s, string ans) {
    if(s.length() == 0) {
        cout<<ans<<endl;
            return;
        }
        char ch = s[0];
        string ros = s.substr(1);
        substring(ros, ans + ch);
        substring(ros, ans);
        }
int main (){
    substring("abc","");
}
*/



// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;

// void f(string &s, int i, string result, vector <string> &li) {
//     if (i == s.length()) {
//         li.push_back(result);
//         return;
//     }
//     f(s, i + 1, result + s[i], li);
//     f(s, i + 1, result, li);
// }
// int main (){
//     vector<string> res;
//     string str = "abc";
//     f(str, 0, "", res);
//     for(int i = 0; i< res.size(); i++) {
//         cout<<res[i]<<endl;
//     }
// }





/*
// GENERATE ALL SUBSTRINGS WITH ASCII VALUE
#include<iostream>
#include<string>
using namespace std;

void substring(string s, string ans) {
    if(s.length() == 0) {
        cout<<ans<<endl;
            return;
        }
        char ch = s[0];
        int code = ch;
        string ros = s.substr(1);
        substring(ros, ans + ch);
        substring(ros, ans);
        substring(ros, ans + to_string(code));
        }
int main (){
    substring("abc","");
}
*/






/*
// PRINT ALL POSSIBLE WORDS FROM PHONE DIGITS
#include<iostream>
#include<string>
using namespace std;

string keypadarr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s, string ans) {
    if(s.length() == 0) {
        cout<<ans<<endl;
            return;
    }
    char ch = s[10];
    string code = keypadarr[ch-'0']; // char to int; 0's ascii code - ch ascii code = int
    string ros = s.substr(1);

    for(int i=0;i<code.length();i++) {
        keypad(ros, ans + code[i]);
    }
}
int main (){
    keypad("23","");
}
*/




// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;

// void f(string &s, int i, string result, vector <string> &li, vector <string> &v) {
//     if (i == s.size()) {
//         li.push_back(result);
//         return;
//     }
//     int digit = s[i] - '0';
//     if(digit <= 1 ) {
//         f(s, i+1, result, li, v);
//         return;
//     }
//     for(int j=0;j<v[digit].size();j++) {
//         f(s, i+1, result + v[digit][j], li, v);
//     }
//     return;
// }
// int main (){
//     vector<string> v {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//     string str = "23";
//     vector<string> li;
//     f(str, 0, "", li, v);
//     for(int i = 0; i< v.size(); i++) {
//         cout<<li[i]<<endl;
//     }
// }






/*
// PERMUTATION 
#include<iostream>
#include<string>
using namespace std;

void permutation(string s, string ans) {
    if(s.length() == 0) {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++) {
        char ch = s[i];
        string ros = s.substr(0,i) + s.substr(i+1);
        permutation(ros, ans + ch);
    }
}
int main (){
    permutation("ABC","");
}
*/





/*
// PALINDROME
#include<iostream>
#include<string>
using namespace std;

bool palindrome(string str, int i, int j) {
    if(i >= j) return true;
        if(str[i] != str[j]) return false;
        return palindrome(str, i+1, j-1);
}

int main (){
    string str = "abba";
    cout<<palindrome(str, 0, str.length()-1);

}
*/






/*
// NUMBER PALINDROME
#include<iostream>
using namespace std;

bool f(int num, int *temp) {
    if(num >= 0 and num<= 9) {
        int lastoftemp = (*temp) % 10;
        (*temp) /= 10;
        return (num == lastoftemp);
    }
    bool result = (f(num/10, temp) and (num%10) == ((*temp) % 10));
    (*temp) /= 10;
    return result;
        
}
int main (){
    int num = 12321;
    int another = num;
    int *temp = &num;
    cout<<f(num, temp);

}
*/