#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtTail(Node *&tail, int data){

    if(tail == NULL){
        Node *newNode = new Node(data);
        tail = newNode;
    }

    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;

}


Node * sortList(Node *&head){

    int value;

    // creating 3 new Linked List
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    while(curr != NULL){
        value = curr->data;
        
        if(value == 0){
            InsertAtTail(zeroTail, 0);
        }
        else if(value == 1){
            InsertAtTail(oneTail, 1);
        }
        else if(value == 2){
            InsertAtTail(twoTail, 2);
        }

        curr = curr->next;
    }

    // merging 3 new Linked List
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;


    return head;

}


void print(Node *head){
    
    Node *curr = head;
    cout << "Linked List: "; 

    while(curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    
}

int main(){

    cout << "Helloo" << endl;

    Node *s = new Node(2);
    Node *head = s;
    Node *tail = s;

    InsertAtTail(tail, 0);
    InsertAtTail(tail, 0);
    InsertAtTail(tail, 1);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 0);
    InsertAtTail(tail, 1);
    InsertAtTail(tail, 1);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 2);

    cout << "Before Sorting: " ;
    print(head);

    Node *sorted = sortList(head);
    cout << endl << "After Sorting: ";
    print(sorted);


    return 0;

}

