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

void insertAtTail(Node *&tail, int d){
    Node *temp = new Node(d);  // creation of new node..
    tail->next = temp;
    tail = temp;   // or tail = tail -> next..
}

void insertAtHead(Node *&head, int d){
    Node *temp = new Node(d);  // creation of new node..
    temp->next = head;  // pointing to next node..
    head = temp;  // shifting head..
}

void print(Node *&head){
    Node *temp = head; // creating a temp node for traversing..

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    int choice,data;
    Node *s = new Node(15);  // creation of first node.. 
    Node *head = s;  // creation of head reference
    Node *tail = s;
    do{
        cout << "Enter the valid choice:" << endl;
        cout << "1. Insert at Head\n2.Insert at Tail\n3.Display\n4.Exit" << endl;
        cin >> choice;

        if(choice == 1){
            cout << "Enter the data of the node" << endl;
            cin >> data;
            insertAtHead(head,data);
        }else if(choice == 2){
            cout << "Enter the data of the node" << endl;
            cin >> data;
            insertAtTail(tail,data);
        }else if(choice == 3){
            print(head);
        }else{
            cout << "---Exiting---" << endl;
        }
        
    }while(choice != 4);

    return 0;

    }