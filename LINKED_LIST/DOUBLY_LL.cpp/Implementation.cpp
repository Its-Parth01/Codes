#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        // this->data = val;
        next = NULL;
        prev = NULL;
        // this->next = NULL;
        // this->prev = NULL;
    }
};

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "<-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
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
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insert_at_tail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        insert_at_head(head, val);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
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
    n->prev = temp;
    n->next->prev = n;
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
    head->prev = NULL;

    delete todelete;
}

void delete_at_node(node *&head, int pos)
{
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void delete_at_tail(node *&tail)
{
    if (tail == NULL)
    {
        return;
    }
    node *temp = tail;
    tail = tail->prev;

    if (tail != NULL)
    {
        tail->next = NULL;
    }
    free(temp);
}

int main()
{

    node *head = NULL;
    node *tail = NULL;

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
    delete_at_tail(tail);
    display(tail);
}