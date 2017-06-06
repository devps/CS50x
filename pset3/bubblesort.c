/*  
     @author: Devendra Singh   @date :  June 4, 2017 
*/
// bubble sort
#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
void bubblesort(int values[], int n )
{
    
     int swap=0;
     for(int i=0;i<n-1;i++)
     {
         swap=0;
         for(int j=0;j<n-i-1;j++)
         {
             if(values[j]>values[j+1])
             {
                
                int temp=values[j];
                values[j]=values[j+1];
                values[j+1]=temp;
                swap++;
             }
         }
         if(swap==0)
           return;
     }
  return;
    
    
}
int main()
{
    int n=get_int();
    int values[100];
    for(int i=0;i<n;i++)
        values[i]=get_int();
        
        
    bubblesort(values,n);
    
    printf("Sorted number:\n");
    for(int i=0;i<n;i++)
       printf("%d ",values[i]);
     printf("\n");
    return 0;
}

