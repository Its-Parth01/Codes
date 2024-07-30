#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class stack
{

    node *head;
    int capacity;
    int currsize;

public:
    stack(int c)
    {
        capacity = c;
        currsize = 0;
        head = NULL;
    }

    bool isempty()
    {
        return (head == NULL);
    }
    bool isfull()
    {
        return (currsize == capacity);
    }

    void push(int data)
    {
        if (isfull())
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            node *newnode = new node(data);
            newnode->next = head;
            head = newnode;
            currsize++;
        }
    }

    int pop()
    {
        if (isempty())
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        else
        {
            node *new_head = head->next;
            head->next = nullptr;
            // node* toberemoved = head;
            // int result = toberemoved->data;
            // delete toberemoved;
            delete head;
            head = new_head;
            // return result;
        }
    }

    int get_top()
    {
        if (isempty())
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        return head->data;
    }

    int size()
    {
        return currsize;
    }
};

int main()
{

    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.push(5);
    cout << s.get_top() << endl;
    s.push(6);

    s.pop();
    s.pop();
    cout << s.get_top() << endl;
}
