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

void print(Node *head){
    
    Node *curr = head;
    cout << "Linked List: "; 

    while(curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    
}

void removeDuplicatesFromSortedLinkedList(Node *&head){

    Node *curr = head;

    while(curr != NULL){
        if((curr->next != NULL) && (curr->data == curr->next->data)){
            Node *temp = curr->next;
            curr->next = temp->next;
            temp->next = NULL;
            delete temp;
        }else{
            
            curr = curr->next;

        }
    }

}

int main(){

    Node *s = NULL;
    insertAtHead(s, 10);
    insertAtHead(s, 10);
    insertAtHead(s, 10);
    insertAtHead(s, 8);
    insertAtHead(s, 7);
    insertAtHead(s, 7);
    insertAtHead(s, 5);
    insertAtHead(s, 4);
    insertAtHead(s, 4);
    insertAtHead(s, 1);

    print(s);

    removeDuplicatesFromSortedLinkedList(s);
    cout << endl << "After Removing Duplicates: ";
    print(s);


    return 0;
}