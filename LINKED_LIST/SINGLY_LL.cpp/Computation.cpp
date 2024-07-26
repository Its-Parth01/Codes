
/*
// DELETE ALTERNATE ELEMENT 1-2-3-4-5 => 1-3-5

#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};
class linkedlist {
    public:
    node* head;

linkedlist(){
    head = NULL;
}

    // void insert_at_tail (node* &head, int val)
    void insert_at_tail (int val){
    node* n = new node(val);

        if(head == NULL) {
            head = n;
            return;
        }
        node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
     temp->next = n;
    }

    void display () {
        node* temp = head;
            while(temp != NULL) {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void delete_alternate (node* &head) {
    node* temp = head;
    while(temp != NULL and temp->next != NULL) {
        node* f = temp->next; // node tp delete
        temp->next = temp->next->next;
        delete f;
        temp = temp->next;
    }
}

int main (){

    // node* head = NULL;
    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.display();

    delete_alternate(l1.head);
    l1.display();

}
*/

/*
// DETETING DUPLICATES FROM SORTED LL

#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};
class linkedlist {
    public:
    node* head;

linkedlist(){
    head = NULL;
}

    // void insert_at_tail (node* &head, int val)
    void insert_at_tail (int val){
    node* n = new node(val);

        if(head == NULL) {
            head = n;
            return;
        }
        node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
     temp->next = n;
    }

    void display () {
        node* temp = head;
            while(temp != NULL) {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void duplicates(node* &head) {
    node* current = head;
    while(current) { // current != null
        while(current->next != NULL && current->data == current->next->data ) {
            node* temp = current->next;  // node to be deleted
            current->next = current->next->next;
            free(temp);
        }
        // loop end when current and next node value are different or ll ends
        current = current->next;
    }
}

int main (){

    // node* head = NULL;
    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(3);
    l1.display();

    duplicates(l1.head);
    l1.display();

}
*/








/*
// REMOVE K-TH NODE FROM END OF THE LIST AND RETURN HEAD

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

// assume k is less than/equal length of ll
void remove_k_node_end(node *&head, int k)
{
    node *first = head;
    node *second = head;

    // move second by k steps ahead
    int count = k;
    while (count--)
    {
        second = second->next;
    }

    if (second == NULL)
    { // k is = to length of ll
        node *temp = head;
        head = temp->next;
        free(temp);
        return;
    }

    // when second id at null then first is at k node to be deleted
    while (second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    // now first is pointing to knode before kth node from end
    node *temp = first->next;
    first->next = first->next->next; // or = temp->next;
    delete temp;
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

    remove_k_node_end(l1.head, 4);
    l1.display();
}
*/