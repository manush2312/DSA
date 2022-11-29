#include<iostream>
#include<queue>
using  namespace std;


int main(){

    queue<int> q;  // creating a queue of type int..

    q.push(11);
    cout << "Front of queue is:" << q.front() << endl;
    q.push(15);
    cout << "Front of queue is:" << q.front() << endl;
    q.push(20);
    cout << "Size of queue is:" << q.size() << endl;
    q.pop();
    cout << "Front of queue is:" << q.front() << endl;
    cout << "Size of queue is:" << q.size() << endl;

    if(q.empty())
    {
        cout << "queue is empty" << endl;
    }else{
        cout << "queue is not empty" << endl;
    }

    return 0;
}