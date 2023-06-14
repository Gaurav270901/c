
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define max 5
int a[max];
int front, rear;
int init();
void add_rear();
void display();
void add_front();
void del_front();
void del_rear();
void exit();

int main()
{
        int ch;
        while (1)
        {
                printf("\n1.init\n");
                printf("2.add_rear\n");
                printf("3.display\n");
                printf("4.add_front\n");
                printf("5.del_front\n");
                printf("6.del_rear\n");
                printf("7.exit\n");
                printf("enter your choice\n");
                scanf("%d", &ch);
                switch (ch)
                {

                case 1:
                        init();
                        break;
                case 2:
                        add_rear();
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        add_front();
                        break;
                case 5:
                        del_front();
                        break;
                case 6:
                        del_rear();
                        break;
                case 7:
                        exit(0);
                        break;
                }
        }
}

int init()
{
        front = -1;
        rear = -1;
}

void add_rear()
{
        int ele;
        if ((front == 0 && rear == max - 1) || (front == rear + 1))
        {
                printf("\nQ IS FULL\n");
                return;
        }

        if (front == -1)
        {
                front = 0;
                rear = 0;
        }

        else
        {
                if (rear == max - 1)
                {
                        rear = 0;
                        printf("rear is %d now", rear);
                }

                else
                {

                        rear = rear + 1;
                        printf("rear is %d now", rear);
                }
        }
        printf("\nEnter the element:\n");
        scanf("%d", &ele);
        printf("a[%d]=%d",rear,ele);
        a[rear] = ele;
}

void add_front()
{
        int ele;
        if ((front == 0 && rear == max - 1) || (front == rear + 1))
        {
                printf("\nQueue IS FULL\n");
                return;
        }

        if (front == -1)
        {
                front = 0;
                rear = 0;
        }

        else
        {
                if (front == 0)
                        front = max - 1;
                else
                        front = front - 1;
        }
        printf("\nEnter the element:");
        scanf("%d", &ele);
        a[front] = ele;
}

void del_front()
{
        if (front == -1)
        {
                printf("Queue IS UNDERFLOW\n");
                return;
        }
        printf("\ndeleted element is %d", a[front]);
        if (front == rear)
        {
                front = -1;
                rear = -1;
        }
        else
        {
                if (front == max - 1)
                        front = 0;
                else
                        front = front + 1;
        }
}

void del_rear()
{
        if (front == -1)
        {
                printf("Queue IS UNDERFLOW\n");
                return;
        }
        printf("\ndeleted ele is %d", a[rear]);
        if (front == rear)
        {
                front = -1;
                rear = -1;
        }
        else
        {
                if (rear == 0)
                        rear = max - 1;
                else
                        rear = rear - 1;
        }
}

void display()
{
        int front_pos = front, rear_pos = rear;
        if (front == -1)
        {
                printf(" \n queue is empty");
                return;
        }
        printf("\n queue element :\n");
        if (front_pos <= rear_pos)
        {
                while (front_pos <= rear_pos)
                {
                        printf("%d\n", a[front_pos]);
                        front_pos++;
                }
        }
        else
        {
                while (front_pos <= max - 1)
                {
                        printf("%d\n", a[front_pos]);
                        front_pos++;
                }
                front_pos = 0;
                while (front_pos <= rear_pos)
                {
                        printf("%d\n", a[front_pos]);
                        front_pos++;
                }
                printf("\n");
        }
}