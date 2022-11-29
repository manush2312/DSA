#include<iostream>
using namespace std;

class InputRes{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    InputRes(int size){
        this->size = size;
        this->arr = new int[size];
        this->rear = -1;
        this->front = -1;
    }

    void pushback(int val){   // push from rear side..
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout<< "Queue is full" << endl;
        }else if(front == -1 || rear == -1){   // first element daalne ke liye..
            front = rear = 0;
            arr[rear] = val;
        }else if(rear == size-1 && front != 0){  // cyclic nature 
            rear = 0;
            arr[rear] = val;
        }else{   // normal flow..
            rear++;
            arr[rear] = val;
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


    int popback(){   // rear se pop karna hai...
        if(rear == -1){
            cout << "Queue is Empty" << endl;
            return  -1;
        }else if(front == rear){
            int ans = arr[rear];
            front = rear = -1;
            return ans;
        }else{
            int ans = arr[rear];
            rear--;
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
    cout << "Enter the size of the Queue:" << endl;
    cin >> n;
    InputRes *s1 = new InputRes(n);   // crreated a queue..
    do{
        cout << "---Enter the valid choice:---" << endl;
        cout << "1.Push from Rear\n2.Pop from Front\n3.Pop from Rear\n4.Display\n5.Exit" << endl;
        cin >> choice;
        switch(choice){
            case 1:{
                int val;
                cout << "Enter the element to be pushed" << endl;
                cin >> val;
                s1->pushback(val);
                break;
            }

            case 2:{
                int ele = s1->popfront();
                cout << ele << endl;
                break;
            }

            case 3:{
                int ele = s1->popback();
                cout << ele << endl;
                break;
            }

            case 4:{
                s1->display();
                break;
            }

            case 5:{
                cout << "----EXITING----" << endl;
                break;
            }
        }
    }while(choice != 5);



    return 0;
}