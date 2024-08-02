/*     
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

node *reverse_iterate(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr; // prevptr is at last and is new head
    // node* newhead = prevptr;
    // return newhead;
}

node *reverse_recursion(node *&head)
{
    if (head == NULL || head->next == NULL)
        return head; // if node is empty or only one node
    node *newhead = reverse_recursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}


// 1-2-3-4-5-6  =>  2-1-4-3-6-5
// REVERSE K NODES
node* reverse_k_nodes(node* &head, int k) {
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count = 0;
    while(currptr != NULL && count < k) {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr != NULL){
        head->next = reverse_k_nodes(nextptr, k);
    }
    return prevptr;
}

int main () {

    node* head = NULL;

    cout<<"insert at tail\n";
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    display(head);


    // node* newhead = reverse_iterate(head);
    // display(newhead);
    // // display(head);



    // node* newhead = reverse_recursion(head);
    // display(newhead);


   int k = 2;
   node* newhead = reverse_k_nodes(head, k);
   display(newhead);

}
*/








/*
// 1-2-3-4-5-6  =>  2-1-4-3-6-5
// REVERSE K NODES USING RECURSION

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

node* swap_adjacent(node* &head) {

    if(head == NULL || head->next == NULL) return head;

    node* second = head->next;
    head->next = swap_adjacent(second->next);
    second->next = head;   // reverse the link btw 1 and 2
    return second;
}

int main (){

    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.insert_at_tail(6);
    l1.display();
    l1.head = swap_adjacent(l1.head);
    l1.display();

}
*/








/*
// just print reverse ll

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

    void reverseprint(node* head) {
        if(head == NULL) return;
        reverseprint(head->next);
        cout << head->data << "-->";
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
    reverseprint(l1.head);

}
*/