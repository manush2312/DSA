#include<stdio.h>
#include<stdlib.h>

int *subset;
int cost;
int l=0;

int max(int a, int b){
    return a>b ? a:b;
}

void KnapSack(int **KS, int n, int w, int *V, int *W){
        int i, j, k;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=w; j++){
                KS[i][j] = 0;  // initialising all the values to zero..
            }
        }

         for(int i=1; i<=n; i++){
            for(int j=1; j<=w; j++){
                if(j-W[i] >= 0){
                    KS[i][j] = max(KS[i-1][j], V[i]+KS[i-1][j-W[i]]);
                }else{
                    KS[i][j] = KS[i-1][j];
                }
            }

         }

         j=w;
         for(int i=n; i>0; i--){
            if(KS[i][j] != KS[i-1][j]){
                cost =+ V[i];
                subset[l++] = i;
                j = j-W[i];
            }
         }

}


int main(){
    int n; // no.of items
    int w;  // capacity of knapsack
    printf("Enter the number of items:\n");
    scanf("%d", &n);
    printf("Enter the the capacity of knapsack:\n");
    scanf("%d",&w);

    int V[n+1],W[n+1];
    V[0] = W[0] = 0;      // we are initialising this as zero for further benefits..
    printf("Enter the weights:\n");
    for(int i=1; i<=n; i++){
        scanf("%d", &W[i]);
    }
    printf("Enter the Values:\n");
    for(int i=1; i<=n; i++){
        scanf("%d", &V[i]);
    }

    int **KS = (int **)malloc((n+1) * sizeof(int *));
    for(int i=0; i<=n; i++){
        KS[i] = (int *)malloc((w+1) *sizeof(int));
    }

    subset = (int *)malloc((n+1)*sizeof(int));   // for including the itmes that we putting in the knapSack..
    KnapSack(KS, n, w, V, W); 

    printf("\nKnapSack Table is \n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            printf("%d\t",KS[i][j]);
        }
        printf("\n");
    }

    printf("\nKnapSack Items are : \t");
    for(int i=l;i>0;i--)
    {
        printf("%d ",subset[i]);
    }
    printf("\n\nCost is : %d\t",cost);

    return 0;
}