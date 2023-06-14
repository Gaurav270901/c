#include <stdio.h>
#include <stdlib.h>
void init();
void pop();
void push();
int isempty();
int isfull();
void display();
#define MAX 5
int stack[MAX], top;
void main()
{
    int ch;
    init();
    while (1)
    {
        printf("\n1.push\n2.pop\n3.display\n4.isfull\n5.isNull\n6.EXIT\nEnter your choice:\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            if (isfull())
                printf("stack is full\n");
            else
                printf("stack is not full\n");
            break;
        case 5:
            if (isempty())
                printf("stack is empty\n");
            else
                printf("stack is not empty\n");
            break;

        case 6:
            exit(0);
        }
    }
}

void init()
{
    top = -1;
}

int isfull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push()
{
    int x;
    if (isfull())
    {
        printf("stack is FULL\n");
        return;
    }
    printf("Enter the data to be pushed:\t");
    scanf("%d", &x);
    top++;
    stack[top] = x;
}

void pop()
{
    int x;
    if (isempty())
    {
        printf("Stack is empty\n");
        return;
    }

    x = stack[top];
    top--;
    printf("deleted element is %d", x);
}

void display()
{
    if (isempty())
    {
        printf("Stack has no element\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}