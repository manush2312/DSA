#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node *&head, int d){
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail, int d){
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int d, int position){
    
    // for first position
    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    
    Node *temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }

    //for last position
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }
    
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

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

    int first_data;
    cout << "Enter the data for the first Node: " << endl;
    cin >> first_data;

    Node *s = new Node(first_data);
    Node *head = s;
    Node *tail = s;

    insertAtHead(head, 20);
    insertAtTail(tail, 30);
    insertAtHead(head, 50);
    print(head);
    insertAtPosition(head, tail, 60, 3);
    print(head);

    

    return 0;
}