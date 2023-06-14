#include<stdio.h>
void selectsong(int);
void main()
{
    int time;
    printf("enter the time duration:\t");
    scanf("%d",&time);
    selectsong(time);
}


void selectsong(int time)
{
    int i,j;
    int arr[10]={5,10,15,20,25,30,40,50,60,70};
    for(int k=0;k<10;k++)
    {
        printf("song %d (%d sec)\n",k+1,arr[k]);
    }


    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(time-(arr[i]+arr[j])==30)
            {
                if(i!=j)
                {
                    printf("song selected :\n song %d(%d sec) and song %d(%d sec)",i+1,arr[i],j+1,arr[j]);
                    return;
                }
            }
        }
    }
    printf("no songs found :(");
    return;


}