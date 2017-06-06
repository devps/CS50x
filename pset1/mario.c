/*  
     @author: Devendra Singh   @date :  June 2, 2017 
*/
     
#include <stdio.h>
#include<cs50.h>

int main(void)
{
     int Height;
    do {
   
    printf("Height :");
   Height=get_int();
    } while (Height <0 || Height >23);
 
  
  int K=1;
   int back=1;
  int H=Height-1;
  
    for(int i=0;i<Height;i++)
    {
     int J=1;
      while(J<=H)
      {
          printf(" ");
          J++;
      }
      H--;
      int k=1;
     
      while(k<=K)
      
      {
          printf("#");
          k++;
      }
      K++;
      
     printf("  ");
     
      for(int p=0;p<back;p++)
      {
        printf("#");
        
      } 
      back++;
      
      
      
      printf("\n");
      
      
      
      
      
      
      
    }
    return 0;
   
  
    
}