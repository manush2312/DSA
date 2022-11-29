#include<iostream>
using namespace std;

class CircularQueue{
    public:
    int *arr;
    int front;
    int size;
    int rear;

    CircularQueue(int size){
        this->size = size;
        this->arr = new int[size];
        this->front = -1;  
        this->rear = -1;
    }

    bool push(int val){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){   // full hai ke nhi wo check karne ke liye
            cout << "Queue is full" << endl;
            return false;
        }else if((front == -1) || (rear == -1)){  // first element indertion..
            front = rear = 0;
            arr[rear] = val;
            return true;
        }else if(rear == size-1 && front != 0){  // circular nature..
            rear = 0;
            arr[rear] = val;
            return true;
        }else{
            rear++;  // normal flow..
            arr[rear] = val;
            return true;
        }
    }

    int pop(){
        if(front == -1){
            cout << "Queue is Empty" << endl;
            return -1;
        }else if(front == rear){  // agar single element hua toh uske liye condition.. 
            int ans = arr[front];
            front = rear = -1;
            // cout << ans << endl;
            return ans;
        }else if(front == size-1){   // circular nature..
            int ans = arr[front];
            front = 0;
            return ans;
        }else{
            int ans = arr[front];   // normal flow..
            front++;
            return ans;
        }
    }

    void display(){
        if(front == -1 ){
            cout << "---Queue is Empty---" << endl;
        }else if(rear >= front){
            for(int i = front; i<=rear; i++){
                cout << arr[i] << " ";
            }
        }else{
            for(int i = front; i<size; i++){
                cout << arr[i] << " ";
            }

            for(int i =0; i<=rear; i++){
                cout << arr[i] << " ";
            }
        }
    }

};


int main(){
    int n,choice;
    cout << "Enter the soze of the Queue:" << endl;
    cin >> n;
    CircularQueue *s1 = new CircularQueue(n);

    do{
        cout << "Enter the valid chooice" << endl;
        cout << "1.Push\n2.Pop\n3.Display\n4.Exit" << endl;
        cin >> choice;
        switch(choice){
            case 1:{
                int val;
                cout << "\nEnter the number to be pushed:" << endl;
                cin >> val;
                s1->push(val);
                break;
            }

            case 2:{
                int ele = s1->pop();
                cout << ele << endl;  // prints the popped element..
                break;
            }

            case 3:{
                s1->display();
                break;
            }

            case 4:{
                cout << "---EXITING---" << endl;
                break;
            }
        }

    }while(choice != 4);
    


    return 0;
}