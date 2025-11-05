#include<stdio.h>
int main ()
{
    int array[10],i,j;
    for(i=0;i<5;i++)
    {
        printf("enter your arrray ki value -: ..");
        scanf("%d",array);

    }
    for (i = 0; i < 5; i++)
    {
  
        if(array[i]>array[i+1])
        {
            array[i]=array[i+1];
            
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d",array[i]);
    }

}