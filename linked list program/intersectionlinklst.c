#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
}*head1=NULL,*head2=NULL;
struct node *create(struct node *);
void display(struct node*);
struct node *ncommon(struct node*,struct node*);

void main()
{
struct node *head3;
printf("enter 1st linked list:\n");
head1=create(head1);
printf("enter 2nd linked list:\n");
head2=create(head2);
printf("1st linked list is \n");
display(head1);
printf("\n2nd linked list is \n");
display(head2);
printf("\n common elements in linklist are:\n");
head3=ncommon(head1,head2);
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
struct node *ncommon(struct node *head1,struct node *head2)
{
struct node *head=NULL,*next=NULL,*temp,*next1,*next2;
 
while(head1!=NULL)
{
next2=head2;
while(next2!=NULL)
{
if(next2->data==head1->data)
{
temp=(struct node*)malloc(sizeof(struct node));
temp->link=NULL;
temp->data=next2->data;
if(head==NULL)
head=temp;
else
{
next=head;
while(next->link!=NULL)
next=next->link;
next->link=temp;  
}
}
next2=next2->link;
 
}
head1=head1->link;

}  
 
return head;
}

struct node *create(struct node *head)
{
int num,i,j,n;
struct node *temp,*next;
printf("how many nodes you want to create :\t");
scanf("%d",&n);
for(i=0;i<n;i++)
{
temp=(struct node*)malloc(sizeof(struct node));
temp->link=NULL;
printf("enter the value of node:");
scanf("%d",&num);
temp->data=num;
if(head==NULL)
head=temp;
else
{
next=head;
while(next->link!=NULL)
next=next->link;
next->link=temp;  
}
}
return head;
}