// Queue Reversal using stack..

#include<iostream>
using namespace std;
#include <stack>

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


    void print(){
        for(int i = front; i<+rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int frontele(){
        if(front == rear){
            cout << "Queue is Empty" << endl;
        }else{
            int ans = arr[front];
            return ans;
        }
    }

    bool empty(){
        if(front == rear){
            return true;
        }else{
            return false;
        }
    }

    Queue* revrse(Queue *q){
        stack <int> s;   //creating a stack of type int and name "s"..
        
        while(!q->empty()){
            int ele = q->frontele();
            q->pop();
            s.push(ele);
        }

        while(!s.empty()){
            int ele = s.top();
            s.pop();
            q->push(ele);
        }

        return q;
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
    //cout << q->arr[q->front] << endl;

    Queue *rev = q->revrse(q);   // creating a new refernce "rev" and then calling function..
    cout << "The reversed queue is" << endl;
    rev->print();


}