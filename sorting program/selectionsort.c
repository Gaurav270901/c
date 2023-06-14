#include<stdio.h>
int a[20],n;
void accept();
void display();
void selection_sort();
void main()
{
    accept();
    printf("\nunsorted array: ");
    display();
    selection_sort();
    printf("\nsorted array : \t");
    display();
}

void accept()
{
    int i;
    printf("enter the number of elements:\t");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("enter the value:\t");
        scanf("%d",&a[i]);
    }
}

void display()
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

void selection_sort()
{
    int min,i,j;
    for(i=0;i<=n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int t=a[min];
            a[min]=a[i];
            a[i]=t;


        }
    
    }

}