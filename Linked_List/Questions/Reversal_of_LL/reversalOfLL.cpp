#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int d){
        this->data = d;
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

void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



Node * reversalOfLL(Node *&head){

    //if empty list or only one element is present then return as it is
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;   // for keeping track of linked list
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;

}



int main(){

    int first_data;
    Node *s = NULL;
    cout << "Enter the data for the first Node: ";
    cin >> first_data;
    cout << endl;

    insertAtHead(s, first_data);
    insertAtHead(s, 23);
    insertAtHead(s, 33);
    insertAtHead(s, 45);

    cout << "Linked List before Reversal: " ;
    print(s);
    cout << endl;


    cout << "Linked List after Reversal: " ;
    Node *p = reversalOfLL(s);
    print(p);


    return 0;
}