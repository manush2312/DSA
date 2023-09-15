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

void print(Node *head){

    Node *temp = head;
    
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}


int main(){

    Node *LL1 = NULL;
    Node *LL2 = NULL;

    insertAtHead(LL1, 6);
    insertAtHead(LL1, 4);
    insertAtHead(LL1, 3);
    insertAtHead(LL1, 1);

    insertAtHead(LL2, 8);
    insertAtHead(LL2, 7);
    insertAtHead(LL2, 5);
    insertAtHead(LL2, 2);

    cout << "Linked List 1 : ";
    print(LL1);
    cout << endl;
    cout << "Linked List 2 : ";
    print(LL2);
    cout << endl;

    return 0;
}