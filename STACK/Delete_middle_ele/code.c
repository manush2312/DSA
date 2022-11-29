// deleting the element from the stack--->>.

#include<stdio.h>

int stack[10];
int top = -1;

void push(){
    int num;
    if(10-top>1){
        printf("Enter the element to be inserted:");
        scanf("%d",&num);
    }else{
        printf("---Overflow---");
    }
}

void delete(){
    printf("%d",top);
}



int main(){
    int choice;


    do{
    printf("Enter the valid choice:\n1.Push\n2.Delete Middle Element\n3.Dislay\n4.Exit\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:{
            push();
            break;
        }

        case 2:{
            delete();
            break;
        }

        case 3:{
            //display();
            break;
        }

        case 4:{
            printf("---Exiting---");
            break;
        }
    }


    }while(choice != 4);


    return 0;
}