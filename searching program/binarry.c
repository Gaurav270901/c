#include <stdio.h>
#define MAX 10
int a[MAX];
int size;
void accept();
void search(int, int);
void main()
{
    accept();
    search(0, size);
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

void search(int low, int high)
{
    int x, i, mid;
    printf("\n enter the element to be searched:\t");
    scanf("%d", &x);
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (x == a[mid])
        {
            printf("\n element found at \t %d ", mid + 1);
            return;
        }
        else if (x < a[mid])
        {
            high = mid - 1;
        }
        else if (x > a[mid])
        {
            low = mid + 1;
        }
    }
    printf("\nelement not found");
}