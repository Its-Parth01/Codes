/*
int getmin() retrives the minimum element of stack
*/

#include<iostream>
#include<climits>
#include<stack>
using namespace std;

#define ll long long int
class MinStack {
public:
    stack <int> s;
    ll mn;
    MinStack() {
        this->mn = INT_MAX;
        
    }
    
    void push(int val) {
        if(this->s.empty()) {
            this->mn = val;
            this->s.push(val);
        }
        else {
            this->s.push (val - this->mn);
            if(this->mn > val) {
                this->mn = val;
            }
        }
        
    }
    
    void pop() {
        if (! this-> s.empty()) {
            if(this->s.top() >= 0) {
                this->s.top();
            }
            else {
                this->mn = this->mn - this->s.top();
                this->s.pop();
            }
        }
        
    }
    
    int top() {
        if(this->s.size() == 1) {
            return this->s.top();
        }
        else if (this->s.top() < 0) {
                return this->mn;
            }
            else {
                return this->mn + this->s.top();
            }
        }
    
    int getMin() {
        return this->mn;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */