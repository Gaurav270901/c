  #include<stdio.h>
int a[20],n;
void accept();
void display();
void insertion_sort();
void main()
{
    accept();
    printf("\nunsorted array: ");
    display();
    insertion_sort();
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

void insertion_sort()
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        k=a[i];
        for(j=i-1;j>=0 && k<a[j];j--)
            a[j+1]=a[j];
        a[j+1]=k;    
    }
}