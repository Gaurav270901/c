#include <stdio.h>
#define MAX 10
int arr[MAX];
int size;
void accept();
void search(int);
void SentinalSearch(int[], int);
void main()
{
    int no;
    accept();
    printf("enter the value to be searched:\t");
    scanf("%d", &no);
    SentinalSearch(arr, no);
}

void accept()
{
    int i;
    printf("how many terms:\t");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the values:\t");
        scanf("%d", &arr[i]);
    }
}

void SentinalSearch(int array[], int num)
{
    int last = array[size - 1];
    array[size - 1] = num;
    // Here num is the search element.
    int i = 0;
    while (array[i] != num)
    {
        i++;
    }
    array[size - 1] = last;
    if ((i < size - 1) || (num == array[size - 1]))
    {
        printf(" %d found at %d ", num, i + 1);
    }
    else
    {
        printf(" element not found");
    }
}