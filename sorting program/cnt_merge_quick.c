#include<stdio.h>
void count();
void merge_sort(int,int);
void quick_sort(int,int);
void merge(int ,int,int);
void display();
void accept();
int partition(int ,int);
#define MAX 20
int n;
int a[MAX];
void main()
{
    int ch;
    accept();
    do
    {
        printf("\n1.counting sort\n2.merge sort\n3.quick sort\nenter your choice:\t");
        scanf("%d",&ch);
        printf("array before sorting:\t");
        display();
        switch(ch)
        {
            case 1:count();break;

            case 2:merge_sort(0,n-1);
            printf("\narray after sorting by merge sort is :\t");
            display();break;

            case 3:quick_sort(0,n-1);
                    printf("\narray after sorting by quick sort is :\t");
                    display();break;
        }
    

    }while(ch<=1 && ch>=3);


    

   
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



void merge_sort(int low,int high)
{
    int mid;
    if(low!=high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}


void merge(int low,int mid,int high)
{
int i,k,j,temp[20];
i=low;
j=mid+1;
k=low;
while((i<=mid) && (j<=high))
{
if (a[i]>=a[j])
temp[k++]=a[j++];
else
temp[k++]=a[i++];
}
while(i<=mid)
temp[k++]=a[i++];
while(j<=high)
temp[k++]=a[j++];
for(i=low;i<=high;i++)
a[i]=temp[i];
}





void quick_sort(int low,int high)
{
    int p;
    if(low<high)
    {
        p=partition(low,high);
        quick_sort(low,p-1);
        quick_sort(p+1,high);
    }
     
    
}


int partition(int low,int high)
{
    int i,j,temp,pivot;
    i=low-1;
    pivot=a[high];
    for(j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
        a[i+1]=a[high];
        a[high]=temp;

    return i+1;
}



void count()
{
    int count[20]={0};
 int i,j;
for(i=0;i<n;i++)
{
 count[a[i]]=count[a[i]]+1;
}
printf("\nsorted array using count sort is:");
for(i=0;i<=n;i++)
 {
  for(j=1;j<=count[i];j++)
    { printf("%d\t",i);
      }
   }
}