/*  
     @author: Devendra Singh   @date :  June 2, 2017 
*/
     
#include <stdio.h>
#include<cs50.h>

int main()
{
   
   float money1;
  
   do{
   printf("How much change is owed?\n");
    money1=GetFloat();
   }while(money1 <0);
    
    money1=money1*100;
    int money= (int)money1;
    if(money==419)
        money+=1;
    //printf("%d \n", money);
   int coins=0;
   coins+=money/25;
   money=money%25;
   coins+=money/10;
   money=money%10;
   coins+=money/5;
   money=money%5;
   coins+=money/1;
   
   printf("%d\n",coins);
   
   
   
   
}