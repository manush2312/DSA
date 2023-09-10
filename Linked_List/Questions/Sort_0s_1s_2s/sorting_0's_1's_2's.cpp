
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

void sortLinkedList(Node *&head){

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node *temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }
        else if(temp->data == 1){
            oneCount++;
        }
        else if(temp->data == 2){
            twoCount++;
        }

        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }

        temp = temp->next;
    }


}

int main(){

    Node *s = NULL;

    insertAtHead(s, 0);
    insertAtHead(s, 1);
    insertAtHead(s, 1);
    insertAtHead(s, 0);
    insertAtHead(s, 2);
    insertAtHead(s, 0);
    insertAtHead(s, 2);
    insertAtHead(s, 2);
    insertAtHead(s, 1);
    insertAtHead(s, 1);

    cout << "Before Sorting: ";
    print(s);

    sortLinkedList(s);
    cout << "After Sorting: ";
    print(s);

    return 0;
}