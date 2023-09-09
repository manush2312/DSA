/*
Detect and Remove Loops

Our task is to:-
--> Detect cycle in Linked List
--> Remove cycle from Linked List
--> We need to give output as beginning/start node of loop in Linked List
*/



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


Node * floydDetectionLoop(Node * head){
    
    if(head == NULL){
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while(slow != NULL && fast != NULL){
        
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        slow = slow->next;
        
        if(slow == fast){
            return slow;
        }
    }

    return NULL;

}


Node * startingPointOfLoop(Node *&head, Node *&PointOfIntersection){
    // PointOfIntersection  --> point where fast and slow met for the first time in "floydDetectionLoop"

    if(head == NULL){
        return NULL;
    }

    Node *slow = PointOfIntersection;
    Node *fast = PointOfIntersection;

    slow = head;

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    // returns the starting point of loop
    return slow;
    
}



void creatingLoop(Node *&head){

   Node *temp = head;
   Node *curr = head;
   Node *end = head;

   while(end->next != NULL){
    end = end->next;
   }
   cout << "End Node: "<< end->data << endl;

   // linking the end node to Node with data 11
   while(curr->data != 11){
    curr = curr->next;
   }
   cout << "Data of curr is : "<< curr->data << endl << endl; 
    // creating a link
    end->next = curr;

    // below should print "11" as to make sure loop is created
    //cout << "New : " << end->next->data << endl;

}


void removeLoop(Node *&head, Node *&startingOfLoop){

    Node *temp = startingOfLoop;
    while(temp->next != startingOfLoop){
        temp = temp->next;
    }

    // pointing the node previous to "StartingPointOfLoop" to "NULL" to break the loop
    temp->next = NULL;

    // checking for the loop once again
    Node *LoopCheckingAgain = floydDetectionLoop(head);
    if(LoopCheckingAgain){
        cout << endl << "Still Present" << endl;
    }else{
        cout << "Loop Removed Successfully" << endl;
    }

}



void print(Node *head){

    Node *temp = head;
    cout << "Linked List : ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}



int main(){

    Node *s = NULL;

    insertAtHead(s, 2);
    insertAtHead(s, 1);
    insertAtHead(s, 20);
    insertAtHead(s, 15);
    insertAtHead(s, 11);
    insertAtHead(s, 9);
    insertAtHead(s, 8);
    insertAtHead(s, 6);

    print(s);

    creatingLoop(s);

    Node *LoopPresent = floydDetectionLoop(s);
    if(LoopPresent){
        cout << "Yes Loop is Present" << endl;
        cout << "Slow and Fast meet at: " << LoopPresent->data << endl;
    }else{
        cout << "Loop is not present" << endl;
    }

    Node *starting = startingPointOfLoop(s, LoopPresent);
    cout << "Starting Point is: " << starting->data << endl;

    removeLoop(s, starting);
    

    return 0;
}