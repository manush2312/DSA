#include<stdio.h>

// creating queue data structure using arrays
int queue[100];

// defining pointers of the queue to perform pop and push
int front=0,back=0;

// defining push operation on the queue
void push(int var)
{
    queue[back] = var;
    back++;
}

// defining pop operation on queue
void pop()
{
    queue[front] = 0;
    front++;
}

// creating a visited array to keep the track of visited nodes
int visited[7] = {0};

int main()
{
    // defining the number of total persons 
    int N  = 6;

    // adjacenty matrix representing graph
    int graph[6][6] = {{0,1,1,0,0,0},
                     {1,0,1,0,0,0},
                     {1,1,0,1,1,0},
                     {0,0,1,0,0,0},
                     {0,0,1,0,0,1},
                     {0,0,0,0,1,0}};
    
    // front == back stands for empty queue 
    // until queue is not empty perfroming bfs 


    // adding a starting node in the list 
    push(1);
    visited[0] = 1; // marking 1st node as visited 
    while(front != back)  // jab tak queue empty na ho 
    {
        int current = queue[front];
        
        // printing current element 
        printf("%d ", current);
        
        // popping the front element from the queue
        pop();
 
        for(int i=0;i<6;i++)
        {
            // adding non-visited connected nodes of the current node to the queue 
            if((graph[current-1][i] == 1) && (visited[i] == 0))
            {
                visited[i] = 1; // marking visisted
                push(i+1);
            }
        }
    }
    return 0;
}


// below code is an example:

/*

#include<stdio.h>

int queue[100];

int front=0, rear=0;

void push(int var){
    queue[rear] = var;
    rear++;
}

void pop(){
    queue[front] = 0;
    front++;
}

int visited[6] = {0};

int main(){
    int n = 5;

    int graph[5][5] = {{0,0,1,1,0},
                        {0,0,0,1,1},
                        {1,0,0,0,1},
                        {1,1,0,0,0},
                        {0,1,1,0,0}};

    push(0); 
    visited[0] = 1;

    while(front != rear){
        int current = queue[front];

        printf("%d", current);
        pop();


        for(int i=0; i<5; i++){
            if((graph[current][i] == 1) && (visited[i] == 0)){
                visited[i] = 1;
                push(i);
            }
        }
    }

    return 0;
}




*/