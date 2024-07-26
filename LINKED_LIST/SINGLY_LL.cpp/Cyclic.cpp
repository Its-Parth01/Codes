/*
// DETECTION OF CYCLE

#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        // this->data = val;
        next = NULL;
        // this->next = NULL;
    }
};


void display (node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


void insert_at_tail (node* &head, int val) {
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


bool detect_cycle(node* &head) {
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL) {  // if fast is null then cycle not present
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) return true;
    }
    return false;

}

// this function is making cycle int the LL
void makecycle(node* &head, int pos) {
    node* temp = head;
    node* startnode;
    int count = 1;
    while(temp->next != NULL) {
        if(count == pos) {
            startnode = temp;
        }
        temp = temp->next;
        count ++;
    }
    temp->next = startnode;
}

int main () {

    node* head = NULL;

    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);

    makecycle(head, 3);  // make cyclic form

    cout<<detect_cycle(head)<<endl;

}
*/









/*
// REMOVAL OF THE CYCLE

#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        // this->data = val;
        next = NULL;
        // this->next = NULL;
    }
};

void display (node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


void insert_at_tail (node* &head, int val) {
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


bool detect_cycle(node* &head) {
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL) {  // if fast is null then cycle not present
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) return true;
    }
    return false;

}

// this function is making cycle int the LL
void makecycle(node* &head, int pos) {
    node* temp = head;
    node* startnode;
    int count = 1;
    while(temp->next != NULL) {
        if(count == pos) {
            startnode = temp;
        }
        temp = temp->next;
        count ++;
    }
    temp->next = startnode;
}

void remove_cycle(node* &head) {
    node* slow = head;
    node* fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while(fast->next != slow->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;

}

int main () {

    node* head = NULL;

    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);

    makecycle(head, 3);  // make cyclic form

    cout<<detect_cycle(head)<<endl;
    remove_cycle(head);
    cout<<detect_cycle(head)<<endl;
    display(head);

}
*/
