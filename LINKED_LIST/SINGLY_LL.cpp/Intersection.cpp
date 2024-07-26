// RETURN NODE AT WHICH TWO LIST INTERSECT

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

int getlength(node *head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

node *move_head_by_k(node *head1, int k)
{
    node *temp = head1;
    while (k--)
    {
        temp = temp->next;
    }
    return temp;
}
node *intersect(node *head1, node *head2)
{
    node *temp1;
    node *temp2;

    // calculate length of ll
    int l1 = getlength(head1);
    int l2 = getlength(head2);

    // find difference k between & move longer ll by k steps
    if (l1 > l2)
    { // l1 is longer
        int k = l1 - l2;
        temp1 = move_head_by_k(head1, k);
        temp2 = head2;
    }
    else
    { // l2 is longer
        int k = l2 - l1;
        temp1 = head1;
        temp2 = move_head_by_k(head2, k);
    }

    // compare temp1 and temp2
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

int main()
{

    // node* head = NULL;
    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.display();

    linkedlist l2;
    l2.insert_at_tail(6);
    l2.insert_at_tail(7);
    l2.insert_at_tail(3);
    l2.head->next->next = l1.head->next->next->next;
    l2.display();

    node *intersection = intersect(l1.head, l2.head);
    if (intersection)
    {
        cout << "Intersection is: " << intersection->data << endl;
    }
    else
    {
        cout << "No intersection" << endl;
    }
}