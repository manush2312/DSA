#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char  data;
    struct Node *next;
};
void display(struct Node *first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    printf("Contents of list are:\n");
    while(first != NULL)
    {
        printf("%c\n",first->data);
     first = first->next;
    }
}
struct Node *insert_rear(char ele,struct Node *first)
{
   struct Node *ptr;
   ptr = (struct Node *)malloc(sizeof(struct Node *));
   ptr->data = ele;
   if(first == NULL)
   {
    ptr->next = NULL;
    return ptr;
   }
   struct Node *temp = first;
   while(temp->next != NULL)
   {
    temp = temp->next;
   }
   temp->next = ptr;
   ptr->next = NULL;
   return first;
}
struct Node *create(char s[])
{
    struct Node *first;
    first = (struct Node *)malloc(sizeof(struct Node *));
    first = NULL;
    int i=0;
    while (s[i] != '\0')
    {
    first = insert_rear(s[i],first);
    i++;
    }
    return first;
}
int isVowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        return 1;
        break;
        default:
        return 0;
    }
}
struct Node *delete_rear(struct Node *first)
  {
    struct Node *temp1 = first;
    struct Node *temp2 = first->next;
    while(temp2->next != NULL)
    {
        temp2=temp2->next;
         temp1=temp1->next;
    }
   temp1->next = NULL;
    free(temp2);
    return first;
  }
  struct Node *delete_front(struct Node *first)
  {
    if(first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    struct Node *t = first->next;
    free(first);
     
    return t;
  }
void allVowels(struct Node *first)
{
   struct Node *temp1 = first;
   struct Node *temp2 = first->next;
   struct Node *temp3 = first;
   while(temp2->next != NULL)
   {
      if(isVowel(temp2->data))
      {
        struct Node *temp = temp2;
        temp1->next = temp2->next;
        free(temp);
        temp2 = temp2->next;
      }
      else
      {
        temp2 = temp2->next;
      }
   }
   if(isVowel(temp2->data))
   {
      first = delete_rear(first);
   }
   if(isVowel(temp3->data))
   {
    first = delete_front(first);
   }
}
int main()
{

  #include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char  data;
    struct Node *next;
};
void display(struct Node *first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    printf("List:\n");
    while(first != NULL)
    {
        printf("%c\n",first->data);
     first = first->next;
    }
}
struct Node *insert_rear(char ele,struct Node *first)
{
   struct Node *ptr;
   ptr = (struct Node *)malloc(sizeof(struct Node *));
   ptr->data = ele;
   if(first == NULL)
   {
    ptr->next = NULL;
    return ptr;
   }
   struct Node *temp = first;
   while(temp->next != NULL)
   {
    temp = temp->next;
   }
   temp->next = ptr;
   ptr->next = NULL;
   return first;
}
struct Node *create(char s[])
{
    struct Node *first;
    first = (struct Node *)malloc(sizeof(struct Node *));
    first = NULL;
    int i=0;
    while (s[i] != '\0')
    {
    first = insert_rear(s[i],first);
    i++;
    }
    return first;
}
int isVowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        return 1;
        break;
        default:
        return 0;
    }
}
struct Node *delete_rear(struct Node *first)
  {
    struct Node *temp1 = first;
    struct Node *temp2 = first->next;
    while(temp2->next != NULL)
    {
        temp2=temp2->next;
         temp1=temp1->next;
    }
   temp1->next = NULL;
    free(temp2);
    return first;
  }
  struct Node *delete_front(struct Node *first)
  {
    if(first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    struct Node *t = first->next;
    free(first);
     
    return t;
  }
void allVowels(struct Node *first)
{
   struct Node *temp1 = first;
   struct Node *temp2 = first->next;
   struct Node *temp3 = first;
   while(temp2->next != NULL)
   {
      if(isVowel(temp2->data))
      {
        struct Node *temp = temp2;
        temp1->next = temp2->next;
        free(temp);
        temp2 = temp2->next;
      }
      else
      {
        temp2 = temp2->next;
      }
   }
   if(isVowel(temp2->data))
   {
      first = delete_rear(first);
   }
   if(isVowel(temp3->data))
   {
    first = delete_front(first);
   }
}
int main()
{

   printf("------------------------------------\n");
    printf("Registration number:-210905294\n");
    printf("------------------------------------\n");
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node *));
    head = NULL;
    char s[15];
    printf("Enter words or names: \n");
    scanf("%s",s);
    head = create(s);
    display(head);
    printf("After removing vowels :\n");
    allVowels(head);
    display(head);
    return 0;
}
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node *));
    head = NULL;
    char s[15];
    printf("Enter name\n");
    scanf("%s",s);
    head = create(s);
    display(head);
    printf("After removing vowels :\n");
    allVowels(head);
    display(head);
    return 0;
}