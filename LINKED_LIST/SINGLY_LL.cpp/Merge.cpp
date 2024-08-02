
// MERGE TWO SORTED LL (IN THIS WE ARE JUST CHANGING LINKS BTW NOT CREATING ANY NEW NODE OR LL)

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

node* mergell(node* &head1, node* &head2) {

    node* dummy_headnode = new node (-1);
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* ptr3 = dummy_headnode;

    while (ptr1 && ptr2) {  // ptr1 != NULL && ptr2 != NULL
        if (ptr1->data < ptr2->data) {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if(ptr1) {  // ptr1 is still NULL
        ptr3->next = ptr1;
    }
    else {  // ptr2 is NULL
        ptr3->next = ptr2;
    }
    return dummy_headnode->next;
}

int main (){

    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(3);
    l1.insert_at_tail(5);
    l1.display();

    linkedlist l2;
    l2.insert_at_tail(2);
    l2.insert_at_tail(4);
    l2.insert_at_tail(6);
    l2.insert_at_tail(7);
    l2.insert_at_tail(8);
    l2.display();

    linkedlist l3;
    l3.head = mergell(l1.head, l2.head);
    l3.display();

}







/*
// MERGE MULTIPLE LL

#include<iostream>
#include<vector>
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

node* mergell(node* &head1, node* &head2) {

    node* dummy_headnode = new node (-1);
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* ptr3 = dummy_headnode;

    while (ptr1 && ptr2) {  // ptr1 != NULL && ptr2 != NULL
        if (ptr1->data < ptr2->data) {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if(ptr1) {  // ptr1 is still NULL
        ptr3->next = ptr1;
    }
    else {  // ptr2 is NULL
        ptr3->next = ptr2;
    }
    return dummy_headnode->next;
}

node* merge_k_ll(vector <node* > &lists)
{
    if(lists.size() == 0) {
        return NULL;
    }

    while(lists.size() > 1)
    {
        node* mergehead =  mergell(lists[0], lists[1]);
        lists.push_back(mergehead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());

    }
    return lists[0];
}

// vector =>  H1 H2 H3 H4
// first H1 and H2 ll will merge
// vector =>  H1 H2 H3 H4 mergehead 1_2
// vector =>  H3 H4 mergehead 1_2
// then H3 and H4 ll will merge
// vector =>  mergehead 1_2 mergehead 3_4
// then mergehead 1_2 && mergehead 3_4 will merge
// vector =>  mergehead 1_2      mergehead 3_4      mergehead 1_2_3_4
// vector => mergehead 1_2_3_4



int main (){

    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(4);
    l1.insert_at_tail(9);
    l1.display();

    linkedlist l2;
    l2.insert_at_tail(3);
    l2.insert_at_tail(5);
    l2.insert_at_tail(7);
    l2.display();

    linkedlist l3;
    l3.insert_at_tail(2);
    l3.insert_at_tail(6);
    l3.insert_at_tail(8);
    l3.display();

    vector <node* > lists;
    lists.push_back(l1.head);
    lists.push_back(l2.head);
    lists.push_back(l3.head);


    linkedlist Mergerll;
    Mergerll.head = merge_k_ll(lists);
    Mergerll.display();

}
*/
