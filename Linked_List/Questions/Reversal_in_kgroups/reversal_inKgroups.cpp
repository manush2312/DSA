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

void insertAtHead(Node *&head, int data){

    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
    }else{
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

}

Node * KReverse(Node *&head, int k){

    if(head == NULL){
        return NULL;
    }

    // step-1 :- reverse first "K" Nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step-2 :- Recursion will do REST
    if(next != NULL){
        head->next = KReverse(next, k);
    }

    // step-3 :- updating the HEAD
    return prev;

}

void print(Node *&head){
    
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

int main(){

    Node *s = NULL;

    insertAtHead(s, 50);
    insertAtHead(s, 40);
    insertAtHead(s, 30);
    insertAtHead(s, 20);
    insertAtHead(s, 10);
    insertAtHead(s, 0);

    print(s);

    cout << "After Reversing in the groups of 2: " << endl;
    Node *p = KReverse(s, 2);
    print(p);
    


    return 0;
}