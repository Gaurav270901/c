#include <stdio.h>
#include <stdlib.h>
int vert, edge, i, j;
struct node
{
    int data;
    struct node *link;
} * h[100], *ptr, *temp;
void create_adl();
void degree();
int indegree(int);
int outdegree(struct node *);
void create();
struct node *findlast(struct node*);
void display();
struct node *getnode(int);
void main()
{
    int ch;
    while (1)
    {
        printf("1.Accept\n");
        printf("2.degree\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter your choice:\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_adl();
            break;
        case 2:
            degree();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        }
    }
}

void create_adl()
{
    int num, vi, vj, i, j;
    printf("enter the number of vertices:\t");
    scanf("%d", &vert);
    printf("enter the number of edges:\t");
    scanf("%d", &edge);
    for (i = 0; i < vert; i++)
    {
        h[i] = NULL;
    }
    for (i = 0; i < edge; i++)
    {
        printf("Enter the vertices vi and vj or edge E%d:\t", i + 1);
        scanf("%d %d", &vi, &vj);
        temp = getnode(vj);
        if (h[vi] == NULL)
        {
            h[vi] = temp;
        }

        else
        {
            ptr = findlast(h[vi]);
            ptr->link = temp;
        }
    }
}

struct node *getnode(int j)
{
    struct node *temp1;
    temp1 = (struct node *)malloc(sizeof(struct node));
    temp1->link = NULL;
    temp1->data = j;
    return (temp1);
}

void display()
{
    for (i = 0; i < vert; i++)
    {
        ptr = h[i];
        printf("\nV%d:\t", i);
        while (ptr != NULL)
        {
            printf("V%d-->", ptr->data);
            ptr = ptr->link;
        }
        printf("NL");
    }
    printf("\n");
}

void degree()
{
    int in, out, i, total;
    for (i = 0; i < vert; i++)
    {
        out = outdegree(h[i]);
        in = indegree(i);
        printf("\n for vertex %d :\n indegree:\t%d\t\toutdegree:%d\t\tTotal:\t%d\n", i, in, out, in + out);
    }
}

int outdegree(struct node *h)
{
    struct node *q;
    int cnt = 0;
    q = h;
    while (q != NULL)
    {
        q = q->link;
        cnt++;
    }

    return cnt;
}

int indegree(int num)
{
    struct node *q;
    int cnt = 0;
    for (i = 0; i < vert; i++)
    {
        q=h[i];
        while (q != NULL)
        {
            if(q->data==num)
            cnt++;
            q = q->link;
        }
    }

    return cnt;
}


struct node *findlast(struct node *h)
{
 struct node *temp1;
 temp1=h;
 while(temp1->link!=NULL)
 temp1=temp1->link;
 return(temp1);
}