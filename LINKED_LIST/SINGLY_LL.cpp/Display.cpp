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
        // this->data = val;
        next = NULL;
        // this->next = NULL;
    }
};

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insert_at_tail(node *&head, int val)
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

void insert_at_head(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

void insert_at_position(node *&head, int val, int pos)
{

    if (pos == 0)
    {
        insert_at_head(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;
    int current = 0;
    while (current != pos - 1)
    {
        temp = temp->next;
        current++;
    }
    n->next = temp->next;
    temp->next = n;
}

void update(node *&head, int val, int pos)
{
    node *temp = head;
    int current = 0;
    while (current != pos)
    {
        temp = temp->next;
        current++;
    }
    temp->data = val;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void delete_at_head(node *&head)
{
    node *todelete = head;
    head = head->next;

    delete todelete;
}

void delete_at_node(node *&head, int val)
{

    // if LL is empty
    if (head == NULL)
    {
        return;
    }

    // if LL has only one node
    if (head->next == NULL)
    {
        delete_at_head(head);
        return;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    // free(todelete);
}

void delete_at_tail(node *&head)
{
    node *second_lsst = head;
    while (second_lsst->next->next != NULL)
    {
        second_lsst = second_lsst->next;
    }
    node *todelete = second_lsst->next;
    second_lsst->next = NULL;
    free(todelete);
}

int main()
{

    node *head = NULL;

    cout << "insert at tail\n";
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    display(head);

    cout << "insert at head\n";
    insert_at_head(head, 0);
    display(head);

    cout << "insert at position\n";
    insert_at_position(head, 4, 2);
    display(head);

    cout << "update\n";
    update(head, 10, 2);
    display(head);

    cout << "ELEMRNT 5 IS PRESENT OR NOT = ";
    cout << search(head, 5);
    cout << endl;
    cout << "ELEMRNT 3 IS PRESENT OR NOT = ";
    cout << search(head, 3);
    cout << endl;

    cout << "delete at head\n";
    delete_at_head(head);
    display(head);

    cout << "delete at node\n";
    delete_at_node(head, 3);
    display(head);

    cout << "delete at tail\n";
    delete_at_tail(head);
    display(head);
}