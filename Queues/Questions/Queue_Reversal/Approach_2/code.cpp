// Queue reversal in a recursive way..

#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int size){
        this->size = size;
        this->arr = new int[size];
        this->front = 0;
        this->rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout << "Queue is full" << endl;
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    int pop(){
        if(front == rear){
            cout << "Queue is Empty" << endl;
            return -1;
        }else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            return ans;
        }
    }

    int SizeOfQueue(){
        int size = 0;
        for(int i = front; i<=rear; i++){
            size++;
        }
        return size;
    }

    int frontele(){
        if(front == rear){
            cout << "Queue is Empty" << endl;
            return -1;
        }else{
            int f_ele = arr[front];
            return f_ele;
        }
    }

    void print(){
        for(int i = front; i<+rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    Queue* reverse(Queue *q){
        // base case
        if(q->SizeOfQueue() == 0){
            return q; 
        }

        int ele = q->frontele();  // storing of front element of the queue..
        q->pop();

        reverse(q);

        q->push(ele);
    }
};


int main(){
     int size,data;
    cout << "Enter the size of the queue" << endl;
    cin >> size;
    
    Queue *q = new Queue(size);
    cout << "Enter the elements of the queue" << endl;
    for(int i = 0; i < size; i++){
        cout << "Enter the element you want to push" <<endl;
        cin >> data;
        q->push(data);
    }

    q->print();
    cout << endl;

    Queue *rev = q->reverse(q);
    rev->print();
    
    
}