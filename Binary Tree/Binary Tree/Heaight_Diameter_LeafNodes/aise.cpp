//remove duplicates then merge two linked lists
#include<iostream>
using namespace std;

class node
{
    public:

    node *next;
    int info;
    node()
    {
        next=NULL;
    }
};

class SLL
{
    public:

    node* insert(node *head)
    {
        node *temp=new node;
        cout<<"Enter info"<<endl;
        cin>>temp->info;
        if(head==NULL)
        {
            head=temp;
            return head;
        }
        else
        {
            node *ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;

            return head;
        }
    }

    void display(node *head)
    {
        node *ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->info<<"->";
            ptr=ptr->next;
        }
    }

    void sort(node *head)
    {
        int a, b;

        if(head==NULL)
        {
            cout<<"list does not exist"<<endl;

        }
        else
        {
            node *temp=head;
            node *ptr=head;
            node *mini;
            while(ptr!=NULL)
            {
                mini=ptr;
                node *t2=ptr->next;
                while(t2!=NULL)
                {
                    if(t2->info<mini->info)
                    {
                        mini=t2;
                    }
                    t2=t2->next;
                }
                if(mini!=ptr)
                {
                    swap(mini->info,ptr->info);
                }

                ptr=ptr->next;
            }

        }
    }

    void removeD(node *head)
    {
        node *temp=head;
        sort(temp);
        
        while(temp!=NULL)
        {
            node *t2= temp->next;
            node *ptr=t2;
            if((t2!=NULL) && (temp->info==t2->info))
            {
                temp->next=t2->next;
                delete(ptr);
            }

            temp=temp->next;
        }
    }

    void removeunsortD(node *head)
    {
        node *temp=head;
        node *t=temp;

        while(temp!=NULL)
        {
            node *t2= temp->next;

            while(t2!=NULL )
            {
                //t->next=ptr;
                
                if((t2!=NULL) && (t2->info==temp->info))
                {
                    node *ptr=t2;
                    t2=t2->next;
                    t->next=t2;
                    ptr->next=NULL;
                    delete(ptr);
                }

                // else{
                // t=t->next;
                // t2=t2->next;
                // }

            }
            temp=temp->next;
        }
    }


};

int main()
{
    SLL s1;
    node *head=NULL;
    int x;
    do
    {
        cout<<"\n1.Insert\n2.Display\n3.Sort\n4.Remove duplicates\n5.unsorted duplicate deletion\n";
        cin>>x;

        switch(x)
        {
            case 1:
            head=s1.insert(head);
            break;

            case 2:
            s1.display(head);
            break;


            case 3:
            s1.sort(head);
            break;

            case 4:
            s1.removeD(head);
            break;


            case 5:
            s1.removeunsortD(head);
            break;

            default:
            cout<<"EXITING...";
            break;
        }
    } while (x!=6);
    
    
}