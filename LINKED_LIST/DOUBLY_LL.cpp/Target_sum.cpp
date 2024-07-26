#include <iostream>
#include <vector>
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

vector<int> pairsum(node *head, node *tail, int x)
{
    vector<int> ans(2, -1);
    while (head != tail)
    {
        int sum = head->data + tail->data;
        if (sum == x)
        {
            ans[0] = head->data;
            ans[1] = tail->data;
            return ans;
        }

        if (sum > x)
        {
            tail = tail->prev;
        }
        else
        {
            head = head->next;
        }
    }
    return ans;
}

int main()
{

    doubly dl;

    cout << "insert at tail\n";
    dl.insert_at_tail(2);
    dl.insert_at_tail(5);
    dl.insert_at_tail(6);
    dl.insert_at_tail(8);
    dl.insert_at_tail(10);
    dl.display();
    vector<int> ans = pairsum(dl.head, dl.tail, 11);
    cout << ans[0] << " " << ans[1];
}