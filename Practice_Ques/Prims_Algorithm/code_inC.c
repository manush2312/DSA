#include<stdio.h>
#define MAX 9999;

int findMinVertex(int distance[], int visited[], int v){
    int minVal = MAX;
    int minIndex;

    for(int i=0; i<v; i++){
        if((visited[i] == 0) && distance[i] < minVal){
            minIndex = i;
            minVal = distance[i];
        }
    }

    return minIndex;
}

int min(int a, int b){
    return a>b ? a:b;
}

int max(int a, int b){
    return a>b ? b:a;
}

int main(){

    printf("Enter the number of vertices: \n");
    int v;
    scanf("%d",&v);
    printf("Enter the no.of edges:\n");
    int e;
    scanf("%d",&e);

    int distance[v];
    int visited[v];
    for(int i=0; i<v; i++){
        visited[i] = 0;
    }
    int parent[v];

    for(int i=1; i<v; i++){
        distance[i] = MAX;
    }
    distance[0] = 0;

    int adj[v][v];
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            adj[i][j] = 0;
        } 
    }

    printf("Enter the edges:\n");
    printf("Enter the source destination and weight:\n");
    for(int i=0; i<e; i++){
        int s, d,c;
        scanf("%d %d %d",&s, &d, &c);
        adj[s][d] = c;
    }

    for(int i=0; i<v-1; i++){
        int curr = findMinVertex(distance, visited, v);
        visited[curr] = 1;

        for(int j=0; j<v; j++){
            if((visited[j] == 0) && adj[curr][j] != 0){
                if(distance[j] > adj[curr][j]){
                    distance[j] = adj[curr][j];
                    parent[j] = curr;    // important..
                }
            }
        }
    }

    printf("Graph is:\n");
    for(int i=1; i<v; i++){
        printf("%d  --->  %d   : %d\n", min(parent[i], i), max(parent[i], i), distance[i]);
    }





    return 0;
}