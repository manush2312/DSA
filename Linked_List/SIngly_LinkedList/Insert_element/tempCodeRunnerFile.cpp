#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next  =NULL;
    }
};

void insertAtHead(Node *&head, int d){
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d){
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " ->";
        temp = temp->next;
    }
}

void insertAtPOsition(Node *&head, Node *&tail, int position, int ele){
    Node *temp = head;
    int count = 1;

    if(position == 1){
        insertAtHead(head, ele);
        
    }else{

    while(count < position -1){
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        insertAtTail(tail, ele);
        return;
    }

    Node *insert = new Node(ele);
    insert->next = temp->next;
    temp->next = insert;
    }

}

int main(){
    int choice,data, first_data,position,ele;

    cout << "Enter the data for first node" << endl;
    cin >> first_data;
    Node *s = new Node(first_data);  // creation of first node
    Node *head = s;
    Node *tail = s;
   do{
        cout << "Enter the valid choice:" << endl;
        cout << "1. Insert at Head\n2.Insert at Tail\n3.Display\n4.Insert at Position\n5.Exit" << endl;
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
        }else if(choice == 4){
            cout << "Enter the Postion and Element to be Inserted:" <<endl;
            cin >> position;
            cin >> ele;
            insertAtPOsition(head,tail,position,ele);
        }
        else{
            cout << "---Exiting---" << endl;
        }
        
    }while(choice != 5);
}