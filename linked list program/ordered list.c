#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
  int data;
  struct node *link;
}*head=NULL;
void Display();
void Insert();
void Delete();
int main()
{
  int ch;
  while(1)
  {
    printf("\n 1.Insert");
    printf("\n 2.Display");
    printf("\n 3.Delete");
    printf("\n 4.Exit");
    printf("\n Enter your choice:\t");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:Insert();
              break;
      case 2:Display();
              break;
      case 3:Delete();
              break;
      case 4:exit(0);
      }
  }
}
void Insert()
{
  int num;
  struct node *temp,*next;
  temp=(struct node *)malloc(sizeof(struct node));
  printf("\n Enter value from user:");
  scanf("%d",&num);
  temp->data=num;
  if(head==NULL || num<head->data)
  {
    temp->link=head;
    head=temp;
    return;
  }
  else
  {
    next=head;
    while(next->link!=NULL && next->link<temp)
    next=next->link;
    temp->link=next->link;
    next->link=temp;
  }
}
void Display()
{
  struct node *next;
  next=head;
  while(next!=NULL)
  {
    printf("%d\t",next->data);
    next=next->link;
  }
}
void Delete()
{
  struct node *temp,*next;
  int pos,i;
  printf("\n Enter the position of node to be delete:\t");
  scanf("%d",&pos);
  if(head==NULL)
  {
    printf("\n link list is empty");
    return;
  }
  if(pos==1)
  {
    temp=head;
    head=head->link;
    free(temp);
  }
  else{
    next=head;
    for(i=0;i<pos-1;i++)
    next=next->link;
    temp=next->link;
    next->link=temp->link;
    temp->link=NULL;
    free(temp);
  }
}