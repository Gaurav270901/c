#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right, *left;
} *root = NULL;
void create();
void insert(int);
void search();
void delete ();
int count(struct node *);
int countleaf(struct node *);
int countnonleaf(struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void main()
{
    int ch, no;
    while (1)
    {
        printf("\n1.create\n2.insert\n3.search\n4.inorder\n5.preorder\n6.postorder\n7.count nodes\n8.count leaf\n9.count non leaf\n10.delete \n11.exit\nenter your choice:\t");
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
            search();
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            preorder(root);
            break;
        case 6:
            postorder(root);
            break;
        case 7:
            printf("\ntotal number of nodes are %d\n", count(root));
            break;
        case 8:
            printf("\ntotal number of leaf are %d\n", countleaf(root));
            break;
        case 9:
            printf("\ntotal number of non leaf are %d\n", countnonleaf(root));
            break;
        case 10:
            delete ();
            break;
        case 11:
            exit(0);
        }
    }
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

void search()
{
    struct node *temp;
    int no;
    if (root == NULL)
    {
        printf("tree is empty !!! insert values in tree\n");
        return;
    }
    printf("enter the data to be searched:\t");
    scanf("%d", &no);     
    temp = root;
    while (temp != NULL)
    {
        if (temp->data == no)
        {
            printf("\n%d found\n", no);
            return;
        }
        else if (no < temp->data)
        {   
            if(temp->left==NULL)
            {
                printf("data not found\n");
                return;
            }
            temp = temp->left;
            if (temp->data == no)
            {
                printf("\n%d found\n", no);
                return;
            }
        }

        else
        {
            if(temp->right==NULL)
            {
                printf("data not found\n");
                return;
            }
            temp = temp->right;

            if (temp->data == no)
            {
                printf("\n%d found\n", no);
                return;
            }
        }
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



int count(struct node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + count(root->left) + count(root->right));
}



int countleaf(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return (1 + countleaf(root->left) + countleaf(root->right));
    else
        return (countleaf(root->left) + countleaf(root->right));
}



int countnonleaf(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL || root->right != NULL)
        return (1 + countnonleaf(root->left) + countnonleaf(root->right));
    else
        return (countnonleaf(root->left) + countnonleaf(root->right));
}



void delete ()
{
    if (root == NULL)
    {
        printf("tree is empty !!! insert values in tree\n");
        return;
    }
    struct node *temp, *prev;
    int x, flag = 0;
    printf("enter the data to be deleted:\t");
    scanf("%d", &x);
    temp = root;
    while (temp != NULL)
    {

        if (temp->data == x)
        {
            prev = temp;
            break;
        }
        else if (x < temp->data)
        {
            if(temp->left==NULL)
            {
                printf("\ndata not found\n");
                return;
            }
            prev = temp;
            temp = temp->left;
            if (temp->data == x)
            {
                break;
            }
        }

        else
        {
            if(temp->right==NULL)
            {
                printf("\ndata not found\n");
                return;
            }
            prev = temp;
            temp = temp->right;
            if (temp->data == x)
            {
                break;
            }

        }
    }

    if(temp==root)
    {
        if(temp->right==NULL && temp->left==NULL)
        {
            free(temp);
            printf("root node is deleted !!\ttree is empty now\n");
            return;
        }

        if(temp->right==NULL && temp->left !=NULL )
        {
            root=root->left;
            root->right=NULL;
            printf("root node is deleted !!\t new root is %d\n",root->data);
            free(temp);
            return;
            
        }

        
        if(temp->right!=NULL && temp->left ==NULL )
        {
            root=root->right;
            root->left=NULL;
            printf("root node is deleted !!\t new root is %d\n",root->data);
            free(temp);
            return;
            
        }

        
        if(temp->right!=NULL && temp->left !=NULL )
        {
            root=root->left;
            root->right=temp->right;
            printf("root node is deleted !!\t new root is %d\n",root->data);
            free(temp);
            return;
            
        }
    }


    if (temp->left == NULL && temp->right == NULL)
    {
        if (temp->data < prev->data)
        {
            prev->left = NULL;
            free(temp);
            return;
        }
        else
        {
            prev->right = NULL;
            free(temp);
            return;
        }
    }

    if (temp->left == NULL && temp->right != NULL)
    {
        if (temp->data > prev->data)
        {
            prev->right = temp->right;
            free(temp);
            return;
        }

        else
        {
            prev->left = temp->right;
            free(temp);
            return;
        }
    }

    if (temp->left != NULL && temp->right == NULL)
    {
        if (temp->data > prev->data)
        {
            prev->right = temp->left;
            free(temp);
            return;
        }

        else
        {
            prev->left = temp->left;
            free(temp);
            return;
        }
    }

    if (temp->left != NULL && temp->right != NULL)
    {
        if (temp->data > prev->data)
        {
            prev->right = temp->left;
            free(temp);
            return;
        }

        else
        {
            prev->left = temp->left;
            free(temp);
            return;
        }
    }
}
