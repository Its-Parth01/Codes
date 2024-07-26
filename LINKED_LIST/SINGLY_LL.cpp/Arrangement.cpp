/*
// REARRANGEMENT OF NODES
// ROTATE LIST TO RIGHT BY K PLACES

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

node* rotate(node* &head, int k) {

    // 1. find length of ll
    int n = 0;
    // 2. find taial node
    node* tail = head;

    while(tail->next) {
        n++;        // finding length
        tail = tail->next;      // finding last node
    }
    n++; // for including last node

    k = k%n;
    if(k == 0 ) return head;
    tail->next = head;

    // 3. traverse n-k nodes
    node* temp = head;
    for(int i = 1; i<n-k; i++) {
        temp = temp->next;
    }
    // temp is pointing to (n-k)th node

    node* newhead = temp->next;
    temp->next = NULL;
    return newhead;

}

int main (){

    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.display();
    l1.head = rotate(l1.head, 2);
    l1.display();

}
*/








/*
// GROUP ALL NODES WITH ODD INDICES FOLLOWED BY evenptr
// 1-2-3-4-5-6  =>  1-3-5-2-4-6

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

node* arrange(node* &head) {

    if(!head) return head;

    node* evenhead = head->next;
    node* oddptr = head;
    node* evenptr = evenhead;
    while(evenptr && evenptr->next) {
        oddptr->next = oddptr->next->next;
        evenptr->next = evenptr->next->next;
        evenptr = evenptr->next;
        oddptr = oddptr->next;
    }
    oddptr->next = evenhead;
    return head;
}

int main (){

    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.display();
    l1.head = arrange(l1.head);
    l1.display();

}
*/









/*
// 1-2-3-4-5-6  =>  1-6-2-5-3
// first - last - second - second last .....

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

node* reorder (node* head) {

    // FIND MIDDLE ELEMENT
    node* slow = head;
    node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // now slow is pointing to middle element

    //BREAK LL IN MIDDLE
    node* currptr = slow->next;
    node* prevptr = slow;
    slow->next = NULL;

    // REVERSE THE SECOND HALF

    while(currptr){
        node* nextnode = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextnode;
    }

    // CHECK IF TEO LL ARE EQUAL
    node* ptr1 = head;      // LL 1 half
    node* ptr2 = prevptr;       // LL 2 second

    while(ptr1 != ptr2) {
        node* temp = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
    }
    return head;
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
    l1.head = reorder(l1.head);
    l1.display();

}
*/