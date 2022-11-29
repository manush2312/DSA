#include<iostream>
using namespace std;

class Queue{
    int *arr;   //we are making pointer because of dynamic memory allocation.. 
    int front;
    int rear;
    int size;

    public:
    Queue(){
        size = 10;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int data){  // push function.. 
        if(rear == size){
            cout << "Queue is full" << endl;
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if(front == rear){
            cout << "Queue is empty" << endl;
            return -1;
        }else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }

            return ans;
        }
    }

    int frontele(){
        if(front == rear){
            cout << "Queue is empty" << endl;
            return -1;
        }else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }else{
            return false;
        }
    }

    void print(){
        int i; 
        for(i=front; i<=rear; i++){
            cout << arr[i] << " ";
        }
    }
};

int main(){

    Queue *q = new Queue();  // used pointer because of dynamic memory allocation.. 
    q->enqueue(10);
    q->print();

    cout << endl;
    q->enqueue(23);
    q->print();

    return 0;
}
