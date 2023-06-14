#include <stdio.h>
#define MAX 10
int a[MAX];
int size;
void accept();
int sentinelsearch(int);

void main()
{
    int i, n;
    accept();
    printf("enter the value to be searched:\t");
    scanf("%d", &n);
    i = sentinelsearch(n);
    if (i == -1)
        printf("\n not found");
    else
        printf("\nfound at loacion %d\t", i + 1);
}

void accept()
{
    int i;
    printf("how many terms:\t");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the values:\t");
        scanf("%d", &a[i]);
    }
}


int sentinelsearch(int key)
{
    int num;
    num = a[size - 1];
    a[size - 1] = key;
    int i = 0;
    while (a[i] != key)
    {
        i++;
    }
    a[size - 1] = num;
    if ((i < size - 1) || (key == a[size - 1]))
    {
        return i;
    }
    else
    {
        return -1;
    }
}