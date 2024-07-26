// TWO LL ARE EQUAL OR NOT
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

    // void insert_at_tail (node* &head, int val)
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

bool equal(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return (temp1 == NULL && temp2 == NULL); // TRUE
}

int main()
{

    // node* head = NULL;
    linkedlist l1;
    linkedlist l2;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l2.insert_at_tail(1);
    l2.insert_at_tail(2);
    l2.insert_at_tail(3);
    l1.display();
    l2.display();

    cout << equal(l1.head, l2.head);
}