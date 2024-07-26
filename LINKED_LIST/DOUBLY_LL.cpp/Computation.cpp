// RIGHT TO LEFT TRAVEL; DELETE NODES WHOSE NEIGHBOUR (NEXT & PREV) HAVE VALUE
// 2 1 1 2 1 => 2 1 1
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

class doubly
{
public:
    node *head;
    node *tail;

    doubly()
    {
        head = NULL;
        tail = NULL;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "<-->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert_at_head(int val)
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

    void insert_at_tail(int val)
    {
        node *n = new node(val);

        if (head == NULL)
        {
            insert_at_head(val);
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
};

void neighbour(node *&head, node *&tail)
{
    node *currnode = tail->prev;
    while (currnode != head)
    {
        node *prevnode = currnode->prev;
        node *nextnode = currnode->next;

        if (prevnode->data == nextnode->data)
        {
            prevnode->next = nextnode;
            nextnode->prev = prevnode;
            free(currnode);
        }
        currnode = prevnode;
    }
}

int main()
{

    doubly dl;

    cout << "insert at tail\n";
    dl.insert_at_tail(2);
    dl.insert_at_tail(1);
    dl.insert_at_tail(1);
    dl.insert_at_tail(2);
    dl.insert_at_tail(1);
    dl.display();
    neighbour(dl.head, dl.tail);
    dl.display();
}