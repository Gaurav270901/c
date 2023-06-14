#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right, *left;
} *root = NULL;
void print_level_order();
int tree_height(struct node *);
void print_level(struct node *, int);

void create();

void main()
{
    create();
    print_level_order();
}

void create()
{
    struct node *newnode, *temp, *prev;
    int no, flag;
    printf("enter the number of nodes :\t");
    scanf("%d", &no);
    for (int i = 0; i < no; i++)
    {
        int n;
        printf("enter the data:\t");
        scanf("%d", &n);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->data = n;
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
}

void print_level_order()
{
    int i;
    if (root == NULL)
        return;
    int height = tree_height(root);
    printf("total levels in tree\t:%d\n", height);
    for (i = 0; i < height; i++)
    {
        printf("level %d :", i);
        print_level(root, i);
        printf("\n");
    }
    printf("complete level order traversal :\n");
    for (i = 0; i < height; i++)
    {
        print_level(root, i);
    }
}

void print_level(struct node *root, int level_no)
{
    if (root == NULL)
        return;
    if (level_no == 0)
    {
        printf("%d->", root->data);
    }

    else
    {
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }
}

int tree_height(struct node *root)
{
     int leftheight,rightheight;
    if (root == NULL)
        return 0;

    else
    {
        leftheight = tree_height(root->left);
        rightheight = tree_height(root->right);
    }

    if (leftheight >= rightheight)
        return leftheight + 1;

    else
        return rightheight + 1;
}