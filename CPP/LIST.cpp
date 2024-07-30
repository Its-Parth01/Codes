#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> l1 = {1, 2, 3, 4};
    // list<int> :: iterator itr;
    auto itr = l1.begin();
    cout << *itr << endl; // stores address of first element


    // reversal travesal
    for (auto itr = l1.rbegin(); itr != l1.rend(); itr++) {
        cout << *itr << endl;
    }

    // inserting element
    
    advance(itr, 2);
    cout << *itr << endl;
    l1.insert(itr,5);

    // using iterator travesal
    for (auto itr = l1.begin(); itr != l1.end(); itr++) {
        cout << *itr << endl;
    }

    l1.insert(itr,3,5);
    // travesal using range based loop
    for (auto num : l1)
    {
        cout << num << endl;
    }

    auto l = l1.begin();
    auto r = l1.begin();
    advance(r,2); // now is pointing to 3
    l1.insert( itr, l, r);
     for (auto itr = l1.begin(); itr != l1.end(); itr++) {
        cout << *itr << endl;
    }

    // deleting
    auto start_itr = l1.begin();
    advance(start_itr, 2);  // point to 3rd element

    auto end_itr = l1.begin();
    advance(end_itr, 4);  // point to 5th element

    l1.erase(start_itr, end_itr);

}