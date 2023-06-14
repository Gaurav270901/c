#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right, *left;
} *root = NULL;
void create();
void insert(int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void main()
{
    int ch, no;
    while (1)
    {
        printf("\n\n1.create\n2.insert\n3.display\n4.exit\nenter your choice:\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:

            printf("enter the data to be inserted:\t");
            scanf("%d", &no);
            insert(no);
            break;
        case 3:
            if (root == NULL)
            {
                printf("tree is empty !!! insert values in tree\n");
                break;
            }
            int c;
            printf("\n\t1.Display by inorder\n\t2.display by pre-order\n\t3.display by post order\n\tenter your choice:\t");
            scanf("%d", &c);
            switch (c)
            {

            case 1:
                printf("\n\tIn-order:\t");
                inorder(root);
                break;
            case 2:
                printf("\n\tpre-order:\t");
                preorder(root);
                break;
            case 3:
                printf("\n\tpost-order:\t");
                postorder(root);
                break;
            }
            break;

        case 4:
            exit(0);

        default:
            printf("wrong choice\t:(\n");
        }
    }
}

void create()
{
    int no;
    printf("enter the number of nodes :\t");
    scanf("%d", &no);
    for (int i = 0; i < no; i++)
    {
        int n;
        printf("enter the data:\t");
        scanf("%d", &n);
        insert(n);
    }
}

void insert(int num)
{
    struct node *newnode, *temp, *prev;
    int no, flag;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = num;
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        temp = root;
        while (temp != NULL)
        {
            prev = temp;
            if (newnode->data < temp->data)
            {
                temp = temp->left;
                flag = 1;
            }
            else
            {
                temp = temp->right;
                flag = 2;
            }
        }

        if (flag == 1)
        {
            prev->left = newnode;
        }
        else
            prev->right = newnode;
    }
}
  


void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}



void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    inorder(root->left);
    inorder(root->right);
}



void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}