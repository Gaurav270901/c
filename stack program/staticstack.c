
#include<stdio.h>
#include<stdlib.h>
#include "ststack.h"
void main()
{
  int ch,x;
  init();
  while(1)
  {
    printf("\n 1.Push");
    printf("\n 2.Pop");
    printf("\n 3.Display");
    printf("\n 4.peek");
    printf("\n 5.exit\n");
    scanf("%d",&ch);    
    switch(ch)
    {
      case 1: push();
              break;
      case 2: pop();
              break;
      case 3: display();
              break;
      case 4: peek();
              break;      
      case 5: exit(0);
    }                            
  }
}
