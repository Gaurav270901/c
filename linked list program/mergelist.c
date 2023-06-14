#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head1=NULL,*head2=NULL;
struct node *create(struct node*);
void display(struct node*);
struct node *insert(struct node*);
struct node *merge(struct node *,struct node *);
void main()
{
    struct node *head3;
    printf("\n Enter 1st linked list:");
    head1=create(head1);
    printf("\n Enter 2nd linked list:");
    head2=create(head2);
    printf("\n 1st linked list is :\n");
    display(head1);
    printf("\n 2nd linked list is: \n");
    display(head2);
    head3=merge(head1,head2);
    printf("\nLinked list after merging is\n");
    display(head3);

}
void display(struct node *head)
{
    struct node *next;
    next=head;
    while(next!=NULL)
    {
        printf("%d\t",next->data);
        next=next->link;
    }

}
struct node *create(struct node *head)
{
    int num,i,n;
    struct node *temp,*next;
    printf("\n How many nodes you want to create:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        head=insert(head);
     
     
    }
    return head;
}
struct node *merge(struct node *l1,struct node *l2)
{
    struct node *l3=NULL,*q,*temp;
    if(l1==NULL && l2==NULL)
    return NULL;
    if (l1==NULL)
    return l2;
    if(l2==NULL)
    return l1;
    while(l1!=NULL && l2!=NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->link=NULL;
        if(l1->data < l2->data)
        {
            temp->data=l1->data;
            l1=l1->link;
        }
        else
        {
            temp->data=l2->data;
            l2=l2->link;
        }
        if(l3==NULL)
        {
            l3=temp;
        }
        else
        {
            q=l3;
            while(q->link!=NULL)
            {
                q=q->link;
            }
            q->link=temp;
        }
       
    }
    if(l1==NULL)
    {
        while(l2!=NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->link=NULL;
            temp->data=l2->data;
            q=l3;
       
            while(q->link!=NULL)
                q=q->link;
            q->link=temp;
            l2=l2->link;    

        }
   
    }
     if(l2==NULL)
    {
        while(l1!=NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->link=NULL;
            temp->data=l1->data;
            while(q->link!=NULL)
                q=q->link;
            q->link=temp;
            l1=l1->link;    

        }
    }
    return l3;

}
struct node *insert(struct node *head)
{
    struct node *temp,*next;
    int num;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
        printf("\nEnter the value from user:\t");
        scanf("%d",&num);
        temp->data=num;
        if(head==NULL || num<head->data)
        {
            temp->link=head;
            head=temp;
            return head;
        }
        else
        {
            next=head;
            while(next->link!=NULL && next->link->data<num)
                next=next->link;
            temp->link=next->link;
            next->link=temp;  
        }    
        return head;
}