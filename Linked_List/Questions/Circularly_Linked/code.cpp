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
        Node *temp = new Node(data);
        head = temp;
    }else{
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}


void linkingLinkedList(Node *&head){

    Node *temp = head->next;
    while(temp->next != NULL){
        temp = temp->next;
    }

    // creating a circular link between last node and head node
    temp->next = head;

}


bool isCircularList(Node *&head){

    if(head == NULL){
        return true;
    }

    Node *temp = head->next;

    while(temp != NULL && temp != head){
        temp = temp->next;
    }

    if(temp == head){
        return true;
    }

    return false;
}

void print(Node *head){
    
    Node *curr = head;

    while(curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    
}

int main(){

    Node *s = NULL;
    insertAtHead(s, 12);
    insertAtHead(s, 11);
    insertAtHead(s, 10);
    insertAtHead(s, 9);

    print(s);

    // creating a circular link
    linkingLinkedList(s);
    //print(s);
    cout << endl;

    if(isCircularList(s)){
        cout << "Yes it is Circularly Linked" << endl;
    }else{
        cout << "NO it is not Circularly Linked" << endl;
    }




    return 0;
}