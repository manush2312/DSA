#include<stdio.h>
#include<stdlib.h>

void display(int top1, int top2, int arr[], int n){
    printf("displaying the elements:");
    int i=0;
    for(i=top2; i<=top1; i--)
    {
        printf("%d\n",arr[i]);
    }
}

void pushfront(int top1, int top2, int arr[]){
    int ele;
    if(top2-top1>1){
        printf("Enter the element to be inserted:\n");
        scanf("%d",&ele);
        top1++;
        arr[top1] = ele;
    }else{
        printf("---STACK OVERFLOW---");
    }
}

void pushback(int top1, int top2, int arr[]){
    int ele;
    if(top2-top1>1){
        printf("Enter the element to be inserted:\n");
        scanf("%d",&ele);
        top2--;
        arr[top2] = ele;
    }else{
        printf("---STACK OVERFLOW---");
    }
}

int popfront(int top1, int top2, int arr[])
{
    if(top1>=0){
        int ans = arr[top1];
        top1--;
        return ans;
    }else{
        return -1;
    }
}

int popback(int top1, int top2, int arr[], int n){
    if(top2<=n){
        int ans = arr[top2];
        top2++;
        return ans;
    }else{
        return -1;
    }
}

int main(){
    int top1, top2, n, choice;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    
    //arr = (int*)calloc(n,sizeof(int));
    int arr[n];
    top1 = -1; 
    top2 = n;

    printf("---Basic 2 Stacks in an Array Operations are: ---\n");
    do{
        printf("Enter the valid choice:\n1.PUSH FRONT\n2.PUSH BACK\n3.POP FRONT\n4.POP BACK\n5.DISPLAY\n6.EXIT\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:{
                pushfront(top1,top2,arr);
                break;
            }

            case 2:{
                pushback(top1,top2,arr);
                break;
            }

            case 3:{
                popfront(top1,top2,arr);
                break;
            }

            case 4:{
                popback(top1,top2,arr,n);
                break;
            }

            case 5:{
                display(top1,top2,arr,n);
                break;
            }

            case 6:{
                printf("----Exiting----");
                break;
            }

        }

    }while(choice != 6);


    return 0;
}