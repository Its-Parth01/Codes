// MAXIMUM AND MINIMUM DISTANCE BETWEEN TWO CRITIAL POINT
#include <iostream>
#include <vector>
#include <climits>
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

bool criticalp(node *&currnode)
{
    // local maxima
    if (currnode->prev->data < currnode->next->data && currnode->next->data < currnode->data)
    {
        return true;
    }

    // local manima
    if (currnode->prev->data > currnode->next->data && currnode->next->data > currnode->data)
    {
        return true;
    }

    return false;
}

vector<int> critical(node *head, node *tail)
{
    vector<int> ans(2, INT_MAX);
    int fc = -1, lc = -1;

    node *currnode = tail->prev;
    if (currnode == NULL)
    {
        ans[0] = ans[1] = -1;
        return ans;
    }

    int currpos = 0;
    while (currnode->prev != NULL)
    {
        if (criticalp(currnode))
        {
            if (fc == -1)
            {
                fc = lc = currpos;
            }
            else
            {
                ans[0] = min(ans[0], currpos - lc); // min distance
                ans[1] = currpos - fc;              // max distance
                lc = currpos;
            }
        }
        currpos++;
        currnode = currnode->prev;
    }
    if (ans[0] == INT_MAX)
    {
        ans[0] = ans[1] = -1;
    }
    return ans;
}

int main()
{

    doubly dl;

    cout << "insert at tail\n";
    dl.insert_at_tail(1);
    dl.insert_at_tail(5);
    dl.insert_at_tail(2);
    dl.insert_at_tail(6);
    dl.insert_at_tail(3);
    dl.display();
    vector<int> ans = critical(dl.head, dl.tail);
    cout << ans[0] << " " << ans[1];
}