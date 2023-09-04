#include<stdio.h>
#include<stdlib.h>

int n;
int *visited, **adj;


void DFS(int i){
  visited[i] = 1;
  printf("%d", i);
  for(int j=0; j<n; j++){

    if((adj[i][j]==1) && (visited[j] == 0)){
      DFS(j);
    }
  }

  
}
 
void main(){
  printf("Enter the number of vertices:\n" );
  scanf("%d", &n);

  visited = (int *)malloc(n * sizeof(int ));
  adj = (int **)malloc(n * sizeof(int *));

  printf("Enter the adjacency matrix:\n");
  for(int i=0; i<n; i++){
    visited[i] = 0;
    adj[i] = (int *)malloc(n*sizeof(int));

    for(int j=0; j<n; j++){
      scanf("%d", &adj[i][j]);
    }
  }

  DFS(0); 




}