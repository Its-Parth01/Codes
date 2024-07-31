#include <iostream>
using namespace std;

class stack
{
    int capacity;
    int top;
    int *arr;

public:
    stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }

    void push(int data)
    {
        if (top >= capacity - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = data;
    }

    int pop()
    {
        if (top < 0)
        { //  top == -1;
            cout << "Stack Underflow\n";
            return -1;
        }
        top--;
    }

    int get_top()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isempty()
    {
        return top == -1;
    }

    int size()
    {
        return top + 1;
    }

    bool isfull()
    {
        return top == capacity - 1;
    }
};

int main()
{
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.get_top() << endl;
    s.push(5);
    cout << s.get_top() << endl;
    s.push(6);

    s.pop();
    s.pop();
    cout << s.get_top() << endl;
}