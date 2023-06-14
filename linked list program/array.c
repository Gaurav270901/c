#include<stdio.h>
int arr[20],n;
void accept();
void display();
void repeat(int);
void main()
{
   accept();
   display();
   for(int i=0;i<n;i++)
    repeat(i);

}


void accept()
{
    printf("number of elements:\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the number:\t");
        scanf("%d",&arr[i]);
    }

}


void display()
{
    printf("array is :");
     for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

}


void repeat(int pos)
{
    int cnt=0;
    if(pos==0)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[pos]==arr[i])
                cnt++;
        }
        printf("\n%d is repeated %d times",arr[pos],cnt);
        return;
    }
    else
    {
        for(int i=0;i<pos;i++)
        {
            if(arr[pos]==arr[i])
                return;
        }
        for(int i=pos;i<n;i++)
        {
            if(arr[pos]==arr[i])
                cnt++;
        }
        printf("\n%d is repeated %d times",arr[pos],cnt);
    }
}