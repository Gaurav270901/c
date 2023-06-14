
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int n;
int adjM[20][20];
void display();
void accept();
void degree();
void adjacency_list();
void display_list();
struct node
{
  int data;
  struct node *next;
} * h[200], *temp, *ptr;
struct node *getnode(int j);
struct node *findlist(struct node *h);
void main()
{
  int ch;
  while (1)
  {
    printf("\n***menu**\n");
    printf("1.Accept\n");
    printf("2.degree\n");
    printf("3.display\n");
    printf("4.adjacency matrix\n");
    printf("5.display list\n");
    printf("6.exit\n");
    printf("enter your choice\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      accept();
      break;
    case 2:
      degree();
      break;
    case 3:
      display();
      break;
    case 4:
      adjacency_list();
      break;
    case 5:
      display_list();
      break;
    case 6:
      exit(1);
    default:
      printf("wrong choice\n");
    }
  }
}

void accept()
{
  int i, j;
  printf("enter the no of vertices:\t");
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      printf("\n is there is edge between %d and %d:\t", i, j);
      scanf("%d", &adjM[i][j]);
    }
  }
}

void display()
{
  int i, j;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      printf("\t%d", adjM[i][j]);
    }
    printf("\n");
  }
}

void degree()
{
  int i, j, indeg, outdeg, total;
  for (i = 1; i <= n; i++)
  {
    indeg = outdeg = total = 0;
    for (j = 1; j <= n; j++)

    {
      if (adjM[i][j] != 0)
        outdeg++;
      if (adjM[j][i] != 0)
        indeg++;
    }
    printf("\n vertex %d have outdegree=%d , indegree=%d,totaldegree=%d", i, outdeg, indeg, outdeg + indeg);
  }
}

struct node *getnode(int j)
{
  struct node *temp1;
  temp1 = (struct node *)malloc(sizeof(struct node));
  temp1->next = NULL;
  temp1->data = j;
  return (temp1);
}

struct node *findlast(struct node *h)
{
  struct node *temp1;
  temp1 = h;
  while (temp1->next != NULL)
    temp1 = temp1->next;
  return (temp1);
}

void display_list()
{
  int i;
  for (i = 1; i <= n; i++)
  {
    printf("\n");
    temp = h[i];
    while (temp != NULL)
    {
      printf("%d->", temp->data);
      temp = temp->next;
    }
  }
}

void adjacency_list()
{
  int i, j;
  for (i = 1; i <= n; i++)
  {
    h[i] = NULL;
    for (i = 1; i <= n; i++)
    {
      temp = getnode(i);
      h[i] = temp;
      for (j = 1; j <= n; j++)
      {
        if (adjM[i][j] == 1)
        {
          temp = getnode(j);
          ptr = findlast(h[i]);
          ptr->next = temp;
        }
      }
    }
    display_list();
  }
}
