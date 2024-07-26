#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class linkedlist
{
public:
    node *head;

    linkedlist()
    {
        head = NULL;
    }

    void insert_at_tail(int val)
    {
        node *n = new node(val);

        if (head == NULL)
        {
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

node *middle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool palindrome(node *head)
{

    // FIND MIDDLE ELEMENT
    node *slow = head;
    node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // now slow is pointing to middle element

    // BREAK LL IN MIDDLE
    node *currptr = slow->next;
    node *prevptr = slow;
    slow->next = NULL;

    // REVERSE THE SECOND HALF

    while (currptr)
    {
        node *nextnode = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextnode;
    }

    // CHECK IF Two LL ARE EQUAL
    node *first = head;
    node *second = prevptr;
    while (first && second)
    {
        if (first->data != second->data)
        {
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}

int main()
{

    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(2);
    l1.insert_at_tail(1);
    l1.display();

    cout << palindrome(l1.head) << endl;
}