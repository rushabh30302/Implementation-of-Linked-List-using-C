#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head,*temp,*r,*r1;

void create()
{
    int n,i;
    printf("Enter no of nodes\n");
    scanf("%d",&n);
    struct node *newnode,*temp;
    head=0;
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if (head==0)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;

        }
    }
}

void display()
{
    if (head==0)
    {
        printf("The list is empty.\n");
    }
    temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void num_of_nodes()
{
    if (head==0)
    {
        printf("The list is empty.\n");
    }
    int count=0;
    temp=head;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }
    printf("%d\n",count);
}

void search()
{
    int n,i=-1;
    printf("Enter the value to search for:\n");
    scanf("%d",&n);
    temp=head;
    while(temp!=0)
    {
        i++;
        if (temp->data==n)
        {

            printf("The value is at index %d\n",i);
            break;
        }
        else
        {
            if (temp->next==0)
                printf("The entered value is not in the list.\n");
        }
        temp=temp->next;
    }

}

void insert()
{
    int n,val;
    printf("Enter the index at which u want to insert:\n");
    scanf("%d",&n);
    printf("Enter the value:\n");
    scanf("%d",&val);
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    temp=head;
    if (n==0)
    {
        newnode->next=head;
        head=newnode;
        newnode->data=val;

    }
    else
    {
            for (int i=0;i<n-1;i++)
            {

                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->data=val;
    }
}

void reverse()
{
    temp=head;
    while(temp!=0)
    {
        if (temp==head)
        {
            r=temp;
            temp=temp->next;
            head->next=0;
        }
        else
        {
            r1=r;
            r=temp;
            temp=temp->next;
            r->next=r1;
            if (temp==0)
            {
                head=r;
            }
        }
    }
}

void delete_()
{
    int n;
    printf("Enter the index which u want to delete:\n");
    scanf("%d",&n);
    temp=head;
    if (n==0)
    {
        head=temp->next;
    }
    else
    {
            for (int i=0;i<n-1;i++)
            {

                temp=temp->next;
            }
            temp->next=(temp->next)->next;
    }
}

void main()
{
    create();
    display();
    search();
    insert();
    display();
    num_of_nodes();
    reverse();
    display();
    delete_();
    display();

}
