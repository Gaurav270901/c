#include <stdio.h>
int a[20], n,max=0;
void accept();
void display();
void count_sort();
void main()
{
    accept();
    printf("\nunsorted array: ");
    display();
    count_sort();
}

void accept()
{
    int i;
    printf("enter the number of elements:\t");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("enter the value:\t");
        scanf("%d", &a[i]);
        if(a[i]>max)
            max=a[i];
    }
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void count_sort()
{
    int count[100] = {0};
    int i, j;
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    printf("sorted array is\n");
    for (i = 0; i <= max; i++)
    {
        for (j = 1; j <= count[i]; j++)
        {
            printf("%d\t", i);
        }
    }
}