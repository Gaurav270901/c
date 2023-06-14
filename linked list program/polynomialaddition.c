#include<stdio.h>
#include<stdlib.h>
struct node
{
  int coe,expo;
  struct node *link;
};
struct node *enter(struct node*);
struct node *insert(struct node*,int,int);
void display(struct node *);
struct node *poly_add(struct node*,struct node*);
void main()
{
  struct node *p1_head,*p2_head,*p3_head;
  p1_head=NULL;
  p2_head=NULL;
  p3_head=NULL;
  printf("\n Enter 1st polynomial:");
  p1_head=enter(p1_head);
  printf("\n Enter 2nd polynomial:");
  p2_head=enter(p2_head);
  printf("\n polynomials is:\n");
  display(p1_head);
  printf("\n ");
  display(p2_head);
  p3_head=poly_add(p1_head,p2_head);
  printf("\n Addition of polynomial is :\n");
  display(p3_head);
}
 struct node *enter(struct node *p_head)
 {
   int i,n,co,ex;
 printf("\n Enter how many terms:");
 scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    printf("\n Enter co & ex:\t");
    scanf("%d%d",&co,&ex);
    p_head=insert(p_head,co,ex);
  }
  return p_head;
}
 struct node *insert(struct node *p_head,int co,int ex)
 {
  struct node *temp,*next;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->link=NULL;
  temp->coe=co;
  temp->expo=ex;
  if(p_head==NULL)
  {
    p_head=temp;
  }
  else
  {
    next=p_head;
    while(next->link!=NULL)
    next=next->link;
    next->link=temp;
  }
  return p_head;
}
void display(struct node *p_head)
{
  struct node *next;
  next=p_head;
  while(next!=NULL)
  {
    printf("%dx^%d+",next->coe,next->expo);
    next=next->link;
  }
}
  struct node *poly_add(struct node *p1,struct node *p2)
  {
  struct node *p3_head,*p3,*temp;
  while(p1!=NULL && p2!=NULL)
  {
    temp=(struct node*)malloc(sizeof(struct node));
    if(p3_head==NULL)
    {
      p3_head=temp;
      p3=p3_head;
    }
    else
    {
      p3->link=temp;
      p3=p3->link;
    }
    if(p1->expo>p2->expo)
    {
      p3->coe=p1->coe;
      p3->expo=p1->expo;
      p1=p1->link;
    }
    if(p2->expo>p1->expo)
    {
      p3->coe=p2->coe;
      p3->expo=p2->expo;
      p2=p2->link;
    }
    if(p1->expo==p2->expo)
    {
      p3->coe=p1->coe+p2->coe;
      p3->expo=p1->expo;
      p1=p1->link;
      p2=p2->link;
    }
  }
  while(p1!=NULL)
  {
   temp=(struct node*)malloc(sizeof(struct node));
   if(p3_head==NULL)
   {
     p3_head=temp;
     p3=p3_head;
    }
   else
   {
     p3->link=temp;
     p3=temp;
   }
   p3->coe=p1->coe;
   p3->expo=p1->expo;
   p1=p1->link;
  }
  while(p2!=NULL)
  {
    temp=(struct node*)malloc(sizeof(struct node));
    if(p3_head==NULL)
    {
      p3_head=temp;
      p3=p3_head;
    }
    else
    {
      p3->link=temp;
      p3=p3->link;
    }
    p3->coe=p2->coe;
    p3->expo=p2->expo;
    p2=p2->link;
  }
 p3->link=NULL;
 return p3_head;
}