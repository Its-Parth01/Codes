#include<iostream>
#include<list>
using namespace std;

int main () {

    list <int> l1 = {1,2,3,4};
    // list<int> :: iterator itr;
    auto itr = l1.begin();
    cout<<*itr<<endl;   // stores address of first element

    advance(itr, 2);
    cout<<*itr<<endl; 

return 0;
} 