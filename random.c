#include<stdio.h>
#include<math.h>

int main()
{
  int n;
  float sum = 0 , x ;
  printf("Enter the number of terms :\t");
  scanf("%d",&n);

  printf("Enter the value of x :\t");
  scanf("%f",&x);
  int j =1;
  for(int i = 0 ; i < n ; i++)
  {
    
    float p = pow(x,j);
    if(i % 2 == 0)
    {
      sum = sum + (p/j);
      j = j + 2;
    }
    else
    {
      sum = sum - (p/j);
      j = j + 2;
    }
  }
printf("Sum of the series is %f",sum);
}