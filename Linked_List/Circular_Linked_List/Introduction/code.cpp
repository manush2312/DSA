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

void insertNode(Node *&tail, int d){
  
    if(tail == NULL){
        Node *newNode = new Node(d);
        newNode->next = newNode;
        tail = newNode;
        
    }else{
        
        Node *temp = new Node(d);
        temp->next = tail->next;
        tail->next = temp;
    }
}

void print(Node *tail){
    
    Node *temp = tail->next;
    Node *head = temp;
    do{
       
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
}

int main(){
    int first_data;
    Node *s;
    cout << "Enter the first data for the Linked List: " << endl;
    cin >> first_data;

    insertNode(s, first_data);
    insertNode(s, 23);
    insertNode(s, 34);
    insertNode(s, 44);
    insertNode(s, 45);

    print(s);

    


    return 0;
}