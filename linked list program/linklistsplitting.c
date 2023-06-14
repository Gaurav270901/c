#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *link;
}*head=NULL;
void display(struct node*);
void main()
{
 int num,i,j,n;
 struct node *temp,*next,*head1,*prev;
 printf("how many nodes you want to create:\t");
 scanf("%d",&n);
 for(i=0;i<n;i++)
{
 temp=(struct node*)malloc(sizeof(struct node));
 temp->link=NULL;
 printf("enter the value for node:");
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
 printf("linked list is :\n");
 display(head);
 printf("\nlinked list after splitting is :\n");
 head1=head;
 n=n/2;
 int pos=0;
 for(pos=1;pos<=n;pos++)
{
 prev=head1;
 head1=head1->link;
}
 prev->link=NULL;
 display(head);
 printf("\n");
 display(head1);
}
void display(struct node *next)
{
 while(next!=NULL)
{
 printf("%d\t",next->data);
 next=next->link;
}

}