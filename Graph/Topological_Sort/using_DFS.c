#include<stdio.h>
#include<stdlib.h>

int n, *visited, *topo, **adj;
int k=0;


void DFS(int i){
    visited[i] = 1;

    // checking for the adjacent nodes
    for(int j=0; j<n; j++){
        if((adj[i][j] == 1) && (visited[j] == 0)){
            
            DFS(j);
        }
    }

    topo[k++] = i;
    
}

int main(){
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    visited = (int *)malloc(n * sizeof(int));
    topo = (int *)malloc(n * sizeof(int));
    adj = (int **)malloc(n * sizeof(int*));

    printf("Enter the adjacency Matrix:\n");
    for(int i=0; i<n; i++){
        visited[i] = 0;
        adj[i] = (int *)malloc(n * sizeof(int));

        for(int j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    DFS(0);

    // printing the DFS in the reverse order:
    for(int i=n-1; i>=0; i--){
        printf("%d", topo[i]);
    }



    return 0;
}