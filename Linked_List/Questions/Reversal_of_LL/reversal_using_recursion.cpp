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

void reversingLLUsingRecursion(Node *&head, Node *curr, Node *prev){
    
    // Node *curr = head;
    // Node *prev = NULL;

    if(curr == NULL){
        head = prev;
        return;
    }

    Node *forward = curr->next;
    reversingLLUsingRecursion(head, forward, curr);

    curr->next = prev;

}


void print(Node *head){

    Node *curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

}

int main(){

    Node *s = NULL;
    insertAtHead(s, 12);
    insertAtHead(s, 13);
    insertAtHead(s, 15);
    cout << "Before Reversing: " << endl;
    print(s);

    Node *curr = s;
    Node *prev = NULL;
    reversingLLUsingRecursion(s, curr, prev);
    cout << "After Reversal: " << endl;
    print(s);

    return 0;
}

