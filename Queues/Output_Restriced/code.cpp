#include<iostream>
using namespace std;

class OutputRes{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    OutputRes(int size){
        this->size = size;
        this->arr = new int[size];
        this->rear = -1;
        this->front = -1;
    }

    void pushback(int val){  // push using rear
        if((front==0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout << "Queue is full" << endl;
        }else if(front == -1 || rear == -1){
            front = rear = 0;
            arr[rear] = val;
        }else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = val;
        }else{
            rear++;
            arr[rear] = val;
        }
    }

    void pushfront(int val){
         if((front==0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout << "Queue is full" << endl;
        }else{
            
        }  
    }

    int popfront(){   // front se pop karna..
        if(front == -1){  // check for empty..
            cout << "Queue is Empty" << endl;
            return -1;
        }else if(front == rear){  // single element..
            int ans = arr[front];
            front = rear = -1;
            return ans;
        }else if(front == size-1){  // cyclic nature..
            int ans = arr[front];
            front = 0;
            return ans;
        }else{  // normal flow..
            int ans = arr[front];
            front++;
            return ans;
        }
    }


};


int main(){



    return 0;
}